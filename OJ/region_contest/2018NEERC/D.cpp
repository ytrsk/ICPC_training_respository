#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=200007;
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
int a[maxn];
map<int,int> aa[200007];
int mu[10000007],phi[10000007];
int len,p[2000007],N=10000000;
int now,NN;int num[10000007];
int top,Num[307],you[307];
int nowx,nowy;
bool dfs(int o,int x){
    if(o==nowx+1){
        aa[now][NN]=x;
        if((++now)>nowy) return true;
        else return false;
    }
    for(int i=0;i<=you[o];i++){
        if(dfs(o+1,x)) return true;
        x*=Num[o];
    }
    return false;
}

int main(){
    mu[1]=1;phi[1]=1;
	for(int i=2;i<=N;i++){
		if(!phi[i]) p[++len]=i,mu[i]=i,phi[i]=i-1;
		for(int k=1;k<=len&&i*p[k]<=N;k++){
			if(i%p[k]!=0) phi[i*p[k]]=phi[i]*phi[p[k]],mu[i*p[k]]=min(mu[i],p[k]);
			else {phi[i*p[k]]=phi[i]*p[k],mu[i*p[k]]=min(mu[i],p[k]);break;}
		}
	}
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read(),num[a[i]]++;
    int ok=1;
    for(int i=1;i<=10000000;i++){
        if(num[i]){
            int x=i;top=0;  
            while(x!=1){
                if(!top) Num[++top]=mu[x],you[top]=1;
                else{
                    if(mu[x]!=Num[top]) Num[++top]=mu[x],you[top]=1;
                    else you[top]++;
                }
                x/=mu[x];
            }
            nowx=top,nowy=num[i];now=1;NN=i;
            ok&=dfs(1,1);
            num[i]=0;
        }
    }
    if(!ok){
        printf("NO");return 0;
    }
    else printf("YES\n");
    for(int i=1;i<=n;i++){
        num[a[i]]++;
        printf("%d %d\n",aa[num[a[i]]][a[i]],a[i]/aa[num[a[i]]][a[i]]);
    }
    return 0;
}