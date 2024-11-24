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
vector<int> ParseVector1D(ifstream& inp) {

    if (inp.is_open() == false)
        throw runtime_error("Input stream not open in ParseVector1D(ifstream&)");

    if (inp.fail())
        throw runtime_error("Input stream failed due to some reason in ParseVector1D(ifstream&)");

    if (inp.eof())
        throw runtime_error("Input stream at EOF in ParseVector1D(ifstream&), check number of testcases again");

    vector<int> res;
    string inputString;
    inp >> inputString;

    if (inputString.size() == 0)
        throw runtime_error("Tried to parse empty line in ParseVector1D(ifstream&), check number of testcases again");

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
    Do not put a space chracter anywhere.
    Space separated integers are not supported (yet?), use ArgsParseInt_2D and pass the input from command line if needed.
*/
vector<vector<int>> ParseVector2D(ifstream& inp) {

    if (inp.is_open() == false)
        throw runtime_error("Input stream not open in ParseVector1D(ifstream&)");

    if (inp.fail())
        throw runtime_error("Input stream failed due to some reason in ParseVector1D(ifstream&)");

    if (inp.eof())
        throw runtime_error("Input stream at EOF in ParseVector1D(ifstream&), check number of testcases again");

    vector<vector<int>> res;
    string inputString;
    inp >> inputString;

    if (inputString.size() == 0)
        throw runtime_error("Tried to parse empty line in ParseVector1D(ifstream&), check number of testcases again");

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
            if (itemInner[0] == '[')
                itemInner.erase(itemInner.begin());

            row.push_back(stoi(itemInner));  
        }
        
        res.push_back(row);
    }
    
    return res;
}

