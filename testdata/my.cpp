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
    int t=clock();
    vector<int> r(4,1);cout<<r[2]<<endl;
    r.resize(0);r.resize(5);
    cout<<r[2]<<endl;
    printf("time: %.6f s\n",(clock()-t)/1000.0);
    return 0;
}