#include <bits/stdc++.h>
#define mp make_pair
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
int a[maxn];
int top,q[maxn];
int main(){
    int t=read();
    while(t--){
        long long sum=0;
        int n=read();top=0;
        for(int i=1;i<=n;i++){
            a[i]=read();
            if(i-1&&a[i]-a[i-1]>1) q[++top]=a[i]-a[i-1]-1,sum+=q[top];
        }
        if(top==0) printf("0\n");
        else{
            if(a[2]-a[1]==1||a[n]-a[n-1]==1) printf("%lld\n",sum);
            else printf("%lld\n",sum-min(q[1],q[top]));
        }
    }
    return 0;
}
