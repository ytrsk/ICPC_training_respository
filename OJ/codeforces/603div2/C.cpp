#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int main(){
    int t=read();
    while(t--){
        int n=read();
        vector<int> g;
        for(int l=1,r;l<=n;l=r+1){
            r=n/(n/l);
            g.push_back(n/l);
        }
        reverse(g.begin(),g.end());
        cout<<g.size()+1<<"\n0 ";
        for(int i=0;i<g.size();i++){
            cout<<g[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}