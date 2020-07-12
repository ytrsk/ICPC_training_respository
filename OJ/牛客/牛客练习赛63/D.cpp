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
char s[1007],t[1007];
int dpm[1007][1007],dpn[1007][1007];
int pre[1007];
int main(){
    int n=read(),cnt0=read(),cnt1=read();
    int valpre=read(),valsuf=read();
    memset(dpm,-0x3f,sizeof(dpm));
    memset(dpn,0x3f,sizeof(dpn));
    scanf("%s%s",s+1,t+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i]=='0');
    dpm[0][0]=dpn[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int k=0;k<=min(i,cnt0);k++){
            int prev,sufv;
            if(t[i]=='0'){  
                    prev=(pre[i]==k)?valpre:0;
                    sufv=(pre[n]-pre[i-1]==cnt0-(k-1))?valsuf:0;
                if(k) dpm[i][k]=dpm[i-1][k-1]+prev+sufv,dpn[i][k]=dpn[i-1][k-1]+prev+sufv;
            }
            else if(t[i]=='1'){
                prev=(pre[i]==k)?valpre:0;
                sufv=(pre[n]-pre[i-1]==cnt0-k)?valsuf:0;
                dpm[i][k]=dpm[i-1][k]+prev+sufv;
                dpn[i][k]=dpn[i-1][k]+prev+sufv;
            }
            else{
                
                if(k){ 
                    prev=(pre[i]==k)?valpre:0;
                    sufv=(pre[n]-pre[i-1]==cnt0-(k-1))?valsuf:0;
                    dpm[i][k]=max(dpm[i][k],dpm[i-1][k-1]+prev+sufv);
                    dpn[i][k]=min(dpn[i][k],dpn[i-1][k-1]+prev+sufv);
                }
                prev=(pre[i]==k)?valpre:0;
                sufv=(pre[n]-pre[i-1]==cnt0-k)?valsuf:0;
                dpm[i][k]=max(dpm[i][k],dpm[i-1][k]+prev+sufv);
                dpn[i][k]=min(dpn[i][k],dpn[i-1][k]+prev+sufv);
                
            }
        }
    }
    cout<<dpn[n][cnt0]<<" "<<dpm[n][cnt0];
    return 0;
}