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
int fa[maxn];
int top,q[maxn];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int val[maxn];
ll dp[13][13][13][13];
int main(){
    int a=read(),b=read(),c=read(),d=read(),n=read();
    for(int i=1;i<=12;i++) fa[i]=i;
    for(int i=1;i<=n;i++){
        int x=read(),y=read();
        fa[find(x)]=find(y);
    }
    for(int i=1;i<=12;i++) val[find(i)]++;
    for(int i=1;i<=12;i++){
        if(find(i)==i) q[++top]=val[i];
    }
    dp[0][0][0][0]=1;
    for(int i=1;i<=top;i++){
       for(int A=a;~A;--A)
       for(int B=b;~B;--B)
       for(int C=c;~C;--C)
       for(int D=d;~D;--D){
           if(A>=q[i]) dp[A][B][C][D]+=dp[A-q[i]][B][C][D];
           if(B>=q[i]) dp[A][B][C][D]+=dp[A][B-q[i]][C][D];
           if(C>=q[i]) dp[A][B][C][D]+=dp[A][B][C-q[i]][D];
           if(D>=q[i]) dp[A][B][C][D]+=dp[A][B][C][D-q[i]];
       }
    }
    cout<<dp[a][b][c][d];
    return 0;
}