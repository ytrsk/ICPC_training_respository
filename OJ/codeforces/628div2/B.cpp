#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn];
map<int,int> aa;
int main(){
    int t=read();
    while(t--){
        int n=read();aa.clear();
        for(int i=1;i<=n;i++) a[i]=read(),aa[a[i]]=1;
        cout<<aa.size()<<endl;
    }
    return 0;
}