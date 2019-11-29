#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=1000007;
const int inf=(1LL<<29);
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
char s[4007][6009];
int r,c;
pii ce[1007][1007];
vector<int> g[maxn];
void addedge(int u,int v){
    g[u].push_back(v);
}
void check(int x1,int y1,int x2,int y2){
    if(s[(ce[x1][y1].first+ce[x2][y2].first)/2][(ce[x1][y1].second+ce[x2][y2].second)/2]==' '){
        addedge((x1-1)*c+y1,(x2-1)*c+y2);
        addedge((x2-1)*c+y2,(x1-1)*c+y1);
    //    printf("%d %d %d %d\n",x1,y1,x2,y2);
    }
}
int vis[1007*1007];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int t=read();
    while(t--){
        r=read(),c=read();
        for(int i=1;i<=4*r+3;i++){
            gets(s[i]+1);
        }
        pii ss,t;
        for(int i=1;i<=r;i++){
            for(int k=1;k<=c;k++){
                //3+4*(i-1),5+6*(k-1)
                pii to=mp(i,k);
                if(k%2==0){
                    //pii to=mp(5+4*(i-1),5+6*(k-1));
                    if(s[5+4*(i-1)][5+6*(k-1)]=='S'){
                        ss=to;
                    }
                    else if(s[5+4*(i-1)][5+6*(k-1)]=='T'){
                        t=to;
                    }
                    ce[i][k]=mp(4*i+1,6*k-1);
                }
                else{
                    //pii to=mp(3+4*(i-1),5+6*(k-1));
                    if(s[3+4*(i-1)][5+6*(k-1)]=='S'){
                        ss=to;
                    }
                    else if(s[3+4*(i-1)][5+6*(k-1)]=='T'){
                        t=to;
                    }
                    ce[i][k]=mp(4*i-1,6*k-1);
                }
            }
        }
        for(int i=1;i<=r*c;i++)
            g[i].clear(),vis[i]=0;
        for(int i=1;i<=r;i++)
        for(int k=1;k<=c;k++){
            if(i!=r){
                check(i,k,i+1,k);
            }

            if(k<c){
                check(i,k,i,k+1);
                if(k%2){
                    if(i>1) check(i,k,i-1,k+1);
                }
                else{
                    if(i<r) check(i,k,i+1,k+1);
                }
            }
        }
        queue<int> q;
        q.push((ss.first-1)*c+ss.second);
        vis[(ss.first-1)*c+ss.second]=1;
        while(!q.empty()){
            int u=q.front();q.pop();
            if(u==(t.first-1)*c+t.second) break;
            for(int i=0;i<g[u].size();i++){
                int v=g[u][i];
                if(!vis[v]){
                    vis[v]=vis[u]+1;
                    q.push(v);
                }
            }
        }
      /*  for(int i=1;i<=r;i++){
            for(int k=1;k<=c;k++)
            printf("%d ",vis[(i-1)*c+k]);
            printf("\n");
        }*/
        if(vis[(t.first-1)*c+t.second]) printf("%d\n",vis[(t.first-1)*c+t.second]);
        else printf("-1\n");
    }
    return 0;
}
