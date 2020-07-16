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
int a[1<<24];
int limit,now;
void op(int o){
    int left=o*2<=limit?a[o<<1]:0,right=o*2+1<=limit?a[o<<1|1]:0;
    if(left==right&&left==0){
        a[o]=0;return; 
    }
    else{
        if(left>right){
            a[o]=left;op(o<<1);
        }
        else{
            a[o]=right;op(o<<1|1);
        }
    }
}
int q[1<<24],top;
void print(){
    for(int i=1;i<=limit;i++) printf("%d ",a[i]);
    printf("\n");
}
void dfs(int o,int ti){
    if(!ti) return;
    if(ti==1){
        op(o);q[++top]=o;return;
    }
    int x=ti/2;
    int l=0,r=0;
    while(ti){
        if(a[o<<1]>a[o<<1|1]){
            if(l==x) break;
            l++;op(o);ti--;q[++top]=o;
        }
        else {
            if(r==x) break;
            r++,op(o),ti--;q[++top]=o;
        }
    }
    dfs(o<<1,x-l);dfs(o<<1|1,x-r);
}
int main(){
    int t=read();
    while(t--){
        int h=read(),g=read();now=(1<<g)-1;limit=(1<<h)-1;
        for(int i=1;i<(1<<h);i++) a[i]=read();top=0;
        dfs(1,limit-now);
        int sum=0;
        for(int i=1;i<(1<<g);i++) sum+=a[i];
        printf("%d\n",sum);
        for(int i=1;i<=top;i++)
        printf("%d ",q[i]);
        cout<<"\n";
    }
    return 0;
}