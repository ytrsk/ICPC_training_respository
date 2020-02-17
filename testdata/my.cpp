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
int a[maxn],b[5];
int ha[maxn],vis[maxn];
int c3(int x){
    return x*(x-1)*(x-2)/6;
}
int c2(int x){
    return x*(x-1)/2;
}
int sum[307][307];
int main(){
    int n=read();
    for(int i=1;i<=n;i++) a[i]=read(),ha[i]=a[i];
    for(int i=1;i<5;i++) b[i]=read();
    sort(ha+1,ha+n+1);
    int len=unique(ha+1,ha+n+1)-a-1;
    long long ans=0;
    for(int i=1;i<=n;i++) a[i]=lower_bound(ha+1,ha+n+1,a[i])-ha;
    for(int i=1;i<=n;i++){
        for(int k=1;k<=n;k++) sum[i][k]=sum[i-1][k]+(a[i]==k);
    }
    if(b[1]==b[2]&&b[3]==b[4]&&b[1]==b[3]){
        for(int i=1;i<=n;i++){
            if(vis[a[i]]>=3) ans+=c3(vis[a[i]]);
            vis[a[i]]++;
        }
    }
    else if(b[1]==b[2]&&b[2]==b[3]){
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                if(k!=a[i]){
                    int left=sum[i-1][k],right=sum[n][k]-sum[i][k];
                    if(left>=3) ans+=c3(left);    
                }
            }
        }
    }
    else if(b[1]==b[2]&&b[2]==b[4]){
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                if(k!=a[i]){
                    int left=sum[i-1][k],right=sum[n][k]-sum[i][k];
                    if(left>=2&&right>=1) ans+=c2(left)*right;    
                }
            }
        }
    }
    else if(b[1]==b[3]&&b[3]==b[4]){
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                if(k!=a[i]){
                    int left=sum[i-1][k],right=sum[n][k]-sum[i][k];
                    if(left>=1&&right>=2) ans+=left*c2(right);    
                }
            }
        }
    }
    else if(b[2]==b[3]&&b[3]==b[4]){
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                if(k!=a[i]){
                    int right=sum[n][k]-sum[i][k];
                    if(right>=3) ans+=c3(right);    
                }
            }
        }
    }
    else if(b[1]==b[2]){
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                for(int z=1;z<=n;z++){
                    if(b[3]!=b[4]){
                        if(k!=a[i]&&k!=z&&a[i]!=z){
                            int left=sum[i-1][k],right=sum[n][z]-sum[i][z];
                            if(left>=2) ans+=c2(left)*right;
                        }
                    }
                    else{
                        if(k!=a[i]&&a[i]==z){
                            int left=sum[i-1][k],right=sum[n][z]-sum[i][z];
                            if(left>=2) ans+=c2(left)*right;
                        }   
                    }
                }
            }
        }
    }
    else if(b[2]==b[3]){
        for(int i=1;i<=n;i++){
            for(int k=i+1;k<=n;k++){
                for(int z=1;z<=n;z++){
                    if(b[1]!=b[4]){
                        if(a[i]!=a[k]&&a[i]!=z&&a[k]!=z){
                            int mid=sum[k-1][z]-sum[i][z];
                            if(mid>=2) ans+=c2(mid);
                        }
                    }
                    else{
                        if(a[i]==a[k]&&a[i]!=z&&a[k]!=z){
                            int mid=sum[k-1][z]-sum[i][z];
                            if(mid>=2) ans+=c2(mid);
                        }
                    }
                }
            }
        }
    }
    else if(b[1]==b[4]){
        for(int i=1;i<=n;i++){
            for(int k=i+1;k<=n;k++){
                for(int z=1;z<=n;z++){
                    if(b[2]!=b[3]){
                        if(a[i]!=z&&a[k]!=z&&a[i]!=a[k]){
                            int left=sum[i-1][z],right=sum[n][z]-sum[k][z];
                            ans+=left*right;
                        }
                    }
                    else{
                        if(a[i]!=z&&a[k]!=z&&a[i]==a[k]){
                            int left=sum[i-1][z],right=sum[n][z]-sum[k][z];
                            ans+=left*right;
                        }
                    }
                }
            }
        }
    }
    else if(b[2]==b[4]){
        for(int i=1;i<=n;i++){
            for(int k=i+1;k<=n;k++){
                for(int z=1;z<=n;z++){
                    if(b[1]!=b[3]){
                        if(a[i]!=z&&a[k]!=z&&a[i]!=a[k]){
                            int left=sum[k-1][z]-sum[i][z],right=sum[n][z]-sum[k][z];
                            ans+=left*right;
                        }
                    }
                    else{
                        if(a[i]!=z&&a[k]!=z&&a[i]==a[k]){
                            int left=sum[k-1][z]-sum[i][z],right=sum[n][z]-sum[k][z];
                            ans+=left*right;
                        }
                    }
                }
            }
        }
    }
    else if(b[1]==b[3]){
        for(int i=1;i<=n;i++){
            for(int k=i+1;k<=n;k++){
                for(int z=1;z<=n;z++){
                    if(b[2]!=b[4]){
                        if(a[i]!=z&&a[k]!=z&&a[i]!=a[k]){
                            int left=sum[i-1][z],right=sum[k-1][z]-sum[i][z];
                            ans+=left*right;
                        }
                    }
                    else{
                        if(a[i]!=z&&a[k]!=z&&a[i]==a[k]){
                            int left=sum[i-1][z],right=sum[k-1][z]-sum[i][z];
                            ans+=left*right;
                        }
                    }
                }
            }
        }
    }
    else if(b[3]==b[4]){
        for(int i=1;i<=n;i++){
            for(int k=1;k<=n;k++){
                for(int z=1;z<=n;z++){
                    if(b[1]!=b[2]){
                        if(k!=a[i]&&k!=z&&a[i]!=z){
                            int left=sum[i-1][k],right=sum[n][z]-sum[i][z];
                            if(right>=2) ans+=left*c2(right);
                        }
                    }
                    else{
                        if(k==a[i]&&k!=z&&a[i]!=z){
                            int left=sum[i-1][k],right=sum[n][z]-sum[i][z];
                            if(right>=2) ans+=left*c2(right);
                        }
                    }
                }
            }
        }
    }
    else{
        for(int i=1;i<=n;i++){
            for(int k=i+1;k<=n;k++){
                if(a[i]!=a[k])
                for(int z=1;z<=n;z++){
                    if(z!=a[i]&&z!=a[k]){
                        int left=i-1-sum[i-1][a[i]]-sum[i-1][a[k]]-sum[i-1][z],right=sum[n][z]-sum[k][z];
                        ans+=left*right;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}