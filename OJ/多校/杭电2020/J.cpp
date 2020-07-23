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
struct node{
    ll p,a,id;
    bool operator < (node x){
        if(p^x.p) return p<x.p;
        else return a<x.a;
    }
}nd[maxn],Q[maxn];
int top,q[maxn],Top,tag[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();top=0;
        for(int i=1;i<=n;i++)
        nd[i].p=read(),nd[i].a=read(),nd[i].id=i;
        sort(nd+1,nd+n+1);
        for(int i=1;i<=n;i++){
            int ok=1;
            if(i-1&&nd[i].a==nd[i-1].a&&nd[i].p==nd[i-1].p||i<n&&nd[i+1].a==nd[i].a&&nd[i+1].p==nd[i].p)
            ok=0;
            while(top&&(nd[i].a>=nd[q[top]].a)){top--;}
            q[++top]=i;
            if(ok) tag[nd[i].id]=1;
            else tag[nd[i].id]=0;
        }
        Top=0;
        for(int i=1;i<=top;i++){
            node now=nd[q[i]];
            while(Top>=2&&(__int128)1*(now.a-Q[Top].a)*(Q[Top].p-Q[Top-1].p)>=(__int128)1*(Q[Top].a-Q[Top-1].a)*
            (now.p-Q[Top].p)) Top--;
            Q[++Top]=now;
        }
        int cnt=0;
        for(int i=1;i<=Top;i++) if(tag[Q[i].id]) cnt++;
        printf("%d\n",cnt);    
    }
    return 0;
}