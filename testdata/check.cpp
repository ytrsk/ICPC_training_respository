#include <bits/stdc++.h>
using namespace std;
int main(){
    system("g++ my.cpp -o my.exe -std=c++14");
    system("g++ test.cpp -o test.exe -std=c++14");
    system("g++ std.cpp -o std.exe -std=c++14");
    system("@echo off");
    while(1){
        system("test.exe > test.in");
        system("my.exe < test.in > my.out");
        system("std.exe < test.in > std.out");
        if(system("fc my.out std.out")) system("pause");
    }
    return 0;
}