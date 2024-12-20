#include <bits/stdc++.h>
#include "../include/lch.hpp"

using std::vector;
using std::string;
using std::stringstream;

using std::getline;
using std::stoi;


void ValidateArguments(const int argc, const int offset, string functionName) {

    if (argc <= 1) {
        throw std::invalid_argument(
            RED_START +
            string("[ERROR] ") + functionName + ": (const int, char**, const int): No input parameters passed" +
            RESET_COLOR
        );
    }
    if (offset + 1 >= argc) {
        throw std::invalid_argument(
            RED_START +
            string("[ERROR] ") + functionName + ": (const int, char**, const int): Offset greater than num of parameters passed" +
            RESET_COLOR
        );
    }

    return;
}


// -- Input Parsing
/*
    @brief Parse inputs as ints from the command line, and put them in a vector<int>
    @param argc argc in main()
    @param argv argv in main()
    @param offset Offset to start parsing from from argv (offset 0 starts from argv[1])
    @return Parsed input in vector<int> format

    This works on space separated numbers as well as
    a single argument as follows [1,2,3,4]
*/
vector<int> ArgsParse_Int1D(const int argc, char** argv, const int offset) {

    ValidateArguments(argc, offset, "ArgsParse_Int1D(const int, char**, const int)");

    vector<int> vec;

    // Case 1: space separated values
    if (argv[1 + offset][0] != '[')
        for (int i = 1 + offset; i < argc; i++) 
            vec.push_back(stoi(argv[i]));


    // Case 2: [1,2,3]
    else if (argv[1 + offset][0] == '[') {

        string inp = argv[1 + offset];

        inp.erase(inp.begin());
        inp.pop_back();

        stringstream ss(inp);
        string item;

        while (getline(ss, item, ','))
            vec.push_back(stoi(item));
    }

    return vec;
}



/*
    @brief Parse inputs as ints from the command line, and put them in a vector<vector<int>>
    @param argc argc in main()
    @param argv argv in main()
    @param offset Offset to start parsing from from argv (offset 0 starts from argv[1])
    @return Parsed input in vector<vector<int>> format

    This works with the following format only:
        [[1,2,3],[4,5,6],[7,8,9]].

    The above argument is a single string
*/
vector<vector<int>> ArgsParse_Int2D(const int argc, char** argv, const int offset) {

    ValidateArguments(argc, offset, "ArgsParse_Int2D(const int, char**, const int)");


    // Set input
    string inp = argv[1 + offset];

    if (inp[0] != '[' || inp[1] != '[') {
        cerr << "Invalid format for 2D parsing\n";
        exit(0);
    }

    // Final vector
    vector<vector<int>> vec;

    // Remove '[' and ']'
    inp.erase(inp.begin());
    inp.pop_back();

    stringstream ssOuter(inp);
    string itemOuter;
    
    while (getline(ssOuter, itemOuter, ']')) {
        if (itemOuter[0] == ',')
            itemOuter.erase(itemOuter.begin());

        vector<int> row;

        stringstream ssInner(itemOuter);
        string itemInner;

        while(getline(ssInner, itemInner, ',')) {
            if (itemInner[0] == '[')
                itemInner.erase(itemInner.begin());

            row.push_back(stoi(itemInner));  
        }
        
        vec.push_back(row);
    }

    return vec;
}


/*
    @brief Parse inputs as ints from the command line, and put them in a vector<string>
    @param argc argc in main()
    @param argv argv in main()
    @param offset Offset to start parsing from from argv (offset 0 starts from argv[1])
    @return Parsed input in vector<string> format

    Works on space separated values as well as a single value like this ["hello world","checking","1234"]
*/
vector<string> ArgsParse_String1D(const int argc, char** argv, const int offset) {

    ValidateArguments(argc, offset, "ArgsParse_String1D(const int, char**, const int)");

    vector<string> vec;
    string inp = argv[1 + offset];

    // Case 1: space separated values
    if (inp[0] != '[')
        for (int i = 1 + offset; i < argc; i++)
            vec.push_back(argv[i]);
    

    // Case 2: [values, like, this]
    if (inp[0] == '[') {

        // Remove '[' and ']'
        inp.erase(inp.begin());
        inp.pop_back();

        stringstream ss(inp);
        string item;

        while(getline(ss, item, ','))
            vec.push_back(item);
    }

    return vec;
}