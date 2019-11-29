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
long long a[maxn],sum[maxn];
pii nex[maxn];

int main(){
    int t=read(),cnt=0;
    while(t--){
        int A=read(),B=read(),n=read();
        for(int i=1;i<=A;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
        int now=0;
        for(int i=1;i<=A;i++){
            if(i>sum[now]) now++;
            nex[i]=make_pair(now,i-sum[now-1]);
        }
        pii last=mp(A,B);
        while(n--){
            if(nex[last.first]==last) break;
            last=nex[last.first];
        }
        //++cnt;
        printf("Case #%d: %d-%d\n",++cnt,last.first,last.second);
    }
    return 0;
}
