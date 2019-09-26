#include <bits/stdc++.h>
#define make_pair mp
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int maxn=200007;
const int inf=(1LL<<29);
int be[maxn],bl,blc;
ll tot[maxn],val[maxn],ans;
int a[1000007];int x;
struct point{
    int l,r,id;
    bool operator < (point a) const{
        return be[l]!=be[a.l]?be[l]<be[a.l]:r<a.r;
    }
}q[maxn];
int l,r;
void modify(int xx,int y){
    if(y<0){
        a[val[xx]]--;
        if(!a[val[xx]]) ans--;
        return;
    }
    //printf("%d %d %lld %d\n",xx,y,ans,y*a[sum[xx]^x]);
    a[val[xx]]++;
    if(a[val[xx]]==1) ans++;
}
int main(){
    int n,m;cin>>n;bl=sqrt(n);
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
        be[i]=(i-1)/bl+1;
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&q[i].l,&q[i].r);q[i].id=i;
    }
    sort(q+1,q+m+1);
    l=1,r=0;
    for(int i=1;i<=m;i++){
        while(r>q[i].r) modify(r,-1),r--;
        while(r<q[i].r) modify(r+1,1),r++;
        while(l<q[i].l) modify(l,-1),l++;
        while(l>q[i].l) modify(l-1,1),l--;
        tot[q[i].id]=ans;
    }
    for(int i=1;i<=m;i++){
        printf("%lld\n",tot[i]);
    }
    return 0;
}
