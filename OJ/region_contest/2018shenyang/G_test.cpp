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
vector<pair<int,int>> you[10000007];
long long val[6007][6007];
bool check(int x,int y){
    return x>=1&&x<=6000&&y>=1&&y<=6000&&val[x][y]!=-1;
}
unordered_map<long long,int> aa;
int main(){
    for(register int i=0;i<=3400;i++)
    for(register int k=i;k<=3400;k++){
        if(i*i+k*k<=10000000) you[i*i+k*k].push_back(make_pair(i,k));
    }
    int cnt=0;
    int t=read();
    memset(val,-1,sizeof(val));
    while(t--){
        ++cnt;
        int n=read(),m=read();long long ans=0;
        for(int i=1;i<=n;i++){
            int x=read(),y=read(),w=read();
            aa[x*7000+y]=1;val[x][y]=w;
        }
        printf("Case #%d:\n",cnt);
        for(int i=1;i<=m;i++){
            int opt=read(),x=read(),y=read(),w,z;
            x=(x+ans)%6000+1;y=(y+ans)%6000+1;
            if(opt==1){
                w=read();val[x][y]=w;aa[x*7000LL+y]=1;
            }
            else if(opt==2){
                val[x][y]=-1;aa.erase(x*7000LL+y);
            }
            else if(opt==3){
                z=read();w=read();
                for(int k=0;k<you[z].size();k++){
                    int a=you[z][k].first,b=you[z][k].second;
                    if(a==0&&b==0){
                        if(check(x,y)) val[x][y]+=w;
                    }
                    else if(a==0||b==0){
                        int r=a+b;
                        if(check(x+r,y)) val[x+r][y]+=w;

                        if(check(x-r,y)) val[x-r][y]+=w;
                        if(check(x,y+r)) val[x][y+r]+=w;
                        if(check(x,y-r)) val[x][y-r]+=w;
                    }
                    else if(a==b){
                        int r=a;
                        if(check(x+r,y+r)) val[x+r][y+r]+=w;
                        if(check(x+r,y-r)) val[x+r][y-r]+=w;
                        if(check(x-r,y+r)) val[x-r][y+r]+=w;
                        if(check(x-r,y-r)) val[x-r][y-r]+=w;
                    }
                    else{
                        if(check(x+a,y+b)) val[x+a][y+b]+=w;
                        if(check(x+a,y-b)) val[x+a][y-b]+=w;
                        if(check(x-a,y+b)) val[x-a][y+b]+=w;
                        if(check(x-a,y-b)) val[x-a][y-b]+=w;
                        if(check(x+b,y+a)) val[x+b][y+a]+=w;
                        if(check(x+b,y-a)) val[x+b][y-a]+=w;
                        if(check(x-b,y+a)) val[x-b][y+a]+=w;
                        if(check(x-b,y-a)) val[x-b][y-a]+=w;
                    }
                }
            }
            else if(opt==4){
                z=read();ans=0;
                for(int k=0;k<you[z].size();k++){
                    int a=you[z][k].first,b=you[z][k].second;
                    if(a==0&&b==0){
                        if(check(x,y)) ans+=val[x][y];
                    }
                    else if(a==0||b==0){
                        int r=a+b;
                        if(check(x+r,y)) ans+=val[x+r][y];
                        if(check(x-r,y)) ans+=val[x-r][y];
                        if(check(x,y+r)) ans+=val[x][y+r];
                        if(check(x,y-r)) ans+=val[x][y-r];
                    }
                    else if(a==b){
                        int r=a;
                        if(check(x+r,y+r)) ans+=val[x+r][y+r];
                        if(check(x+r,y-r)) ans+=val[x+r][y-r];
                        if(check(x-r,y+r)) ans+=val[x-r][y+r];
                        if(check(x-r,y-r)) ans+=val[x-r][y-r];
                    }
                    else{
                        if(check(x+a,y+b)) ans+=val[x+a][y+b];
                        if(check(x+a,y-b)) ans+=val[x+a][y-b];
                        if(check(x-a,y+b)) ans+=val[x-a][y+b];
                        if(check(x-a,y-b)) ans+=val[x-a][y-b];
                        if(check(x+b,y+a)) ans+=val[x+b][y+a];
                        if(check(x+b,y-a)) ans+=val[x+b][y-a];
                        if(check(x-b,y+a)) ans+=val[x-b][y+a];
                        if(check(x-b,y-a)) ans+=val[x-b][y-a];
                    }
                }
                printf("%lld\n",ans);
            }

        }
        for(auto x:aa){
        long long now=x.first;
            val[now/7000][now%7000]=-1;
        }
        aa.clear();
    }
    return 0;
}
