#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=1007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[maxn];
int you[1007][57];
const int mod=1e9+7;   
int now[1007];
int main(){
    int n=read(),K=read();
    scanf("%s",s+1);
    now[0]=1;
    for(int i=1;i<=n;i++){
        int ch=s[i]-'a';
        for(int k=K-1;~k;k--){
            int x=now[k];
            now[k+1]=(0LL+now[k+1]+now[k]-you[k][ch]+mod)%mod;
            you[k][ch]=now[k];
        }
    }
    if(K==0) cout<<1;
    else cout<<now[K];
    return 0;
}