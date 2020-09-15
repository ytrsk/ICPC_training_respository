#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=300007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int flag[maxn];
char s[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read(),K=read();
        scanf("%s",s+1);
        fill(flag,flag+K,-1);
        int ok=1;
        rep(i,1,n){
            int ch=-1;
            if(s[i]=='0') ch=0;
            if(s[i]=='1') ch=1;
            if(~ch){
                if(flag[i%K]==-1) flag[i%K]=ch;
                else if(flag[i%K]!=ch) ok=0;
            }
        }
        int cnt0=0;
        rep(i,1,K){
            if(~flag[i%K]) s[i]=flag[i%K]+'0';
            if(s[i]=='0') cnt0++;
        }
        rep(i,1,K){
            if(s[i]=='?'){
                if(cnt0<K/2) cnt0++;
            }
        }
        if(cnt0==K/2&&ok){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}