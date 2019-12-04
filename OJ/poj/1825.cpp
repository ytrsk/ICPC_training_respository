#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
const int maxn=100007;
struct bignum{
	int shu[maxn];int len;
	bignum(){
		memset(shu,0,sizeof(shu));
	}
	bignum operator = (int a){
		char b[30];sprintf(b+1,"%d",a);
		return *this=b;
	}
	bool operator < (bignum a) const {
		if(len!=a.len) return len<a.len;
		for(int i=a.len;i;i--) if(shu[i]!=a.shu[i]) return shu[i]<a.shu[i];
		return false;
	}
	bool operator == (bignum a) const{
		if(len!=a.len) return false;
		for(int i=a.len;i;i--) if(shu[i]!=a.shu[i]) return false;
		return true;
	}
	bignum operator = (char *a){
		len=strlen(a+1);for(int i=1;a[i]=='0';i++) len--;
		for(int i=1;i<=len;i++) shu[i]=a[len-i+1]-'0';
		return *this;
	}
	bool operator > (bignum a) const{
		return a<*this;
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
	bignum operator + (bignum a){
		int lm=max(len,a.len);bignum new1;
		for(int i=1;i<=lm;i++){
			new1.shu[i]=shu[i]+a.shu[i];
		}
		new1.len=lm;
		new1.move();
		return new1;
	}
	bignum operator * (bignum a){
		bignum new1;
		for(int i=1;i<=len;i++)
		for(int k=1;k<=a.len;k++)
		new1.shu[i+k-1]+=shu[i]*a.shu[k];
		new1.len=len+a.len-1;
		new1.move();
		return new1;
    }
	void print(){
		for(int i=len;i;i--) printf("%d",shu[i]);
		printf("\n");
	}
};
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int a[23],val[1007];
void add(int x,int y){
    int len=(int)sqrt(x+0.5);
    for(int i=2;i<=len;i++){
        if(x%i==0){
            while(x%i==0) val[i]+=y,x/=i;
        }
    }
    if(x!=1) val[x]+=y;
}
int you[1007];
int main(){
    int n=read(),tot=0;
    for(int i=1;i<=n;i++){
        a[i]=read();tot+=a[i];
    }
    for(int i=1;i<=tot;i++) add(i,1); 
    for(int i=n;i;i--){
        for(int k=1;k<=a[i];k++){
            add(a[i]-k+you[k]+1,-1);
            you[k]++;
        }
    }
    bignum now;now=1;
    for(int i=2;i<=tot;i++){
        bignum th;th=i;
        while(val[i]--) now=now*th;
    }
    now.print();
	return 0;
}
