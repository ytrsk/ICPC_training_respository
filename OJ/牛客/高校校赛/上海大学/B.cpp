#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
string a[maxn];
int b[maxn];
double c[maxn];
int id[maxn];
int cmp(int x,int y){
    if(a[x]!=a[y]) return a[x]>a[y];
    else if(c[x]!=c[y]) return c[x]>=c[y];
    else return b[x]<b[y];
}
int main(){
    int n=read(),cnt=0;
    for(int i=1;i<=n;i++){
        id[i]=i;
        cin>>a[i];b[i]=read();
        scanf("%lf",&c[i]);
        if(c[i]>=38.0) cnt++;
    }
    printf("%d\n",cnt);
    sort(id+1,id+n+1,cmp);
    for(int i=1;i<=n;i++){
        if(c[id[i]]>=38.0){
            cout<<a[id[i]]<<" "<<b[id[i]]<<" ";
            printf("%.1f\n",c[id[i]]);
        }
    }
    return 0;
}