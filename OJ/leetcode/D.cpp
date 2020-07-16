#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
#pragma GCC optimize(3,"Ofast","inline")
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
int dp[1000000+7];
vector<int> yy[100001];
class Solution {
public:
    int splitArray(vector<int>& nums) {
        int len=nums.size();
        memset(dp,0x3f,sizeof(dp));
        for(int i=0;i<len;i++){
            int x=nums[i];
            for(int k=2;k*k<=x;k++){
                if(x%k==0){
                    yy[i].push_back(k);
                    while(x%k==0) x/=k;
                }
            }
            if(x>1) yy[i].push_back(x);
        }
        for(int i=0;i<=len;i++){
            int now=inf;
            if(i){
                for(auto k:yy[i-1]){
                    now=min(now,dp[k]);
                }
            }
            else now=0;
            if(i==len) return now;
            for(auto k:yy[i]){
                dp[k]=min(dp[k],now+1);
            }
            
        }
        return 0;
    }
}s;
int main(){
    vector<int> nums{2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    cout<<s.splitArray(nums);
    return 0;
}