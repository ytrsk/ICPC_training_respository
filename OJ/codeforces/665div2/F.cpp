#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a[1<<19];
ll sum[19][1<<19];int sw[19];
int main(){
    int n=read(),q=read();
    for(int i=0;i<(1<<n);i++){
        a[i]=read();
        for(int k=0;k<19;k++){
            sum[k][i/(1<<k)*(1<<k)]+=a[i];
        }
    }
    for(int i=1;i<=q;i++){
        int op=read();
        if(op==1){
            int x=read(),K=read();x--;
            for(int k=0;k<19;k++) if(sw[k]) x^=(1<<k);
            for(int k=0;k<19;k++){
                (sum[k][x/(1<<k)*(1<<k)]-=a[x])+=K; 
            }
            a[x]=K;
        }
        else if(op==2){
            int x=read();
            for(int i=0;i<=x-1;i++){
                sw[i]^=1;
            }
        }
        else if(op==3){
            sw[read()]^=1; 
        }
        else{
            int now=read(),len=read()-now+1;
            now--;
            ll ans=0;
            while(len){
                for(int i=18;i>=0;i--){
                    if((1<<i)<=len&&now%(1<<i)==0){
                        int x=now;
                     //   printf("query %d %d\n",now,(1<<i));
                        for(int z=i;z<=18;z++){
                            if(sw[z]) x^=(1<<z);
                        }
                   //     printf("update %d %d\n",i,x);
                        ans+=sum[i][x];
                        len-=(1<<i);
                        now+=(1<<i);
                        break;
                    }
                }
            }
            printf("%lld\n",ans);
          //  printf("%lld %lld %lld %lld %lld\n",ans,sum[0][0],sum[0][1],sum[0][2],sum[0][3]);
        }
    }
    return 0;
}
//reverse(k)->(reverse(k-1)->swap(k-1))//(swap(k-1)->reverse(k-1))
//reverse(k)->(swap(0)->swap(1)->...->swap(k-1))
//replace(x,k)->(swap(0))