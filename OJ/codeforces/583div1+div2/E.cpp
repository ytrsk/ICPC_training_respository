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
int d[100007],id[100007];
bool cmp(int x,int y){
    return d[x]>d[y];
}
int last[100007];
int you[100007];
int main(){
    //cin.tie(0);ios_base::sync_with_stdio(false);
    int n;cin>>n;
    for(int i=1;i<=n;i++) d[i]=read(),id[i]=i;
    sort(id+1,id+n+1,cmp);
    for(int i=1;i<n;i++){
        printf("%d %d\n",2*id[i]-1,2*id[i+1]-1);
    }
    int now=0;
    for(int i=1;i<=n;i++){
        if(d[id[i]]==1){
            printf("%d %d\n",2*id[i]-1,2*id[i]);continue;
        }
        int len=d[id[i]]-1;
        if(i+len<=n) printf("%d %d\n",2*id[i+len]-1,2*id[i]),you[1]=2*id[i];
        else{
       //     cout<<"asd";
            you[0]=2*id[n]-1;
            int x=i+len-n;
            printf("%d %d\n",you[x],2*id[i]);
            if(!you[x+1]) you[x+1]=2*id[i];
        }
    }
    return 0;
}
