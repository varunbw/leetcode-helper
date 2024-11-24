#include <bits/stdc++.h>
#include "../include/lch.h"

vector<int> ParseVector1D(ifstream& inp) {

    if (inp.is_open() == false)
        throw runtime_error("Input stream not open in ParseVector1D(ifstream&)");

    if (inp.fail())
        throw runtime_error("Input stream failed due to some reason in ParseVector1D(ifstream&)");

    vector<int> res;
    string inputString;
    inp >> inputString;

    inputString.erase(inputString.begin());
    inputString.pop_back();

    stringstream ss(inputString);
    string item;

    while (getline(ss, item, ','))
        res.push_back(stoi(item));
    
    return res;
}