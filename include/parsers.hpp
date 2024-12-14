#pragma once

#ifndef LCH_PARSERS
#define LCH_PARSERS

#include <bits/stdc++.h>

// -- Input Parsing - Through input file stream
/*
    @brief Parse inputs into a std::vector<int> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a std::vector<int>

    This works with the following format only:
        [1,2,3,4,...]
*/
std::vector<int> FileParse_Int1D(std::ifstream& fin);

/*
    @brief Parse inputs into a std::vector<std::vector<int>> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a std::vector<std::vector<int>>

    This works with the following format only:
        [[1,2,3,4,...],[5,6,7,8,...],...]

    IMPORTANT: Keep the entire 2D grid in one line as seen above, don't split the rows into different lines
*/
std::vector<std::vector<int>> FileParse_Int2D(std::ifstream& fin);

/*
    @brief Parse inputs into a std::vector<std::string> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a std::vector<std::string>

    This works with the following formats only:
        ["Hello","World"]
        [Hello,World]
*/
std::vector<std::string> FileParse_String1D(std::ifstream& fin);

/*
    @brief Parse inputs into a std::vector<std::vector<std::string>> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a std::vector<std::vector<std::string>>

    This works with the following format only:
        [["Hello","World"],["This is ", "a test :)"]]

    IMPORTANT: Keep the entire 2D grid in one line as seen above, don't split the rows into different lines
*/
std::vector<std::vector<std::string>> FileParse_String2D(std::ifstream& fin);

/*
    @brief Parse inputs into a std::vector<char> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a std::vector<char>

    This works with the following formats
        ["a","b","c","d","e"]
        ['a','b','c','d','e']
        [a,b,c,d,e]
        a,b,c,d,e

    You may leave spaces here anywhere, but in case you dont see the expected output, just stick to one of the above formats
*/
std::vector<char> FileParse_Char1D(std::ifstream& fin);

/*
    @brief Parse inputs into a std::vector<std::vector<char>> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a std::vector<std::vector<char>>

    This works with the following formats
        [["a","b","c","d","e"],['a','b','c','d','e']]
        [[a,b,c,d,e],[a,b,c,d,e]]

    You may leave spaces here anywhere, but in case you dont see the expected output, just stick to one of the above formats
    IMPORTANT: Keep the entire 2D grid in one line as seen above, don't split the rows into different lines
*/
std::vector<std::vector<char>> FileParse_Char2D(std::ifstream& fin);



// -- Input Parsing - Through command line arguments
// ! These aren't really ideal, use the file parsers above
/*
    @brief Parse inputs as ints from the command line, and put them in a std::vector<int>
    @param argc argc in main()
    @param argv argv in main()
    @param offset Offset to start parsing from from argv (offset 0 starts from argv[1])
    @return Parsed input in std::vector<int> format

    This works on space separated numbers as well as
    a single argument as follows [1,2,3,4]
*/
std::vector<int> ArgsParse_Int1D(const int argc, char** argv, const int offset);

/*
    @brief Parse inputs as ints from the command line, and put them in a std::vector<std::vector<int>>
    @param argc argc in main()
    @param argv argv in main()
    @param offset Offset to start parsing from from argv (offset 0 starts from argv[1])
    @return Parsed input in std::vector<std::vector<int>> format

    This works with the following format only:
        [[1,2,3],[4,5,6],[7,8,9]].

    The above argument is a single std::string
*/
std::vector<std::vector<int>> ArgsParse_Int2D(const int argc, char** argv, const int offset);

/*
    @brief Parse inputs as ints from the command line, and put them in a std::vector<std::string>
    @param argc argc in main()
    @param argv argv in main()
    @param offset Offset to start parsing from from argv (offset 0 starts from argv[1])
    @return Parsed input in std::vector<std::string> format

    Works on space separated values as well as a single value like this ["hello world","checking","1234"]
*/
std::vector<std::string> ArgsParse_String1D(const int argc, char** argv, const int offset);


#endif