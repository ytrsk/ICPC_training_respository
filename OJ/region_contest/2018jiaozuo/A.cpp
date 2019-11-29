#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const int inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int main(){
    int t=read();
    while(t--){
        int a=read(),b=read(),c=read(),d=read();
        int x=0;if(a) x++;if(b) x++;if(c) x++;if(d) x++;
        if(x==0) printf("Typically Otaku\n");
        else if(x==1) printf("Eye-opener\n");
        else if(x==2) printf("Young Traveller\n");
        else if(x==3) printf("Excellent Traveller\n");
        else printf("Contemporary Xu Xiake\n");
    }

    return 0;
}
