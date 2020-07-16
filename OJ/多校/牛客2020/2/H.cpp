#include <stdio.h>
#include <algorithm>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int maxn=8000007;
const int inf=1e9+7; 
int rt,e1,sz[maxn],ls[maxn],rs[maxn],cnt[maxn],val[maxn];
int mn[maxn],mx[maxn];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
void pushup(int o){
	sz[o]=sz[ls[o]]+sz[rs[o]];
    val[o]=min(val[ls[o]],val[rs[o]]);
    mn[o]=min(mn[ls[o]],mn[rs[o]]);
    mx[o]=max(mx[ls[o]],mx[rs[o]]);
}
int find_Cnt(int o,int l,int r,int x){
    if(l==r) return cnt[o];
    int mid=(l+r)>>1;
    if(x<=mid) return find_Cnt(ls[o],l,mid,x);
    else return find_Cnt(rs[o],mid+1,r,x);
}
int find_Pre(int o,int l,int r,int x){
    if(!sz[o]||x<l) return 0;
    if(l==r) return cnt[o]?l:0;
    int mid=(l+r)>>1;
    if(x<=mid) return find_Pre(ls[o],l,mid,x);
    else{
        int v=find_Pre(rs[o],mid+1,r,x);
        return v?v:mx[ls[o]];
    }
}
int find_Sub(int o,int l,int r,int x){
    if(!sz[o]||x>r) return inf;
    if(l==r) return cnt[o]?l:inf;
    int mid=(l+r)>>1;
    if(x<=mid){
        int v=find_Sub(ls[o],l,mid,x);
        return v==inf?mn[rs[o]]:v;
    }
    else return find_Sub(rs[o],mid+1,r,x);
}
void ins(int &o,int l,int r,int x,int y){
    if(!o) o=++e1;
    if(l==r){
        cnt[o]++;sz[o]=cnt[o];
        mx[o]=mn[o]=l;
        if(cnt[o]==1) val[o]=y;
        else val[o]=0;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) ins(ls[o],l,mid,x,y);
    else ins(rs[o],mid+1,r,x,y);
    pushup(o);
}
int del(int &o,int l,int r,int x,int y){
    if(l==r){
        cnt[o]--;sz[o]=cnt[o];
        if(cnt[o]==0) mn[o]=inf,mx[o]=0,val[o]=inf;
        else if(cnt[o]==1) val[o]=y;
        return cnt[o];
    }
    int mid=(l+r)>>1,z;
    if(x<=mid) z=del(ls[o],l,mid,x,y);
    else z=del(rs[o],mid+1,r,x,y);
    pushup(o);
    return z;
}
void change(int o,int l,int r,int x,int y){
    if(l==r){
        if(cnt[o]==1) val[o]=y;return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) change(ls[o],l,mid,x,y);
    else change(rs[o],mid+1,r,x,y);
    pushup(o);
}
int query(int o,int l,int r,int x){
    if(!o) return inf;
    if(l==r) return x>l?inf:val[o];
    int mid=(l+r)>>1;
    if(x<=mid) return min(val[rs[o]],query(ls[o],l,mid,x));
    else return query(rs[o],mid+1,r,x);
}
int main(){
    mn[0]=val[0]=inf;
    int q=read();
    while(q--){
        int op=read(),x=read();
        if(op==1){
            int a=find_Pre(rt,1,1e9,x-1);
            int b=find_Sub(rt,1,1e9,x+1);
            if(a) ins(rt,1,1e9,x,x-a);
            else ins(rt,1,1e9,x,inf);
            if(b^inf) change(rt,1,1e9,b,b-x);
        }
        else if(op==2){
            int a=find_Pre(rt,1,1e9,x-1),c=del(rt,1,1e9,x,a?x-a:inf);
            if(!c){
                int b=find_Sub(rt,1,1e9,x+1);
                if(b^inf){
                    change(rt,1,1e9,b,a?b-a:inf);
                }
            }
        }
        else if(op==3){
            int ok=0,a1=find_Pre(rt,1,1e9,x),a2=0;
            if(a1){
                if(find_Cnt(rt,1,1e9,a1)>=2){
                    ok|=(2*a1>x);
                }
                else {
                    a2=find_Pre(rt,1,1e9,a1-1);
                    if(a2) ok|=(a1+a2>x);
                }
            }
            int v=query(rt,1,1e9,x);
            ok|=(x>v);
            if(ok) printf("Yes\n");
            else printf("No\n");
        }
    }
	return 0;
}
