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
    cout<<x<<endl;
    int ans;cin>>ans;
    return ans;
}
map<string,int> aa;
int main(){
    int t,B;scanf("%d%d",&t,&B);
    while(t--){
        aa.clear();string r;
        for(int i=1;i<=150/B;i++){
            string s;
            for(int k=1;k<=B;k++){
                int x=query(k);
                s.insert(s.begin(),x+'0');
            }
            aa[s]=1;r=s;
        }
        reverse(r.begin(),r.end());
        cout<<r<<"\n";
        string ss;fflush(stdout);
        cin>>ss;
        if(ss=="Y") continue;
        else return 0;
    }
    return 0;
}