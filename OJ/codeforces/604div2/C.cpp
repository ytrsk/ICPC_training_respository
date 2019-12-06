#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=400007;
const int inf=(1LL<<29);
const int mod=1e9+7;
int read(){
    int x=0;int f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;c=getchar();
    }
    while(c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    x*=f;return x;
}
int val[maxn];
int main(){
    int t=read();
    while(t--){
        int n=read();
        for(int i=1;i<=n;i++) val[i]=read();
        int posa=1,ok=1;
        while(posa<n&&val[posa+1]==val[1]) ++posa;
        int posb=posa+1;
        while(posb<n&&(val[posb+1]==val[posb]||posb-posa<=posa)) ++posb;
        int posc=posb+1;
        while(posc<n&&val[posc+1]==val[posb+1]) ++posc;
            while(1){
                int nex=posc+1;
                while(nex<n&&val[nex+1]==val[posc+1]) nex++;
                if(nex<=n/2){
                    posc=nex;
                }
                else break;
            }
        ok=0;
        if(posc<=n/2&&posc-posb>posa&&posb-posa>posa) printf("%d %d %d\n",posa,posb-posa,posc-posb);
        else printf("0 0 0\n");
    }
    return 0;
}