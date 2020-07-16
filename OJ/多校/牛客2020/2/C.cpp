#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int maxn=200007;
int head[maxn],to[maxn<<1],nex[maxn<<1],e1;
int cnt,L[maxn],R[maxn],de[maxn];
pii dfs(int u,int fa){
    stack<int> s;
    if(de[u]==1) return mp(u,0);
	for(int i=head[u];i;i=nex[i]){
		int v=to[i];
		if(v!=fa){
            pii x=dfs(v,u);
            if(x.first&&!x.second){
                if(s.size()==2){
                    int y=s.top();s.pop();
                    ++cnt;L[cnt]=y;R[cnt]=x.first;
                }
                else s.push(x.first);
            }
            else if(x.second){
                if(s.size()==0) s.push(x.first),s.push(x.second);
                else if(s.size()==1){
                    int y=s.top();s.pop();
                    ++cnt;L[cnt]=y;R[cnt]=x.first;
                    s.push(x.second);
                }
                else{
                    int y=s.top();s.pop();
                    ++cnt;L[cnt]=y;R[cnt]=x.first;
                    s.push(x.second);
                }
            }
        }
	}
    if(s.size()==0) return mp(0,0);
    else if(s.size()==1) return mp(s.top(),0);
    else {
        int y=s.top();s.pop();
        return mp(y,s.top());
    }
}
void addedge(int u,int v){
	++e1;nex[e1]=head[u];head[u]=e1;to[e1]=v;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int re[maxn];
int main(){
    int n=read();
    if(n==1){
        printf("0");return 0;
    }
    if(n==2){
        printf("1\n1 2");return 0;
    }
    for(int i=1;i<n;i++){
        int u=read(),v=read();
        addedge(u,v);addedge(v,u);
        de[u]++;de[v]++;
    }
    int rt=0;
    for(int i=1;i<=n;i++){
        if(de[i]>1){
            rt=i;break;
        }
    }
    pii z=dfs(rt,0);
    if(z.second){
        ++cnt;L[cnt]=z.first;R[cnt]=z.second;
    }
    else if(z.first){
        ++cnt;
        int x=0;
        for(int i=1;i<=n;i++){
            if(de[i]==1&&i!=z.first){
                x=i;break;
            }
        }
        L[cnt]=z.first;R[cnt]=x;
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++){
        printf("%d %d\n",L[i],R[i]);
    }
	return 0;
}
