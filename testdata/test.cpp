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

    int n=500000,m=500000;pr(n);pr(m);
    while(n--) pr(1,100000),pr(1,100000);
    while(m--) pr(1,2),pr(1,100000),pr(1,100000);
    return 0;
}
