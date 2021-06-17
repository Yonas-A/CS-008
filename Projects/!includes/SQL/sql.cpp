
#include "../../!includes/SQL/sql.h"

#include <stdio.h>
#include <string.h>

#include <cstring>
#include <iomanip>
#include <iostream>
#include <istream>

#include "../../!includes/Enums/enumerations.h"
#include "../../!includes/Map/BPlus_Tree/multimap.h"
#include "../../!includes/Parser/parser.h"

const std::string SQL::STARTUP_FILE("startup.txt");
const std::string SQL::BATCH_FILE("_!select-1.txt");
const int COMMAND_LENGTH = 200;

using namespace std;

// =============================================================
// ctor

SQL::SQL() : _parser(), _sql_table(), _fail(false) {
    cout << "--------------  SQL Tables I Manage: -------------- " << endl;
    build_sql_table();
    cout << "\n--------------------------------------------------" << endl;
}

SQL::~SQL() {
    _sql_table.clear();
}

// =============================================================

void SQL::batch() {
    cout << "=  =   =   =   =  BATCH TEST  =  =   =   =   =\n\n";

    ifstream fin;
    fin.open(BATCH_FILE);

    if (fin.fail()) {
        cout << BATCH_FILE << " opening failed" << endl
             << endl;
        exit(1);
    }

    int count = 0;

    char command_line[COMMAND_LENGTH + 1];
    fin.getline(command_line, COMMAND_LENGTH, '\n');

    while (!fin.eof()) {
        if (strcmp(command_line, "\0") != 0 && command_line[0] != '/') {
            /// filter out comments in the file do not parse them
            cout << "[" << count++ << "]  " << command_line << endl;
            parse_command(command_line);
        } else
            cout << command_line << endl
                 << endl;

        /// get the next command on the next line
        fin.getline(command_line, COMMAND_LENGTH, '\n');
    }

    clear_debug_folder();
    cout << "=  =   =   =   =  END BATCH TEST  =  =   =   =   =\n\n";
}

void SQL::console() {
    const int MAXIMUM = 200;
    char command_line[MAXIMUM + 1];

    cout.write(">   ", 4);
    cin.getline(command_line, MAXIMUM, '\n');

    while (strcmp(command_line, "exit") != 0 &&
           strcmp(command_line, "quit") != 0) {
        if (strcmp(command_line, "\0") != 0) {
            _sql_command = command_line;
            parse_command(command_line);
        }

        cout.write(">   ", 4);
        cin.getline(command_line, MAXIMUM, '\n');
    }
}

void SQL::run(bool state) {
    /// from cosole
    if (state == true)
        console();
    /// from file
    else
        batch();
}

// =============================================================
// Table/Database modifiers

void SQL::parse_command(char cmd[]) {
    _parser.set_string(cmd);

    // if current parsed command is valid
    if (_parser.is_valid()) {
        /// get a multimap of parsed command
        MMap<string, string> ptree = _parser.get_parse_tree();

        if (ptree["command"].front() == "create") {
            /// \note make and create functions are controlled by the
            /// the table ctor with 2 arguments
            if (create(ptree))
                cout << success::create << endl;
            else
                cout << error::create << endl;
        }

        else if (ptree["command"].front() == "delete") {
            if (delete_table(ptree))
                cout << success::_delete << endl;
            else
                cout << error::_delete << endl;

        }

        else if (ptree["command"].front() == "drop") {
            if (drop(ptree))
                cout << success::drop << endl;
            else
                cout << error::drop << endl;
        }

        else if (ptree["command"].front() == "insert") {
            if (insert(ptree))
                cout << success::insert << endl;
            else
                cout << error::insert << endl;
        }

        else if (ptree["command"].front() == "make") {
            if (make(ptree))
                cout << success::make << endl;
            else
                cout << error::make << endl;
        }

        else if (ptree["command"].front() == "select") {
            if (select(ptree))
                cout << success::select << endl;
            else
                cout << error::select << endl;
        }

    } else {
        cout << error::_default;
    }
}

bool SQL::create(MMap<string, string> &ptree) {
    string table_name = ptree["table"].front();

    if (_sql_table.contains(table_name)) {
        /// if a table with the same name exists, exit and return false
        return false;
    }

    vector<string> fields = ptree["fields"];
    /// get fields for the new table
    Table t(table_name, fields);
    /// create new table with name and fields
    update_sql_table(table_name, t);

    return true;
}

bool SQL::delete_table(MMap<string, string> &ptree) {
    string table_name = ptree["table"].front();

    if (!_sql_table.contains(table_name)) {
        /// if a no table exists with this name, exit and return false
        return false;
    }

    Table t(table_name);

    /// \attention if delete command doesn't have conditions, it acts like
    /// drop table where we are forced to delete the entire database
    if (ptree.contains("conditions")) {
        t.delete_where(ptree["conditions"]);
    } else {
        t.drop();
    }

    ///\todo
    ///  delete table in Table:: clase

    return true;
}

bool SQL::drop(MMap<string, string> &ptree) {
    string table_name = ptree["table"].front();

    if (!_sql_table.contains(table_name))
        /// if a no table exists with this name, exit and return false
        return false;

    Table t(table_name);
    remove_sql_table(table_name);
    /// remove table name from file and erase it from _sql_table map

    t.drop();
    /// deletes associated file

    return true;
}

bool SQL::insert(MMap<string, string> &ptree) {
    string table_name = ptree["table"].front();

    /// if a no table exists with this name, exit and return false
    if (!_sql_table.contains(table_name)) {
        return false;
    }

    Table t(table_name);

    t.insert_into(ptree["fields"]);

    return true;
}

bool SQL::make(MMap<string, string> &ptree) {
    string table_name = ptree["table"].front();

    /// if a table with the same name exists, exit and return false
    if (_sql_table.contains(table_name)) {
        return false;
    }

    vector<string> fields = ptree["fields"];
    /// get fields for the new table
    Table t(table_name, fields);
    /// create new table with name and fields
    update_sql_table(table_name, t);

    return true;
}

bool SQL::select(MMap<string, string> &ptree) {
    string table_name = ptree["table"].front();

    if (!_sql_table.contains(table_name)) {
        /// if a table name does not exist, exit and return false
        return false;
    }

    Table t(table_name);

    if (ptree["fields"].front() == "*") {
        if (ptree.contains("conditions")) {
            Table temp = t.select_all(ptree.get("conditions"));
            cout << temp << endl;
            update_sql_table(temp.get_tablename(), temp);
        }

        else {
            Table temp = t.select_all();
            cout << temp << endl;
            update_sql_table(temp.get_tablename(), temp);
        }
    }

    else {
        if (ptree.contains("conditions")) {
            Table temp = t.select_where(ptree["fields"], ptree["conditions"]);
            cout << temp << endl;

            /// only update table if table is not in an error state
            if (temp.get_error() != true)
                update_sql_table(temp.get_tablename(), temp);
            /** \note
              * if error is true, then input command included fields
              *  the table from which temp was being created did not contain
              *  so temp is in error state
              */
        }

        else {
            Table temp = t.select(ptree["fields"]);
            cout << temp << endl;
            if (temp.get_error() != true)
                update_sql_table(temp.get_tablename(), temp);
        }
    }

    return true;
}

// =============================================================
// private initializer

void SQL::build_sql_table() {
    // open a table object with each line and insert
    ifstream f;
    f.open(STARTUP_FILE);

    if (f.fail()) {
        cout << "opening " << STARTUP_FILE << " failed" << endl
             << endl;
        exit(-2);
    }

    char table_names[COMMAND_LENGTH + 1];
    /// holds a single line of characters
    f.getline(table_names, COMMAND_LENGTH, '\n');
    /// get a line from _start.txt file
    while (!f.eof()) {
        Table t(table_names);
        /// open a table object with each line of text and insert
        ///  table and name from file onto _sql_table map
        _sql_table[table_names] = t;
        cout << table_names << endl;
        f.getline(table_names, COMMAND_LENGTH, '\n');
    }

    f.close();
}

// =============================================================
// private accessor

bool SQL::is_valid() const {
    return _fail;
}

void SQL::display_command() const {
    cout << " " << _sql_command << endl;
}

// =============================================================
// private modifiers

void SQL::update_sql_table(const string &s, Table &t) {
    /// write new table's name onto the file
    ofstream fout;
    fout.open(STARTUP_FILE, ios::app);
    fout << s << endl;
    fout.close();

    //// insert table t and its name into the _sql_table map
    _sql_table[s] = t;
}

void SQL::remove_sql_table(const std::string &s) {
    _sql_table.erase(s);
    /// erase the table from _sql_table map

    ifstream fin;
    fin.open(STARTUP_FILE);
    ofstream fout;
    fout.open("temp.txt");

    string line;
    /// current line reading from file
    while (getline(fin, line)) {
        if (line != s)
            /// write all lines to a temp file other than the
            /// line marked for erasing
            fout << line << endl;
    }
    fin.close();
    fout.close();
    remove("startup.txt");
    /// remove file with table name to be erased in it
    rename("temp.txt", "startup.txt");
    /// rename new file to default startup
}

void SQL::clear_debug_folder() {
    // open a table object with each line and insert
    ifstream f;
    f.open(STARTUP_FILE);

    if (f.fail()) {
        cout << "clear debug folder::  opening"
             << STARTUP_FILE << " failed" << endl
             << endl;
        exit(-2);
    }

    char names[COMMAND_LENGTH + 1];
    /// to hold table names form file
    f.getline(names, COMMAND_LENGTH, '\n');
    /// read a line from file

    while (!f.eof()) {
        string s = names;
        s += ".bin";
        remove(strcpy(names, s.c_str()));
        f.getline(names, COMMAND_LENGTH, '\n');
    }

    f.close();
    /// eraseing everyting inside the startup file
    std::ofstream ofs;
    ofs.open(STARTUP_FILE, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}
