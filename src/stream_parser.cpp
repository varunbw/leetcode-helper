#include <bits/stdc++.h>
#include "../include/lch.h"

/*
    @brief Parse inputs into a vector<int> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a vector<int>

    This works with the following format only:
        [1,2,3,4,...]
*/
vector<int> FileParse_Int1D(ifstream& inp) {

    if (inp.is_open() == false)
        throw runtime_error("Input stream not open in FileParse_Int1D(ifstream&)");

    if (inp.fail())
        throw runtime_error("Input stream failed due to some reason in FileParse_Int1D(ifstream&)");

    if (inp.eof())
        throw runtime_error("Input stream at EOF in FileParse_Int1D(ifstream&), check number of testcases again");

    vector<int> res;
    string inputString;
    if(inp.peek() == '\n')
        inp.ignore();
    getline(inp, inputString);

    if (inputString.size() == 0)
        throw runtime_error("Tried to parse empty line in FileParse_Int1D(ifstream&), check number of testcases again");

    inputString.erase(inputString.begin());
    inputString.pop_back();

    stringstream ss(inputString);
    string item;

    while (getline(ss, item, ','))
        res.push_back(stoi(item));
    
    return res;
}


/*
    @brief Parse inputs into a vector<vector<int>> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a vector<vector<int>>

    This works with the following format only:
        [[1,2,3,4,...],[5,6,7,8,...],...]
*/
vector<vector<int>> FileParse_Int2D(ifstream& inp) {

    if (inp.is_open() == false)
        throw runtime_error("Input stream not open in FileParse_Int2D(ifstream&)");

    if (inp.fail())
        throw runtime_error("Input stream failed due to some reason in FileParse_Int2D(ifstream&)");

    if (inp.eof())
        throw runtime_error("Input stream at EOF in FileParse_Int2D(ifstream&), check number of testcases again");

    vector<vector<int>> res;
    string inputString;
    if(inp.peek() == '\n')
        inp.ignore();
    getline(inp, inputString);

    if (inputString.size() == 0)
        throw runtime_error("Tried to parse empty line in FileParse_Int2D(ifstream&), check number of testcases again");

    inputString.erase(inputString.begin());
    inputString.pop_back();

    stringstream ssOuter(inputString);
    string itemOuter;

    while (getline(ssOuter, itemOuter, ']')) {
        if (itemOuter[0] == ',')
            itemOuter.erase(itemOuter.begin());

        vector<int> row;

        stringstream ssInner(itemOuter);
        string itemInner;

        while(getline(ssInner, itemInner, ',')) {
            while (itemInner[0] == '[' || itemInner[0] == ' ')
                itemInner.erase(itemInner.begin());

            row.push_back(stoi(itemInner));  
        }
        
        res.push_back(row);
    }
    
    return res;
}


/*
    @brief Parse inputs into a vector<string> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a vector<string>

    This works with the following formats only:
        ["Hello","World"]
        [Hello,World]
*/
vector<string> FileParse_String1D(ifstream& inp) {

    if (inp.is_open() == false)
        throw runtime_error("Input stream not open in FileParse_String1D(ifstream&)");

    if (inp.fail())
        throw runtime_error("Input stream failed due to some reason in FileParse_String1D(ifstream&)");

    if (inp.eof())
        throw runtime_error("Input stream at EOF in FileParse_String1D(ifstream&), check number of testcases again");

    vector<string> res;
    string inputString;
    if(inp.peek() == '\n')
        inp.ignore();
    getline(inp, inputString);

    if (inputString.size() == 0)
        throw runtime_error("Tried to parse empty line in FileParse_String1D(ifstream&), check number of testcases again");

    inputString.erase(inputString.begin());
    inputString.pop_back();

    stringstream ss(inputString);
    string item;

    while(getline(ss, item, ',')) {
        while (item[0] == '"' || item[0] == ' ')
            item.erase(item.begin());
        if (item.back() == '"')
            item.pop_back();

        res.push_back(item);
    }

    return res;
}


/*
    @brief Parse inputs into a vector<vector<string>> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a vector<vector<string>>

    This works with the following format only:
        ["Hello","World"]
        [Hello,World]
*/
vector<vector<string>> FileParse_String2D(ifstream& inp) {

    if (inp.is_open() == false)
        throw runtime_error("Input stream not open in FileParse_String2D(ifstream&)");

    if (inp.fail())
        throw runtime_error("Input stream failed due to some reason in FileParse_String2D(ifstream&)");

    if (inp.eof())
        throw runtime_error("Input stream at EOF in FileParse_String2D(ifstream&), check number of testcases again");

    vector<vector<string>> res;
    string inputString;
    if (inp.peek() == '\n')
        inp.ignore();
    getline(inp, inputString);

    if (inputString.size() == 0)
        throw runtime_error("Tried to parse empty line in FileParse_String2D(ifstream&), check number of testcases again");
    
    inputString.erase(inputString.begin());
    inputString.pop_back();

    stringstream ssOuter(inputString);
    string itemOuter;

    while (getline(ssOuter, itemOuter, ']')) {
        if (itemOuter[0] == ',')
            itemOuter.erase(itemOuter.begin());

        vector<string> row;

        stringstream ssInner(itemOuter);
        string itemInner;

        while(getline(ssInner, itemInner, ',')) {
            while (itemInner[0] == '[' || itemInner[0] == ' ')
                itemInner.erase(itemInner.begin());

            while (itemInner[0] == '"' || itemInner[0] == ' ')
                itemInner.erase(itemInner.begin());
            if (itemInner.back() == '"')
                itemInner.pop_back();
            row.push_back(itemInner);  
        }
        
        res.push_back(row);
    }

    return res;
}


/*
    @brief Parse inputs into a vector<char> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a vector<char>

    This works with the following formats
        ["a","b","c","d","e"]
        ['a','b','c','d','e']
        [a,b,c,d,e]
        a,b,c,d,e

    You may leave spaces here anywhere, but in case you dont see the expected output, just stick to one of the above formats
*/
vector<char> FileParse_Char1D(ifstream& inp) {

    if (inp.is_open() == false)
        throw runtime_error("Input stream not open in FileParse_Int1D(ifstream&)");

    if (inp.fail())
        throw runtime_error("Input stream failed due to some reason in FileParse_Int1D(ifstream&)");

    if (inp.eof())
        throw runtime_error("Input stream at EOF in FileParse_Int1D(ifstream&), check number of testcases again");

    string line;
    // A newline character can sometimes be left in the buffer
    while (inp.peek() == '\n')
        inp.ignore();
    getline(inp, line);

    if (line.size() == 0)
        throw runtime_error("Tried to parse empty line in FileParse_Char1D(ifstream&), check number of testcases again");

    // Ideally, the input should be encased in square brackets
    // The if statements are here just to check that is, and we dont lose any data
    if (line[0] == '[')
        line.erase(line.begin());
    if (line.back() == ']')
        line.pop_back();
    
    vector<char> res;
    stringstream ss(line);
    string item;

    while (getline (ss, item, ',')) {
        // Erase any '"' or spaces from the beginning
        while (item.size() && (item[0] == '"' || item[0] == ' '))
            item.erase(item.begin());
        // `item` might have a closing '"'
        if (item.back() == '"')
            item.pop_back();
        
        // Add the 0th element of item, which happens to be the entire thing
        res.push_back(item[0]);
    }

    return res;
}


/*
    @brief Parse inputs into a vector<vector<char>> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a vector<vector<char>>

    This works with the following formats
        [["a","b","c","d","e"],['a','b','c','d','e']]
        [[a,b,c,d,e],[a,b,c,d,e]]

    You may leave spaces here anywhere, but in case you dont see the expected output, just stick to one of the above formats
*/
vector<vector<char>> FileParse_Char2D(ifstream& inp) {

    if (inp.is_open() == false)
        throw runtime_error("Input stream not open in FileParse_Char(ifstream&)");

    if (inp.fail())
        throw runtime_error("Input stream failed due to some reason in FileParse_Char(ifstream&)");

    if (inp.eof())
        throw runtime_error("Input stream at EOF in FileParse_Char(ifstream&), check number of testcases again");

    // Fetch an entire line and remove any newline characters that might be still left in the buffer
    string line;
    while (inp.peek() == '\n')
        inp.ignore();
    getline(inp, line);

    // Just in case
    if (line.size() == 0)
        throw runtime_error("Tried to parse empty line in FileParse_Char2D(ifstream&), check number of testcases again");

    // Erase any leading/trailing brackets that should be 
    if (line[0] == '[')
        line.erase(line.begin());
    if (line.back() == ']')
        line.pop_back();

    stringstream ssOuter(line);
    string itemOuter;

    vector<vector<char>> res;
    // Outer loop processes takes a row at a time
    while (getline(ssOuter, itemOuter, ']')) {
        if (itemOuter.size() && itemOuter[0] == ',')
            itemOuter.erase(itemOuter.begin());

        stringstream ssInner(itemOuter);
        string itemInner;

        vector<char> row;
        // Inner loop processes individual elements
        while (getline(ssInner, itemInner, ',')) {
            while (itemInner.size() &&
                  (itemInner[0] == '[' || itemInner[0] == ' ' ||
                   itemInner[0] == '"' || itemInner[0] == '\''))
                itemInner.erase(itemInner.begin());
            
            if (itemInner.back() == '"')
                itemInner.pop_back();
            
            row.push_back(itemInner[0]);
        }

        res.push_back(row);
    }

    return res;
}