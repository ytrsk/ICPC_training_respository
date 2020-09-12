#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
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
char A[100007],B[100007];
int preA[100007];
int df[100007];
int preB[100007];
int main(){
    int t=read();
    while(t--){
        int n=read();
        scanf("%s%s",A+1,B+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(A[i]!=B[i]) ans++;
            df[i]=(A[i]!=B[i])+df[i-1];
            preA[i]=preA[i-1]+A[i]-'0';
            preB[i]=preB[i-1]+B[i]-'0';
        }
        df[n+1]=df[n];
        A[n+1]=B[n+1]='0';
        for(int i=1;i<=n;i++){
            int now=i-preA[i]+(A[i+1]!='0');
            now+=preB[i]+(B[i+1]!='1')+df[n+1]-df[i+1];
            ans=min(ans,now+1);
        }
        printf("%d\n",ans);
    }
    return 0;
}