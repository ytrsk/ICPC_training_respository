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
int main(){
   // ios::sync_with_stdio(false);
    freopen("test.in","w",stdout);
    int n=500;pr(n);
    int t=n*n;
    while(t--) pr(1,10000);
    return 0;
}
