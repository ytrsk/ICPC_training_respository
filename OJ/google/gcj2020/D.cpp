#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=1<<29;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int query(int x){
    cout<<x<<endl;fflush(stdout);
    int ans;scanf("%d",&ans);
    return ans;
}
int val[maxn],ans[maxn],t,B;
void rev(){
    for(int i=1;i<=B;i++) ans[i]^=1;
}
void swap(){
    for(int i=1;i<=B/2;i++) swap(ans[i],ans[B-i+1]);
}
int main(){
    cin>>t>>B;
    while(t--){
        for(int i=1;i<=B;i++) ans[i]=0;
        int x=-1,y=-1,tot=0;
        for(int i=1;;i++){
            if(tot>1&&tot%10==0){
                if(y==-1){
                    if(query(x)^ans[x]){
                        rev();
                    }
                    query(1);
                }
                else{
                    if(query(y)^ans[y]){
                        if(x==-1) query(1),rev();
                        else{
                            if(query(x)^ans[x]) rev();
                            else swap();
                        }
                    }
                    else{
                        if(~x){
                            if(query(x)^ans[x]) rev(),swap();
                        }
                        else query(1);
                    }
                }
                tot+=2;
            }
            if(tot==150) break;
            int X=(i-1)%(B/2)+1;
            ans[X]=query(X),ans[B-X+1]=query(B-X+1);
            if(ans[X]==ans[B-X+1]) x=X;
            else y=X;
            tot+=2;
            if(tot==150) break;
        }
        for(int i=1;i<=B;i++) printf("%d",ans[i]);
        printf("\n");
        fflush(stdout);
        string ss;cin>>ss;
        if(ss=="Y") continue;
        else return 0;
    }
    return 0;
}