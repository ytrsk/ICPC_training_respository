#include <stdio.h>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
const int maxn=800007;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
    int n,m;
    while(1){
        n=read();m=read();
        if(n==0&&m==0) return 0;
        int sum=0;
        for(int i=1;i<=n;i++){
            char s[20];scanf("%s",s+1);
            int x=read();
            sum+=x;
        }
        //3*x+2*y=sum
        //x+y=m
        //3*m-sum
        printf("%d\n",3*m-sum);
    }
    return 0;
}
