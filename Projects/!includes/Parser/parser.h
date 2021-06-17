#ifndef PARSER_H
#define PARSER_H

#include <iostream>

#include "../../!includes/State_Machine/command_line_table.h"
#include "../../!includes/STokenizer/stokenizer.h"
#include "../../!includes/Token/token_strings.h"
#include "../../!includes/Queue/queue.h"
#include "../../!includes/Map/BPlus_Tree/multimap.h"
#include "../../!includes/Map/BPlus_Tree/map.h"
#include "../../!includes/Table/table.h"

class Parser
{

public:

    static const int CMD_MAX_ROWS = CMD_ROW;
    static const int CMD_MAX_COLUMNS = CMD_COL;

    // ==============================================================
    // constructors

    /// default
    Parser( );

    /// takes a character array
    Parser ( char s [] );

    // ==============================================================
    // accessors

    /// @returns the value of _ptree ,a multimap of parser /SQL commands
    /// from _input_string
    /// _ptree could be empty if an error occured when parsing
    MMap<string, string> get_parse_tree(  ) const;

    /// checks the validity of mem variable _ptree
    /// @returns true if parsing was completed without any failure or
    /// @returns false if parsing was finished without a success state
    bool is_valid ( ) const;

    // ==============================================================
    // modifiers

    /// takes a character array of commands from screen and tokenizes
    /// this input and pushes it into input_queue
    void set_string( const char str[ ]  );

    /// @returns true if input was parsed to a correct sql command or
    /// @returns false if at the end, we did not reach a success state
    ///          when parsing input string
    bool parse_tree( );

    void clear_parse( );


private:

    /// state machine representing table to parse input commands
    static int cmd_table[ CMD_MAX_ROWS ][ CMD_MAX_COLUMNS ];
    /// 2d array we will use to process sql commands and keywords
    /// \note   this table is independent of the table used for
    ///         string tokenizer although follows simillar principles

    /// a flag for checking validity of current Ptree
    bool _flag;
    /// \else parsing succeed, _flag = true
    /// \if parsing failed, _flag = false

    /// a string to stores the input string
    std::string _input_string;

    /// tokenzes string and returns tokens of words
    STokenizer _stk;

    /// stores the token from stokenizer
    Queue<std::string> input_queue;

    /// stores sql commands like SELECT, WHERE ... with an assigned integers
    Map< string, int > _keyword;

    /// a multimap of strings and strings to store current parsed
    /// commands from a given input
    MMap< string, string > _ptree;
    /// stores input strings in a form of syntax tree which
    /// ***another table class can recognize

    // ============================================================
    // private initializer

    /// initializer for the (state machine) table to parse commands
    void make_cmd_table ( int _table[][ CMD_MAX_COLUMNS ] );
    /// create table for all the tokens we will recognize
    ///   (e.g. select, first, last , salary ..  etc.. )
    // ============================================================
    // private accessors

    /// \returns  the column number of a string or keywords
    int get_column( const std::string& str );
    /// @returns str's corresponding int value from map _keyword
    /// if str is found in _keyword or
    /// @returns a default value to indicate column is SYMBOLE
    /// e.g. str = "select", returns 1, str = "John" returns 15( SYMBOLE)

    // ============================================================
    // private modifiers

    /// the keywords map is filled with sql commands and a number
    void build_keyword( );
    /// based on standard sql commands, keywords map is built with
    /// these commands with a number for each commands that will
    /// later help to identify commands from console



};

#endif // PARSER_H
