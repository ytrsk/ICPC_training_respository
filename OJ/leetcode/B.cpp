#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
  
    return x*f;
}
class Solution {
public:
    int minTime(vector<int>& time, int m) {    
        int l=0,r=1e9+7,ans=0;
        while(l<=r){
            int mid=(l+r)>>1,p=0;
            for(int i=1;i<=m;i++){
                if(p==time.size()) break; 
                int x=0,mx=-1;
                while(p<time.size()&&x+time[p]<=mid){
                    x+=time[p];mx=max(mx,time[p]);
                    p++;
                    
                }
                if(p<time.size()){
                    int y=max(time[p],mx);
                    x-=y;
                    while(p<time.size()&&x+time[p]<=mid){
                        x+=time[p];mx=max(mx,time[p]);
                        p++;
                    }
                }
            }
            if(p==time.size()) ans=mid,r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
}s;
int main(){
    vector<int> a{999,999,999};
    printf("%d",s.minTime(a,4));
    return 0;
}