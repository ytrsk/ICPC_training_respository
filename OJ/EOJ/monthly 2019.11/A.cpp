#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=500007;
const int inf=(1LL<<29);
const int mod=1e9+7;
ll read(){
    ll x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
char s[500007];
int q[maxn],top,pos[maxn],id[maxn];
ll mul[maxn];
int main(){
    int n=read(),m=read(),z=read();ll tot=read();
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++){
        if(s[i]=='#'){
            pos[i]=++top;id[top]=i;
        }
    }
    ll ans=1,num=0;mul[num]=ans;
    if(z!=1) while(z<(tot-1)/ans+1) ans*=z,mul[++num]=ans;
    for(int i=1;i<=len;i++){
        if(s[i]=='#'){
            if(z>=2&&top-pos[i]<=num){
                for(int k=1;k<=z;k++){
                    if(tot>mul[top-pos[i]]) tot-=mul[top-pos[i]];
                    else{
                        q[i]=k;break;
                    }
                }
            }
            else{
                q[i]=1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        char ss[30];scanf("%s",ss+1);
        sort(ss+1,ss+z+1);
        s[id[i]]=ss[q[id[i]]];
    }
    cout<<s+1;
    return 0;
}