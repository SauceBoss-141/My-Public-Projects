#include "bank.h"
#include<iostream>
using namespace std;

int main(int argc, char *argv[]){
        if(argc!=2){
            cout<<"Program needs a file to run"<<endl;
            return 0;
        }else{
        bank mainBank= bank();
        mainBank.file_in(string(argv[1]));
        mainBank.execute_();
        
    return 0;
        }
}