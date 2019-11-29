#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
const int mod=1e9+7;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct matrix{
	int n,m;ll shu[107][107];
	matrix(){
		memset(shu,0,sizeof(shu));
	}
	matrix operator * (matrix a){
		matrix new1;new1.n=n;new1.m=a.m;
		for(int i=1;i<=n;i++)
		for(int k=1;k<=a.m;k++)
		for(int z=1;z<=m;z++)
		new1.shu[i][k]+=shu[i][z]*a.shu[z][k],new1.shu[i][k]%=mod;
		return new1;
	}
	matrix operator + (matrix a){
		matrix new1;new1.n=n;new1.m=m;
		for(int i=1;i<=n;i++)
		for(int k=1;k<=m;k++){
			new1.shu[i][k]=(shu[i][k]+a.shu[i][k])%mod;
		}
		return new1;
	}
	void print(){
		for(int i=1;i<=n;i++){
			for(int k=1;k<=m;k++){
				printf("%lld ",shu[i][k]);
			}
			printf("\n");
		}
	}
	void eye(){
		for(int i=1;i<=n;i++) shu[i][i]=1;
	}
};
matrix powmat(matrix a,int b){
	matrix ans;ans.n=ans.m=a.n;ans.eye();
	while(b){
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int len,num[maxn];
void solve(int x){
    int m=0,d=1,a=(int)sqrt(x);num[0]=a;
    while(1){
        long long nm=1LL*d*num[len]-m;
        long long nd=(x-nm*nm)/d;
        num[++len]=(num[0]+nm)/nd;
        if(num[len]==2*a) break;
        else if(num[len]==0){
            len--;break;
        }
        m=nm;d=nd;
    }
}
int main(){
    int n=read(),m=read();
    solve(n);
    matrix now;
    now.n=2;now.m=2;
    now.shu[1][1]=(int)sqrt(n);now.shu[1][2]=1;
    now.shu[2][1]=1;now.shu[2][2]=0;
    matrix pre;pre.n=pre.m=2;pre.eye();
    for(int i=1;i<=len;i++){
        matrix x;x.n=x.m=2;
        x.shu[1][1]=num[i];x.shu[2][1]=1;
        x.shu[1][2]=1;
        pre=pre*x;
    }
    pre=powmat(pre,m/len);
    now=now*pre;
    for(int i=1;i<=m%len;i++){
        matrix x;x.n=x.m=2;
        x.shu[1][1]=num[i];x.shu[2][1]=1;
        x.shu[1][2]=1;
        now=now*x;
    }
    printf("%lld/%lld",now.shu[1][1],now.shu[2][1]);
    return 0;
}