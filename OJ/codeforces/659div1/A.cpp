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
int a[26][26],c[26][26],q[maxn];
char A[maxn],B[maxn];
int top=0;
int main(){
    int t=read();
    while(t--){
        int n=read();
        scanf("%s%s",A+1,B+1);
        int ok=1;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        rep(i,1,n){
            if(A[i]!=B[i]){
                if(A[i]>B[i]) ok=0;
                else a[A[i]-'a'][B[i]-'a']=1;
            }
        }
        int ans=0;
        rep(i,0,20){
            //if(b[i]) continue;
            top=0;q[++top]=i;
            rep(k,i+1,20){
                if(a[i][k]) q[++top]=k,a[i][k]=0;
            }
      //      if(i==0) cout<<top<<endl;
            rep(k,1,top-1){
                if(!a[q[k]][q[k+1]]){
                    a[q[k]][q[k+1]]=1;
                }
            }
        } 
        rep(i,0,20)
        rep(k,0,20) 
        ans+=a[i][k];
        printf("%d\n",ok?ans:-1);
    }
    return 0;
}