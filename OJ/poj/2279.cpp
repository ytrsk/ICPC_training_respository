#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;
const int maxn=100007;
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
    int n;
    while(n=read()){
        int tot=0;
        for(int i=1;i<=n;i++){
            a[i]=read();tot+=a[i];
        }
        for(int i=1;i<=tot;i++) you[i]=val[i]=0;
        for(int i=1;i<=tot;i++) add(i,1); 
        for(int i=n;i;i--){
            for(int k=1;k<=a[i];k++){
                add(a[i]-k+you[k]+1,-1);
                you[k]++;
            }
        }
        unsigned long long ans=1;
        for(int i=2;i<=tot;i++){
            while(val[i]--) ans=ans*i;
        }
        cout<<ans<<"\n";
    }
	return 0;
}
