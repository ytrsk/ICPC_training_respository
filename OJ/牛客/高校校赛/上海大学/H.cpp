#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[1000007];
int len,pos[10],pre[3];
vector<int> g;
bool Try(int x1,int x2,int L,int R){
    if(R<0) return 0;L=max(L,0);if(L>R) return 0;
    int x=L==0?0:((L-1)/3+1)*3;
    if(x>R) return 0;
    x/=3;
    return x1/3+x2/3>=x;
}
bool ttry(int x1,int x2,int L,int R){
    L=max(L,0);
    if(x1<0||x2<0||R<0) return false;
    int ok=Try(x1,x2,L,R);
    if(x1&&x2){
        ok|=Try(x1-1,x2-1,L-2,R-2);
    }
    if(x1>=2&&x2>=2){
        ok|=Try(x1-2,x2-2,L-4,R-4);
    }
    return ok;
}
bool check(int x0,int x1,int x2,int x,int mo){
    if(mo==1){
        return ttry(x1-1,x2,x-x0-1,x-1);
    }
    else if(mo==0){
        return ttry(x1,x2,x-x0,x);
    }
    else{
        return ttry(x1-2,x2,x-x0-2,x-2)||ttry(x1,x2-1,x-x0-1,x-1);
    }
}
int main(){
    int t=read();
    while(t--){
        g.clear();
        memset(pos,0,sizeof(pos));
        pre[0]=pre[1]=pre[2]=0;
        scanf("%s",s+1);
        len=strlen(s+1);
        int m=read();
        for(int i=len;i;i--){
            int ch=s[i]-'0';
            pos[ch]++;pre[ch%3]++;
        }
        int tot=0,val=m,first=1;
        while(val){
            int you=-1;
            for(int i=9;i>=first;i--){
                int x=0;
                if(!pos[i]) continue;
                if(i%3==0) x=check(pre[0]-1,pre[1],pre[2],val-1,(tot+(3-i%3))%3);
                else if(i%3==1) x=check(pre[0],pre[1]-1,pre[2],val-1,(tot+(3-i%3))%3);
                else x=check(pre[0],pre[1],pre[2]-1,val-1,(tot+(3-i%3))%3);
                if(x){
                    you=i;break;
                }
            }
            first=0;
            if(you==-1) break;
            else{
                pre[you%3]--;pos[you]--;
                tot=(tot+(3-you%3))%3;
                g.push_back(you);
                val--;
            }
        }
        if(!val){
            for(int i=0;i<g.size();i++) printf("%d",g[i]);
            printf("\n");
        }   
        else if(pre[0]&&m==1) printf("0\n");
        else printf("-1\n");
    }
    return 0;
}