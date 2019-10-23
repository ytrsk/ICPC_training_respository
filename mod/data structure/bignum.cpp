#include <stdio.h>
#include <string.h>
#include <algorithm>
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
int main(){
	return 0;
}
