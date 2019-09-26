#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=100007;
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
struct poke{
    char name[15];
    int val[6],ll;
    pair<int,pair<int,int> > rk;
    void solve(){
        int sum=val[1]+val[2]+val[3]+val[4]+val[5];
        sort(val+1,val+6);
        if(val[1]==1&&val[2]==10&&val[3]==11&&val[4]==12&&val[5]==13){
            rk=mp(7,mp(0,0));return;
        }
        if(val[2]==val[1]+1&&val[3]==val[2]+1&&val[4]==val[3]+1&&val[5]==val[4]+1){
            rk=mp(6,mp(val[5],0));return;
        }
        for(int i=1;i<=2;i++){
            if(val[i]==val[i+1]&&val[i+1]==val[i+2]&&val[i+2]==val[i+3]){
                rk=mp(5,mp(val[i],sum-4*val[i]));return;
            }
        }
        for(int i=1;i<=3;i++){
            if(val[i]==val[i+1]&&val[i+1]==val[i+2]){
                int x;
                if(i==1) x=val[4];
                else x=val[1];
                if(sum-3*val[i]==2*x){
                    rk=mp(4,mp(val[i],x));return;
                }
                else{
                    rk=mp(3,mp(val[i],sum-3*val[i]));return;
                }
            }
        }
        if(val[1]==val[2]&&val[3]==val[4]){
            rk=mp(2,mp(val[4],val[2]*20+sum-2*val[1]-2*val[3]));return;
        }
        if(val[1]==val[2]&&val[4]==val[5]){
            rk=mp(2,mp(val[5],val[2]*20+sum-2*val[1]-2*val[4]));return;
        }
        if(val[2]==val[3]&&val[4]==val[5]){
            rk=mp(2,mp(val[5],val[3]*20+sum-2*val[2]-2*val[4]));return;
        }
        for(int i=1;i<=4;i++){
            if(val[i]==val[i+1]){
                rk=mp(1,mp(val[i],sum-2*val[i]));return;
            }
        }
        rk=mp(0,mp(sum,0));
    }
    bool operator < (poke a){
        if(rk!=a.rk) return rk>a.rk;
        for(int i=1;i<=min(ll,a.ll);i++){
            if(name[i]!=a.name[i]) return name[i]<a.name[i];
        }
        return ll<a.ll;
    }
}p[100007];
char pai[15];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++){
            scanf("%s%s",p[i].name+1,pai+1);
            int len=strlen(pai+1);
            p[i].ll=strlen(p[i].name+1);
            int pos=1,e1=0;
            while(pos<=len){
                if(pai[pos]>='2'&&pai[pos]<='9') p[i].val[++e1]=pai[pos]-'0';
                else if(pai[pos]=='J') p[i].val[++e1]=11;
                else if(pai[pos]=='Q') p[i].val[++e1]=12;
                else if(pai[pos]=='K') p[i].val[++e1]=13;
                else if(pai[pos]=='A') p[i].val[++e1]=1;
                else p[i].val[++e1]=10,++pos;
                ++pos;
            }
            p[i].solve();
        }
        sort(p+1,p+n+1);
        for(int i=1;i<=n;i++){
            printf("%s\n",p[i].name+1);
        }
    }
    return 0;
}
