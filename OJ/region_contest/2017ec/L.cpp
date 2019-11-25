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
int pre[20],n;
struct node{
    int a[18];
    void decode(int x){
        for(int i=0;i<n;i++) a[i]=(x/pre[i])%3;
    }
    int encode(){
        int x=0;
        for(int i=0;i<n;i++) x+=a[i]*pre[i];
        return x;
    }
    node operator = (int x){
        this->decode(x);
        return *this;
    }
    bool check(){
        for(int i=0;i<n-2;i++){
            if(a[i]==2&&a[i+1]==1&&a[i+2]==2) return true;
        }
        return false;
    }
    int suan(){
        int x=0;
        for(int i=0;i<n;i++) if(a[i]) x++;
        return x;
    }
    void print(){
        for(int i=0;i<n;i++) printf("%d ",a[i]);
        printf("\n");
    }
};
int main(){
    int t=read();
    int cnt=0;
    while(t--){
        ++cnt;
        int n=read();
        if(n<7||n%2==0&&n<16) printf("Case #%d: Draw\n",cnt);
        else if(n%2) printf("Case #%d: Panda\n",cnt);
        else printf("Case #%d: Sheep\n",cnt);
    }
    return 0;
}
