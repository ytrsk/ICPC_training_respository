#include <bits/stdc++.h>
using namespace std;
int main(){
    system("g++ my.cpp -o my.exe -std=c++14");
    system("g++ test.cpp -o test.exe -std=c++14");
    system("g++ std.cpp -o std.exe -std=c++14");
    while(1){
        system("start test.exe > test.in");
        system("start my.exe < test.in > my.out");
        system("start std.exe < test.in > std.out");
        if(system("fc my.out std.out")) system("pause");
    }
    return 0;
}