#include <stdio.h>
#include <iostream>
using namespace std;
#define mp make_pair
#define sqr(x) (x)*(x)
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
int c[1007][1007];
int main(){
    int t=read();
    c[0][0]=1;
    for(int i=1;i<=13;i++)
    for(int k=1;k<=i;k++){
        c[i][k]=(c[i-1][k-1]+k*c[i-1][k])%2;
    }
    while(t--){
        int n=read(),m=read();
        if(m==0&&n||m>n) printf("0\n");
        else if(!m&&!n) printf("1\n");
        else{
            int x=n-m+m-m/2-1,y=m-m/2-1;
            int ok=1;
            while(x||y){
              //  cout<<"asd"<<endl;
                if(x%2<y%2) ok=0;
                x/=2;y/=2;
            }
            printf("%d\n",ok);
        }
    }
    return 0;
}