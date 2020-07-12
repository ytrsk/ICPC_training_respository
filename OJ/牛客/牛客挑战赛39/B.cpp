#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=2000007;
char s[maxn];
int sa[2][maxn],rk[2][maxn],now,bit,n,a[maxn],h[maxn],v[maxn],l1;
void solve(int sa[],int rk[],int SA[],int RK[]){
	for(int i=1;i<=n;i++) v[rk[sa[i]]]=i;
	for(int i=n;i;i--) if(sa[i]>l1) SA[v[rk[sa[i]-l1]]--]=sa[i]-l1;
	for(int i=n-l1+1;i<=n;i++) SA[v[rk[i]]--]=i;
	for(int i=1;i<=n;i++) RK[SA[i]]=RK[SA[i-1]]+(rk[SA[i]]!=rk[SA[i-1]]||rk[SA[i]+l1]!=rk[SA[i-1]+l1]);
}
void getsa(){
	now=0;
	for(int i=1;i<=n;i++) v[a[i]]++;
	for(int i=1;i<=30;i++) v[i]+=v[i-1];
	for(int i=1;i<=n;i++) sa[now][v[a[i]]--]=i;
	for(int i=1;i<=n;i++) rk[now][sa[now][i]]=rk[now][sa[now][i-1]]+(a[sa[now][i]]!=a[sa[now][i-1]]);
    for(l1=1;l1<n;l1<<=1){
		solve(sa[now],rk[now],sa[now^1],rk[now^1]);now^=1;
	}
}
void geth(){
	l1=0;
	for(int i=1;i<=n;i++)
    if(rk[now][i]==1) h[rk[now][i]]=0;
    else{
        int last=sa[now][rk[now][i]-1];
        while(l1<=min(n-i,n-last)&&a[i+l1]==a[last+l1]) l1++;
        h[rk[now][i]]=l1;if(l1>0) l1--;
    }
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int st[maxn],top;
int Pos[maxn];
int vis[maxn];
int main(){
    int len=read(),K=read();K=len/K;
	scanf("%s",s+1);n=2*len;
    for(int i=len+1;i<=n;i++) s[i]=s[i-len];
	for(int i=1;i<=n;i++) a[i]=s[i]-'a'+1;
	getsa();geth();
    for(int i=1;i<=n;i++){
        if(sa[now][i]<=len) st[++top]=sa[now][i],Pos[sa[now][i]]=top;
    }
    int l=1,r=len,ans=-1;
    while(l<=r){
        int mid=(l+r)>>1;
        for(int i=1;i<=len/K;i++) vis[i]=0;
        for(int i=1;i<=len;i++){
            if(Pos[i]>mid){
                vis[(i-1)%(len/K)+1]=1;
            }
        }
        int ok=0;
        for(int i=1;i<=len/K;i++) if(!vis[i]) ok=1;
        if(ok) r=mid-1,ans=mid;
        else l=mid+1;
    }
    for(int i=st[ans];i<=st[ans]+len/K-1;i++){
        printf("%c",s[i]);
    }
	return 0;
}
