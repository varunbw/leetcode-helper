#include <bits/stdc++.h>
#include "../include/lch.h"

/*
    @brief Parse inputs into a vector<int> from the given stream `inp`
    @param `inp` The input file stream
    @return Parsed input in a vector<int>

    This works with the following format only:
        [1,2,3,4,...]
    Do not put a space chracter anywhere.
    Space separated integers are not supported (yet?), use ArgsParseInt_1D and pass the input from command line if needed.
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
    Do not put a space chracter anywhere; space separated integers are not supported.
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
    Do not put a space chracter anywhere.
    Space separated strings are not supported (yet?), use ArgsParseInt_2D and pass the input from command line if needed.
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
    Do not put a space chracter anywhere; space separated strings are not supported.
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
    if(inp.peek() == '\n')
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