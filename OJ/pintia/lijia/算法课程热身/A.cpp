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
int main(){
    int a=read(),b=read();
    for(int i=1;i<=4;i++){
        cout<<a<<" ";
        if(i==1) cout<<"+";
        else if(i==2) cout<<"-";
        else if(i==3) cout<<"*";
        else cout<<"/";
        cout<<" "<<b;
        cout<<" = ";
        if(i==1) cout<<a+b;
        else if(i==2) cout<<a-b;
        else if(i==3) cout<<a*b;
        else cout<<a/b;
        if(i<4) cout<<"\n";
    }
    return 0;
}