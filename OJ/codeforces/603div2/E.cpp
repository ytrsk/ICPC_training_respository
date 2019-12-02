#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
#define rint register int
const int maxn=1000007;
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
char s[maxn],now[maxn];
int mn[maxn<<2],tag[maxn<<2],mx[maxn<<2];
void pushdown(int o){
    if(tag[o]){
        tag[o<<1]+=tag[o];tag[o<<1|1]+=tag[o];
        mn[o<<1]+=tag[o];mn[o<<1|1]+=tag[o];
        mx[o<<1]+=tag[o];mx[o<<1|1]+=tag[o];
        tag[o]=0;
    }
}
void pushup(int o){
    mn[o]=min(mn[o<<1],mn[o<<1|1]);
    mx[o]=max(mx[o<<1],mx[o<<1|1]);
}
void update(int o,int l,int r,int ql,int qr,int x){
    if(l==ql&&r==qr){
        tag[o]+=x;mx[o]+=x;mn[o]+=x;return;
    }
    pushdown(o);
    int m=(l+r)>>1;
    if(ql<=m&&qr>m) update(o<<1,l,m,ql,m,x),update(o<<1|1,m+1,r,m+1,qr,x);
    else if(ql<=m) update(o<<1,l,m,ql,qr,x);
    else update(o<<1|1,m+1,r,ql,qr,x);
    pushup(o);
}
char r[maxn];
int main(){
    int len=read();
    scanf("%s",s+1);
    int pos=1,tot=0,now=1;
    for(int i=1;i<=len;i++){
        if(s[i]=='L'){
            pos=max(1,pos-1);
        }
        else if(s[i]=='R'){
            pos++;
        }
        else{
            if(s[i]=='('){
                if(r[pos]!='('){
                    if(r[pos]==')') tot+=2;
                    else tot++;
                } 
                if(r[pos]!='(') update(1,1,maxn-7,pos,maxn-7,r[pos]==')'?2:1);
            }
            else if(s[i]==')'){
                if(r[pos]!=')'){
                    if(r[pos]=='(') tot-=2;
                    else tot--;
                }
                if(r[pos]!=')') update(1,1,maxn-7,pos,maxn-7,r[pos]=='('?-2:-1);
            }
            else{
                if(r[pos]=='(') tot--;
                else if(r[pos]==')') tot++;
                
                if(r[pos]=='('||r[pos]==')')update(1,1,maxn-7,pos,maxn-7,r[pos]=='('?-1:1);
            }
            r[pos]=s[i];
        }
        if(mn[1]<0||tot!=0) printf("-1 ");
        else printf("%d ",mx[1]); 
    }
    return 0;
}