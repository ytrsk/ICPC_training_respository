#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn=10007;
int ans,from[maxn],a[maxn],fa[maxn],head[maxn],to[maxn],nex[maxn],e1,w[maxn];
void addedge(int u,int v,int x){
	to[++e1]=v;from[e1]=u;nex[e1]=head[u];head[u]=e1;w[e1]=x;
}
bool cmp(int x,int y){
	return w[x]<w[y];
}
int find(int x){
	if(fa[x]==x) return x;
	else fa[x]=find(fa[x]);
}
void kruscal(){
	for(int i=1;i<=e1;i++) a[i]=i;
	sort(a+1,a+e1+1,cmp);
	for(int i=1;i<=e1;i++){
		int x=find(from[i]),y=find(to[i]);
		if(x!=y){
			fa[x]=y;ans+=w[i];
		}
	}
}
int main(){
	return 0;
}
