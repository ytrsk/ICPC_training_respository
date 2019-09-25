#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=2048;
bitset<maxn> a[maxn],b,c,d,e,nw[maxn];
pii solve(int x,int y){
    //if(x==2&&y==5||x==5&&y==2) cout<<"qq";
    c=a[x]&a[y];
    pii z=mp((a[x]^c)._Find_first(),(a[y]^c)._Find_first());
    if(z.first==2048||z.second==2048) return mp(-1,-1);
    else return z;
}
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'&&ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
map<pii,int> aa;
map<pii,pii> bb;
int main(){
    int n=read(),m=read(),q=read();
    for(int i=0;i<m;i++) b[i]=1;
    for(int i=0;i<n;i++) aa[mp(0,i)]=1;
    for(int i=0;i<=m;i++) nw[i]=(b<<i)&b;
    //cout<<(nw[3]^nw[4]).count();
    while(q--){
        /*cout<<"now";
        for(auto i=aa.begin();i!=aa.end();++i)
        cout<<"("<<i->first.first<<","<<i->first.second<<")"<<" ";
        cout<<"\n";*/
        int x=read(),l=read(),r=read();
        l--;r--;x--;
        int len=a[x].count();
        auto it=aa.find(mp(len,x));
        pii y,z;
        int x1=-1,x2=-1;
        if(it!=aa.begin()){
            auto now=it;--now;
            int pos=(now->first).second;
            x1=pos;
            z=mp(pos,x);
            if(bb.count(z)) bb.erase(z);
        }
        auto now=it;++now;
        if(now!=aa.end()){
            int pos=(now->first).second;
            x2=pos;
            z=mp(x,pos);
            if(bb.count(z)) bb.erase(z);
        }
        if(~x1&&~x2){
            y=solve(x1,x2);
            if(y.second!=-1) bb[mp(x1,x2)]=y;
        }
        x1=-1;x2=-1;
        a[x]^=nw[l]^nw[r+1];
       // cout<<(nw[l]^nw[r+1]).count()<<endl;
        aa.erase(it);len=a[x].count();
        aa[mp(len,x)]=1;it=aa.find(mp(len,x));
        if(it!=aa.begin()){
            auto now=it;--now;
            int pos=(now->first).second;
            x1=pos;
            y=solve(pos,x);
            z=mp(pos,x);
            if(y.second!=-1) bb[mp(pos,x)]=y;
        }
        now=it;++now;
        if(now!=aa.end()){
            int pos=(now->first).second;
            x2=pos;
            y=solve(x,pos);
            z=mp(x,pos);
            if(y.second!=-1) bb[mp(x,pos)]=y;
        }
        if(bb.count(mp(x1,x2))) bb.erase(mp(x1,x2));
        if(bb.size()){
            y=bb.begin()->first;
            z=bb.begin()->second;
            if(y.first>y.second) swap(y.first,y.second);
            if(z.first>z.second) swap(z.first,z.second);
            cout<<y.first+1<<" "<<z.first+1<<" "<<y.second+1<<" "<<z.second+1<<"\n";
        }
        else cout<<-1<<"\n";
    }
    return 0;
}
