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
int A[2200007],B[2200007],C[2200007];
unsigned long long F[2000007];
unordered_map<unsigned,int> aa;
int main(){
    F[1]=1;F[2]=2;
   // aa[1]=1;
   // aa[2]=2;
    for(int i=3;i<=2000001;i++) F[i]=F[i-1]+F[i-2];//aa[F[i]]=i;
    int t=read();
    while(t--){
    //    scanf("%s%s%s",A+1,B+1);
        int lenA=read();
        unsigned long long a=0,b=0,c=0;
  //      for(int i=1;i<=lenA;i++) A[i]=read();
        for(int i=1;i<=lenA;i++){
            if(read()) a+=F[i];
        }
        int lenB=read();
        //for(int i=1;i<=lenB;i++) B[i]=read();
        for(int i=1;i<=lenB;i++){
            if(read()) b+=F[i];
        }
        int lenC=read();
        for(int i=1;i<=lenC;i++){
            C[i]=read();
            if(C[i]) c+=F[i];
        }
        unsigned long long x=a*b-c;
        for(int i=1;i<=lenC;i++){
            if(F[i]==x){
                printf("%d\n",i);break;
            }
        }
      //  unsigned long long a=0,b=0,c=0;
        //cout<<a<<" "<<b<<" "<<endl;
     //   printf("%d\n",aa[a*b-c]);
    }
    return 0;
}