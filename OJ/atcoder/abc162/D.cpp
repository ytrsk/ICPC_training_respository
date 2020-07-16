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
int a[maxn];
char s[maxn];
int pre[maxn][4];
int main(){
    int n=read();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='R') a[i]=1;
        else if(s[i]=='G') a[i]=2;
        else if(s[i]=='B') a[i]=3;
        pre[i][a[i]]++;
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=3;k++)
        pre[i][k]+=pre[i-1][k];
    }
    ll sum=0;
    for(int i=1;i<=n;i++){
        for(int k=i+2;k<=n;k++){
            int x=a[i],y=a[k];
            if(x^y){
                int z=6-x-y;
                sum+=pre[k][z]-pre[i][z];
                if((k-i)%2==0){
                    if(a[(k+i)/2]==z) sum--;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}