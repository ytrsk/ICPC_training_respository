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
int c[1007][1007],sum[1007][1007];
int find(int x,int y){
    while(1){
        for(int i=0;i<=x;i++){
            if(sum[x][i]==y){
                printf("%d %d\n",x,i);
                return 0;
            }
        }
        x++;y--;
    }
}
int A[37];
int main(){
    int t=read(),cnt=0;
    while(t--){
        int n=read(),h=0;
        for(int i=1;i<=40;i++){
            if(n<(1LL<<i)+i){
                h=i;break;
            }
        }
        int a=n-h;
        printf("Case #%d:\n",++cnt);
        int sum=0;
        for(int i=1;i<=h;i++){
            if(a>>(i-1)&1) sum++,A[i]=1;
            else A[i]=0;

        }
        int nx=1,ny=1,pos=0;
        printf("1 1\n");
        for(int i=2;i<=h;i++){
            if(pos){
                if(A[i]==1){
                    for(int k=i;k;k--){
                        printf("%d %d\n",i,k);
                    }
                    pos=0;
                }
                else printf("%d %d\n",i,i);
            }
            else{
                if(A[i]==1){
                    for(int k=1;k<=i;k++){
                        printf("%d %d\n",i,k);
                    }
                    pos=1;
                }
                else printf("%d 1\n",i);
            }
        }
        if(!pos){
            for(int i=1;i<=sum;i++){
                printf("%d %d\n",h+i,1);
            }
        }
        else{
            for(int i=1;i<=sum;i++){
                printf("%d %d\n",h+i,h+i);
            }
        }
    }
    return 0;
}