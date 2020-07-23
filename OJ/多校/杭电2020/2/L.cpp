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
char A[100007],B[23];
int dp[23][23];
int you[maxn][30];
int last[30];
int main(){
    int t=read();
    while(t--){
        scanf("%s",A+1);
        scanf("%s",B+1);
        int lenB=strlen(B+1);
        reverse(B+1,B+lenB+1);
        for(int i=0;i<26;i++) last[i]=0;
        int lenA=strlen(A+1);//lenB=strlen(B+1);
        for(int i=1;i<=lenA+1;i++){
            for(int k=0;k<26;k++) you[i][k]=last[k];
            if(i<=lenA) last[A[i]-'a']=i;
        }
        /*
        for(int i=0;i<26;i++) last[i]=0;
        for(int i=1;i<=lenB;i++){
            for(int k=0;k<26;k++) Last[i][k]=last[k];
            last[B[i]-'a']=i;
        }*/
        int q=read();
        for(int i=1;i<=q;i++){
            int L=read(),R=read();
            for(int k=0;k<=lenB;k++) dp[0][k]=0;
            dp[0][0]=R+1;
            int ans=0;
            for(int k=1;k<=lenB;k++){
                dp[k][0]=R+1;
                for(int z=1;z<=lenB;z++){
                    dp[k][z]=0;
                    dp[k][z]=dp[k-1][z];
                    if(z) dp[k][z]=max(dp[k][z],you[dp[k-1][z-1]][B[k]-'a']); 
                    if(dp[k][z]>=L) ans=max(ans,z);
                }
            }
      //      if(i==1) cout<<you[7][B[2]-]<<endl;
            printf("%d\n",R-L+1+lenB-2*ans);
        }
    }
    return 0;
}