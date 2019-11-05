#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[maxn],pos[maxn];
int vis[maxn];
int f(int pos,int a,int p){
    if(p<=pos) return 2*a-(pos-p);
    else return 2*a-(p-pos);
}
int main(){
    int n;
    while((n=read())&&n){
        for(int i=1;i<=n;i++){
            a[i]=read();
            if(i==1){
                pos[i]=a[i];
            }
            else{
                int mn=0;
                for(int k=1;k<i;k++){
                    if(a[i]==a[k]) mn=max(mn,pos[k]+2*a[i]);
                    else if(a[i]>a[k]){
                        mn=max(mn,pos[k]+2*a[k]);
                    }
                    else{
                        mn=max(mn,pos[k]+2*a[i]);
                    }
                }
                pos[i]=mn;
            }
        }
        for(int i=1;i<=n;i++){
            vis[i]=0;
            for(int k=pos[i]-a[i];k<pos[i]+a[i];k++){
                int x=1;
                for(int z=1;z<=n;z++){
                    if(z==i) continue;
                    if(!(k>=pos[z]-a[z]&&k<pos[z]+a[z])) continue;
                    if(k<pos[i]&&f(pos[i],a[i],k)<f(pos[z],a[z],k)) x=0;
                    if(k>=pos[i]&&f(pos[i],a[i],k)<=f(pos[z],a[z],k)) x=0;
                }
                if(x==1) vis[i]=1;
            }
            if(vis[i]) printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}
