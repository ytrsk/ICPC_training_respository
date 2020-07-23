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
int a[507][507],d[507][507],n;
int dis(int a,int b,int x,int y){
    int A=abs(a-x),B=abs(b-y);
    if(A>B) swap(A,B);
    return min(A,B)+(A==B?0:(B-A-1)/2+1);
}
int check(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=n;
}
int q[507];
int main(){
    int t=read();
    while(t--){
        n=read();int x0=read(),y0=read();
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                a[i][k]=read();
                d[i][k]=dis(x0,y0,i,k);
            }
        }
        int mn=inf;
        for(int i=1;i<=n;i++)
        for(int k=1;k<=n;k++){
            int top=0;
            for(int z=-3;z<=3;z++)
            for(int r=-3;r<=3;r++){
                if(check(i+z,r+k)&&abs(z)+abs(r)<=3&&abs(z)+abs(r)!=0)
                q[++top]=a[i+z][r+k];
            }
            sort(q+1,q+top+1);
            int val=a[i][k];
            int f=0,tot=0;
            for(int z=1;z<=8;z++){
                if(z-1<=top&&z>=2){
                    val+=q[top-(z-1)+1];
                }
                int now=(8*z*z-f-1)/val+1;
                tot+=now;
                f+=now*val;
            }
            mn=min(mn,tot+d[i][k]);
        }
        printf("%d\n",mn);
    }
    return 0;
}