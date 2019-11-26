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
    srand(time(0));
    int t=5;
    pr(t);
    while(t--){
        int n=10000;pr(n);wtree(n);
        int q=30000;
        for(int i=1;i<=q;i++){
            if(i%2) pr("QUERY");
            else pr("CHANGE");
            pr(1,n/2);if(i%2) pr(n/2+1,n);else pr(-10000,-1);
        }
        pr("DONE");
    }
    return 0;
}
