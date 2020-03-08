#include <bits/stdc++.h>
using namespace std;
int a[500007];
template<typename E>
void pr(E x){
    cout<<x<<" ";
}
void pr(int l,int r){
    cout<<rand()%(r-l+1)+l<<" ";
}
void tree(int n){
    for(int i=2;i<=n;i++) pr(1,i-1),pr(i);
}
void wtree(int n){
    for(int i=2;i<=n;i++) pr(1,i-1),pr(i),pr(-10000,-1);
}
int id[1000007];
int main(){
   // ios::sync_with_stdio(false);
    srand(time(0));pr(1);
    int T=20;pr(T);
    while(T--){
    int n=300;pr(n);
    for(int i=1;i<=n;i++) id[i]=i;
    random_shuffle(id+1,id+n+1);
    for(int i=1;i<=n;i++) cout<<id[i]<<" ";
    tree(n);}
    return 0;
}
