#pragma once
#ifndef BIN_FILE_FUNCTIONS_H
#define BIN_FILE_FUNCTIONS_H

#include <fstream>
#include <iostream>


using namespace std;

/**
 * @pre takes a const string reference of a filename
 * @post opens the filename in a binary form
 *       \if file exists \returns true
 *       \else file doesn't exist, \return false
 */
bool file_exists( const string& filename );

/**
 * @pre takes a const string reference of a filename, and filestream reference
 * @post checks if file with the given filename exists,
 *       \if file exists, file is opened in read and write mode
 *       \else file doesn't exist, file is created for a writing mode only
 */
void open_fileRW( fstream& f, const string& filename ) throw( char* );
/**
 * @pre takes a const string reference of a filename, and file stream reference
 * @post attempts to opens file for writing purpose only
 *       \if opening the file success noting
 *       \else opening the file fails, terminate
 */
void open_fileW( fstream& f, const string& filename ) ;


//void open_fileR( fstream& f, const string& filename );
/**
 * @pre takes a const string reference of a filename, and file stream reference
 * @post attempts to opens file for reading purpose only
 *       \if opening the file success noting
 *       \else opening the file fails, terminate
 */

/// ======================================================================
///              DEFINITIONS
/// ======================================================================

bool file_exists( const string& filename )
{
    const bool DEBUG = false;
    fstream f;
    f.open ( filename,std::fstream::in | std::fstream::binary  );
    /// open binary file for input
    if ( f.fail(  ) )
    {
        if ( DEBUG )
            cout << "file_exists(): " << filename << " does NOT exist\n";
        return false;
    }

    f.close(  );
    return true;
}

void open_fileRW( fstream& f, const string& filename) throw( char* )
{
    const bool DEBUG = false;
     /// \if file name does not  exists
    if ( !file_exists( filename ) )
    {
        /// open file for output only
        f.open( filename, std::fstream::out|std::fstream::binary );
        if ( f.fail(  ) )
        {
            cout << "file_open_RW(): failed with out|" << filename << "]\n";
            throw( "file RW failed " );
        }
        else
        {
            if ( DEBUG )
                cout << "open_fileRW: " << filename << " created" << endl;
        }
    }
    else      /// \else file name  exists
    {
        /// open file in writing and reading mode
        f.open ( filename,  std::fstream::in |
                            std::fstream::out| std::fstream::binary  );
        if ( f.fail(  ) )
        {
            cout << "open_fileRW: failed. [" << filename << "]" << endl;
            throw( "file failed to open." );
        }
    }
}


void open_fileW( fstream& f, const string&  filename )
{
    /// open file for writing purpose only
    /// \note this will erase existing texts in the file
    f.open ( filename , std::fstream::out | std::fstream::binary  );

    /// if file doesn't exist or cannot be opened
    if ( f.fail(  ) )
    {
        cout << "open_fileW(): [ " << filename << " ] faild to open\n";
        throw( "file failed to open." );
    }

}


//void open_fileR( fstream& f, const string& filename )
//{
//    f.open( filename , std::fstream::in | std::fstream::binary );
//    if ( f.fail(  ) )
//    {
//        cout << "open_fileR( ): [ " << filename << " ] faild to open\n";
//        throw( "file failed to open." );
//    }
//}

#endif // BIN_FILE_FUNCTIONS_H
