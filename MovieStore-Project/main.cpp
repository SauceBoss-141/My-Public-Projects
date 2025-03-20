#include <iostream>
#include <fstream>
#include <sstream>
#include "vendor.h"

using namespace std;

// ---------------------------------------------- Main ---------------------------------------------
// Jacob Brown
// CSS343
// Assignment 4
// Created 03/03/25 Last edited 03/14/25
// --------------------------------------------------------------------------------------------------
int main(){

    string files[3]{ "data4customers.txt", "data4movies.txt", "data4commands.txt"};
    vendor v;
    for(int i =0; i < 3;i++){
        v.readFile(files[i]);
    }
    return 0;
};