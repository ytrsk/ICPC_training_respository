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
    int shu[70];int len;
    bignum(){
        memset(shu,0,sizeof(shu));
    }
    bool operator < (bignum a) const{
        if(len!=a.len) return len<a.len;
        for(int i=a.len;i;i--) if(shu[i]!=a.shu[i]) return shu[i]<a.shu[i];
        return false;
    }
    bool operator > (bignum a) const{
        return a<*this;
    }
    bignum operator * (bignum a){
        bignum new1;
        for(int i=1;i<=len;i++)
        for(int k=1;k<=a.len;k++){
            new1.shu[i+k-1]+=shu[i]*a.shu[k];
        }
        new1.len=len+a.len-1;
        new1.move();
        return new1;
    }
    void move(){
        for(int i=1;i<=len;i++){
            if(shu[i]>9){
                if(i==len){
                    shu[++len]=shu[i]/10;
                    shu[i]%=10;
                }
                else shu[i+1]+=shu[i]/10,shu[i]%=10;
            }
        }

    }
    bignum operator = (char *a){
        len=strlen(a+1);for(int i=1;a[i]=='0';i++) len--;
        for(int i=1;i<=len;i++) shu[i]=a[len-i+1]-'0';
        return *this;
    }
    void check(){
        for(int i=1;i<=len;i++){
            if(shu[i]<0){
                shu[i]+=10;shu[i+1]--;
            }
        }
        while(len-1&&!shu[len]) len--;
    }
    bignum operator = (int a){
        char b[30];sprintf(b+1,"%d",a);
        return *this=b;
    }
    bignum operator - (bignum a){
        bignum new1;
        new1.len=len;
        for(int i=1;i<=len;i++) new1.shu[i]=shu[i]-a.shu[i];
        new1.check();
        return new1;
    }
    void print(){
        for(int i=len;i;i--) printf("%d",shu[i]);
        printf("\n");
    }
};
char s[200007];
bignum four;
int main(){
    four=4;
    int t=read();
    while(t--){
        scanf("%s",s+1);
        bignum now;now=s;
        bignum a,b;a=4;b=14;
        if(!(now>a)){
            a.print();
        }
        else if(!(now>b)){
            b.print();
        }
        else{

            while(now>b){
                bignum t=a;
                a=b;
                b=four*b-t;
            }
            b.print();
        }
    }

    return 0;
}
