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
int A[150007],B[40007];
bitset<40001> s[40007],ze,cur;
int idA[150007],idB[40007];
int cmpB(int a,int b){
    return B[a]<B[b];
}
int cmpA(int a,int b){
    return A[a]<A[b];
}
int main(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++) A[i]=read();
    for(int i=1;i<=m;i++) B[i]=read();
    for(int i=1;i<=m;i++) idB[i]=i;
    sort(idB+1,idB+m+1,cmpB);
    for(int i=1;i<=n;i++) idA[i]=i;
    sort(idA+1,idA+n+1,cmpA);
    int now=1;
    s[0]=0;
    for(int i=1;i<=m;i++){
        s[i]=s[i-1];
        s[i].set(idB[i]);
    }
    ze.set(m);int Ans=0;
    for(int i=n;i;i--){
        int l=0,r=m,ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(B[idB[mid]]<=A[i]) ans=mid,l=mid+1;
            else r=mid-1; 
        }
        cur=((cur>>1)|ze)&s[ans];
        if(cur[1]==1) Ans++;
    }
    cout<<Ans;
    return 0;
}