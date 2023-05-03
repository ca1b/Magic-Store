#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

#ifndef CART_H
#define CART_H

class Cart
{
private:
    string uID = "";
    string filename = "";
public:
    Cart(string uID)
    {
        this->uID = uID;
        filename = uID + ".csv";
    };

    string getFilename() { return filename; };
    bool addCart()
    {
        fstream fout;
        fout.open(filename, ios::out | ios::app);
        return true;
    };

    bool removeCart()
    {
        remove(filename.c_str());
        return true;
    };
};


#endif