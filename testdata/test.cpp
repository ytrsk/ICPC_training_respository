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
int main(){
   // ios::sync_with_stdio(false);
   freopen("test.in","w",stdout);
    srand(time(0));
    int n=1000,m=4000;pr(n);pr(m);
    cout<<"\n";
    for(int i=2;i<=n;i++) pr(1,i-1);
    cout<<"\n";
    for(int i=1;i<=n;i++) pr(1,m);
    cout<<"\n";
    return 0;
}
