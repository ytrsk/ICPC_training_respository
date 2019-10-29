#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=29;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
struct bignum{
    int shu[maxn];int len;
    bignum(){
        memset(shu,0,sizeof(shu));
    }
    bignum operator < (bignum a){
        if(len!=a.len) return len<a.len;
        for(int i=a.len;i;i--) if(shu[i]!=a.shu[i]) return shu[i]<a.shu[i];
        return false;
    }
    bignum operator > (bignum a){
        return a<*this;
    }
    bignum operator * (bignum a){
        bignum new1;
        for(int i=1;i<=len;i++)
        for(int k=1;k<=a.len;k++){

        }
    }
    bignum operator + (bignum a){


};
int main(){
    int t=read();
    while(t--){
        int
    }

    return 0;
}
