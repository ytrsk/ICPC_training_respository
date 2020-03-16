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
int dp1[20],dp2[20];
int main(){
    string s1="XiaoQiao",s2="XiaoHuiHui";
    string s;cin>>s;
    dp1[0]=dp2[0]=1;
    int n=s.length();
    for(int i=0;i<n;i++){
        for(int k=7;~k;k--){
            if(dp1[k]&&s[i]==s1[k]) dp1[k+1]=1; 
        }
        for(int k=9;~k;k--){
            if(dp2[k]&&s[i]==s2[k]) dp2[k+1]=1;
        }
    }
    cout<<((dp1[8]&&dp2[10])?"Happy":"emm");
    return 0;
}