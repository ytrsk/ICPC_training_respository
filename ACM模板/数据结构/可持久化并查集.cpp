#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=1000007;
int root[1000007],e1,n,a[1000007],ls[20000007],rs[20000007],val[20000007],fa[20000007],sz[20000007];
void insfa(int &o,int p,int l,int r,int x,int y){
	o=++e1;ls[o]=ls[p];rs[o]=rs[p];fa[o]=fa[p];sz[o]=sz[p];
	int m=(l+r)>>1;
	if(l==r){
		fa[o]=y;return;
	}
	x<=m?insfa(ls[o],ls[p],l,m,x,y):insfa(rs[o],rs[p],m+1,r,x,y);
}
void inssz(int o,int l,int r,int x,int y){
    if(l==r){
        sz[o]=y;return;
    }
    int m=(l+r)>>1;
    x<=m?inssz(ls[o],l,m,x,y):inssz(rs[o],m+1,r,x,y);
}
void build(int &o,int l,int r){
    if(!o) o=++e1;
    if(l==r){
        sz[o]=1;fa[o]=l;return;
    }
    int m=(l+r)>>1;
    build(ls[o],l,m);build(rs[o],m+1,r);
}
int getsz(int o,int l,int r,int x){
    if(l==r) return sz[o];
    int m=(l+r)>>1;
    if(x<=m) return getsz(ls[o],l,m,x);
    else return getsz(rs[o],m+1,r,x);
}
int getfa(int o,int l,int r,int x){
	if(l==r) return fa[o];
	int m=(l+r)>>1;
	if(x<=m) return getfa(ls[o],l,m,x);
	else return getfa(rs[o],m+1,r,x);
}
int find(int o,int x){
    int f=getfa(root[o],1,n,x);
    return f==x?x:find(o,f);
}
void merge(int o,int p,int u,int v){
    int x=find(p,u),y=find(p,v);
    int sx=getsz(root[p],1,n,x),sy=getsz(root[p],1,n,y);
    if(sx>=sy){
        insfa(root[o],root[p],1,n,y,x);
        inssz(root[o],1,n,x,sx+sy);
    }
    else{
        insfa(root[o],root[p],1,n,x,y);
        inssz(root[o],1,n,y,sx+sy);
    }
}
int main(){
    int m;cin>>n>>m;
    build(root[0],1,n);
    for(int i=1;i<=m;i++){
        int opt,x;scanf("%d%d",&opt,&x);
        if(opt==1){
            int y;scanf("%d",&y);
            merge(i,i-1,x,y);
        }
        else if(opt==2){
            root[i]=root[x];
        }
        else{
            root[i]=root[i-1];
            int y;scanf("%d",&y);
            printf("%d\n",find(i,x)==find(i,y));
        }
    }
	return 0;
}
