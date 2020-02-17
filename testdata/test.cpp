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
int rd(int l,int r){
    return rand()%(r-l+1)+l;
}
void tree(int n){
    for(int i=2;i<=n;i++) pr(1,i-1),pr(i);
}
void wtree(int n){
    for(int i=2;i<=n;i++) pr(1,i-1),pr(i),pr(-10000,-1);
}
int A[307];
int main(){
   // ios::sync_with_stdio(false);
    //freopen("test.in","w",stdout);
    srand(time(0));
    int n=60;pr(n);
    for(int i=1;i<=n;i++) A[i]=rand()%5+1;
    for(int i=1;i<=n;i++) cout<<A[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=4;i++) pr(rand()%2+1);
    return 0;
}
