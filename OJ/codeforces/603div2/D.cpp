#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=200007;
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
map<string,int> id;
int fa[maxn],you[maxn];
int find(int x){
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        for(int k=0;k<s.length();k++){
            int x=s[k]-'a';
            if(!you[x]) you[x]=i;
            else fa[find(you[x])]=find(i);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++) if(find(i)==i) ++cnt;
    cout<<cnt;
    return 0;
}