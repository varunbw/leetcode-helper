#include <bits/stdc++.h>
#include "../include/lch.h"

/*
    @brief Perform basic error checking on the input string
    @param
    `fin` The input file stream
    
    `callerFuncName` The name of the function to print in error messages
    @return None
*/
void ValidateInputStream(ifstream& fin, string callerFuncName) {
    
    if (fin.is_open() == false)
        throw runtime_error("[ERROR]: " + callerFuncName + ": Input stream not open");

    if (fin.fail())
        throw runtime_error("[ERROR]: " + callerFuncName + ": Input stream failed due to some reason");

    if (fin.eof())
        throw runtime_error("[ERROR]: " + callerFuncName + ": Input stream at EOF, check number of testcases again");
    
    return;
}


/*
    @brief Get a single line from the input file stream
    @param
    `fin` The input file stream
    
    `callerFuncName` The name of the function to print in error messages

    @return Fetched line

    This same code was being reused everywhere, so just put it in a function.
    Other than that, this doesn't really do anything special
*/
string GetLineFromStream(ifstream& fin, string callerFuncName) {

    string res;

    // Remove any newline character left in the buffer
    if (fin.peek() == '\n')
        fin.ignore();
    
    getline(fin, res);

    if (res.size() == 0)
        throw runtime_error("[ERROR]: " + callerFuncName + ": Tried to parse empty line in, check number of testcases again");

    return res;
}

/*
    @brief Parse inputs into a vector<int> from the given stream `fin`
    @param `fin` The input file stream
    @return Parsed input in a vector<int>

    This works with the following format only:
        [1,2,3,4,...]
*/
vector<int> FileParse_Int1D(ifstream& fin) {

    ValidateInputStream(fin, "FileParse_Int1D");
    string line = GetLineFromStream(fin, "FileParse_Int1D");

    // Erase any leading/trailing brackets that ideally should be there
    if (line[0] == '[')
        line.erase(line.begin());
    if (line.back() == ']')
        line.pop_back();

    vector<int> res;
    stringstream ss(line);
    string item;

    while (getline(ss, item, ',')) {
        while (item.size() && item[0] == ' ')
            item.erase(item.begin());
        res.push_back(stoi(item));
    }
    
    return res;
}


/*
    @brief Parse inputs into a vector<vector<int>> from the given stream `fin`
    @param `fin` The input file stream
    @return Parsed input in a vector<vector<int>>

    This works with the following format only:
        [[1,2,3,4,...],[5,6,7,8,...],...]
*/
vector<vector<int>> FileParse_Int2D(ifstream& fin) {

    ValidateInputStream(fin, "FileParse_Int2D");
    string line = GetLineFromStream(fin, "FileParse_Int2D");

    // Erase any leading/trailing brackets that ideally should be there
    if (line[0] == '[')
        line.erase(line.begin());
    if (line.back() == ']')
        line.pop_back();

    vector<vector<int>> res;
    stringstream ssOuter(line);
    string itemOuter;

    // TODO try-catch handling for stoi()

    // Outer loop fetches one row at a time
    while (getline(ssOuter, itemOuter, ']')) {
        if (itemOuter[0] == ',')
            itemOuter.erase(itemOuter.begin());

        vector<int> row;
        stringstream ssInner(itemOuter);
        string itemInner;

        // Inner loop processes each element
        while (getline(ssInner, itemInner, ',')) {
            while (itemInner[0] == '[' || itemInner[0] == ' ')
                itemInner.erase(itemInner.begin());

            row.push_back(stoi(itemInner));  
        }
        
        res.push_back(row);
    }
    
    return res;
}


/*
    @brief Parse inputs into a vector<string> from the given stream `fin`
    @param `fin` The input file stream
    @return Parsed input in a vector<string>

    Wrap your strings with "", this function works with the following format only:
        ["Hello","World"]

    Refer FAQs on why more formats aren't supported
*/
vector<string> FileParse_String1D(ifstream& fin) {

    ValidateInputStream(fin, "FileParse_String1D");
    string line = GetLineFromStream(fin, "FileParse_String1D");

    if (line[0] == '[')
        line.erase(line.begin());
    if (line.back() == ']')
        line.pop_back();

    vector<string> res;
    stringstream ss(line);
    string item;

    while (getline(ss, item, ',')) {
        // Remove any whitespace
        while (item.size() && item[0] == ' ')
            item.erase(item.begin());
        
        // Remove starting and ending "s
        if (item.size() && item[0] == '"')
            item.erase(item.begin());
        if (item.back() == '"')
            item.pop_back();

        res.push_back(item);
    }

    return res;
}


/*
    @brief Parse inputs into a vector<vector<string>> from the given stream `fin`
    @param `fin` The input file stream
    @return Parsed input in a vector<vector<string>>

    Wrap your strings with "", this function works with the following format only:
        [["Hello","World"],["This is ", "a test"]]
    
    You may leave spaces here anywhere, but in case you dont see the expected output, just stick to no spaces

    Refer FAQs on why more formats aren't supported
*/
vector<vector<string>> FileParse_String2D(ifstream& fin) {

    ValidateInputStream(fin, "FileParse_String2D");
    string line = GetLineFromStream(fin, "FileParse_String2D");

    if (line[0] == '[')
        line.erase(line.begin());
    if (line.back() == ']')
        line.pop_back();

    vector<vector<string>> res;
    stringstream ssOuter(line);
    string itemOuter;

    while (getline(ssOuter, itemOuter, ']')) {
        if (itemOuter[0] == ',')
            itemOuter.erase(itemOuter.begin());

        vector<string> row;
        stringstream ssInner(itemOuter);
        string itemInner;

        while(getline(ssInner, itemInner, ',')) {
            // Remove any opening brackets and whitespaces that the item might have
            while (itemInner.size() && (itemInner[0] == '[' || itemInner[0] == ' '))
                itemInner.erase(itemInner.begin());

            // Remove the "" that a string is encased in
            if (itemInner.size() && itemInner[0] == '"')
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
    @brief Parse inputs into a vector<char> from the given stream `fin`
    @param `fin` The input file stream
    @return Parsed input in a vector<char>

    Wrap your chars with "", this function works with the following format only:
        ["a","b","c","d","e"]

    You may leave spaces here anywhere, but in case you dont see the expected output, just stick to no spaces

    Refer FAQs on why more formats aren't supported
*/
vector<char> FileParse_Char1D(ifstream& fin) {

    ValidateInputStream(fin, "FileParse_Char1D");
    string line = GetLineFromStream(fin, "FileParse_Char1D");

    // Erase any leading/trailing brackets that ideally should be there
    if (line[0] == '[')
        line.erase(line.begin());
    if (line.back() == ']')
        line.pop_back();
    
    vector<char> res;
    stringstream ss(line);
    string item;

    while (getline (ss, item, ',')) {
        // Erase any spaces from the beginning
        while (item.size() && item[0] == ' ')
            item.erase(item.begin());

        // Remove the "" that a character is encased in
        if (item.size() && item[0] == '"')
            item.erase(item.begin());
        if (item.back() == '"')
            item.pop_back();
        
        // Add the 0th element of item, which happens to be the entire thing
        res.push_back(item[0]);
    }

    return res;
}


/*
    @brief Parse inputs into a vector<vector<char>> from the given stream `fin`
    @param `fin` The input file stream
    @return Parsed input in a vector<vector<char>>

    Wrap your chars with "", this function works with the following format only:
        [["a","b","c","d","e"],['a','b','c','d','e']]
        [[a,b,c,d,e],[a,b,c,d,e]]

    You may leave spaces here anywhere, but in case you dont see the expected output, just stick to one of the above formats

    Refer FAQs on why more formats aren't supported
*/
vector<vector<char>> FileParse_Char2D(ifstream& fin) {

    ValidateInputStream(fin, "FileParse_Char2D");
    string line = GetLineFromStream(fin, "FileParse_Char2D");

    // Erase any leading/trailing brackets that should be 
    if (line[0] == '[')
        line.erase(line.begin());
    if (line.back() == ']')
        line.pop_back();

    vector<vector<char>> res;
    stringstream ssOuter(line);
    string itemOuter;

    // Outer loop processes takes a row at a time
    while (getline(ssOuter, itemOuter, ']')) {
        if (itemOuter.size() && itemOuter[0] == ',')
            itemOuter.erase(itemOuter.begin());

        vector<char> row;
        stringstream ssInner(itemOuter);
        string itemInner;

        // Inner loop processes individual elements
        while (getline(ssInner, itemInner, ',')) {
            while (itemInner.size() && itemInner[0] == ' ')
                itemInner.erase(itemInner.begin());
            
            // Remove any leading/trailing "s
            if (itemInner.size() && itemInner[0] == '"')
                itemInner.erase(itemInner.begin());
            if (itemInner.back() == '"')
                itemInner.pop_back();
            
            row.push_back(itemInner[0]);
        }

        res.push_back(row);
    }

    return res;
}