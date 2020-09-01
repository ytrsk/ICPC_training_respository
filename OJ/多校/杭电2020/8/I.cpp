#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=5000007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[5000007];
int len,num[5000007];
typedef unsigned long long ull;
ull ha[maxn],pre[maxn];
unordered_map<ll,int> aa;
inline ull calc(int l,int r){
    return pre[r]-pre[l-1]*ha[r-l+1];
}
int main(){
    ha[0]=1;
    for(int i=1;i<=5000000;i++) ha[i]=ha[i-1]*27;
    int t=read();
    while(t--){
        int n=read();scanf("%s",s+1);
        len=0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                num[++len]=i;
                if(i*i!=n) num[++len]=n/i;
            }
        }
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]*27+s[i]-'a'+1;
        int ok=0;
     //   cout<<len<<endl;
        for(int i=1;i<=len;i++){
            int OK=1;
            aa.clear();
            int x=num[i];
            if(x==n) continue;
            for(int k=1;k<=x;k++){
                aa[calc(k+1,x)*ha[k]+pre[k]]=1;
            }
            for(int k=2;k<=n/x;k++){
                if(!aa[calc((k-1)*x+1,k*x)]){
               //     cout<<(k-1)*x+1<<" "<<k*x<<" "<<calc((k-1)*x+1,k*x)<<endl;
                    OK=0;break;
                }
            }
            if(OK){
                ok=1;break;
            }
        }
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}