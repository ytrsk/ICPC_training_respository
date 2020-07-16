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
int a[207][207];
int ans[207],sum[207],n;
int you[207][207],pos[207],ch[207];
unordered_map<int,int> aa[207];
int wei[207];
bool check(){
    for(int i=1;i<=n;i++) wei[ans[i]]=i;
    for(int i=2;i<=n;i++) ch[pos[i]]=i;
    for(int i=1;i<n;i++){
        for(int k=1;k<=a[i][0];k++){
            if(wei[a[i][k]]>ch[i]||wei[a[i][k]]<ch[i]-a[i][0]+1) return false;
        }
    }
    return true;
}
int main(){
    int t=read();
    while(t--){
        n=read();
        for(int i=1;i<n;i++){
            for(int k=1;k<=n;k++) you[i][k]=0;
            a[i][0]=read();sum[i]=0;
            for(int k=1;k<=a[i][0];k++) a[i][k]=read(),you[i][a[i][k]]=1,sum[i]+=a[i][k];
            
        }
        int okk=0;
        if(n==2){
            printf("%d %d\n",a[1][1],a[1][2]);continue;
        }
        for(int i=1;i<n;i++){
            if(a[i][0]==2){
                for(int k=1;k<n;k++){
                    aa[k].clear();
                    for(int z=1;z<=a[k][0];z++)
                    aa[k][a[k][z]]=1;
                }
                for(int k=1;k<n;k++) pos[k+1]=ch[k]=0;
                pos[2]=i;
                ans[1]=a[i][1],ans[2]=a[i][2];ch[i]=1;
                int ok=0;
                for(int k=1;k<n;k++){
                    if(k^i){
                        if(a[k][0]==2){
                            if(you[k][ans[1]]){
                                pos[3]=k;ch[k]=1;
                                ans[3]=sum[k]-ans[1];
                                ok=1;break;
                            }
                            else if(you[k][ans[2]]){
                                pos[3]=k;ch[k]=1;
                                ans[3]=sum[k]-ans[2];
                                ok=1;break;
                            }
                        }
                        else if(a[k][0]==3){
                            if(you[k][ans[1]]&&you[k][ans[2]]){
                                pos[3]=k;ch[k]=1;
                                ans[3]=sum[k]-ans[1]-ans[2];ok=1;break;
                            }
                        }
                    }
                }
                for(int i=1;i<=2;i++){
                    for(int k=1;k<n;k++){
                        if(aa[k].count(ans[i])) aa[k].erase(ans[i]);
                    }
                }
                if(ok){
                    for(int k=4;k<=n;k++){
                        int OK=0;
                        for(int z=1;z<n;z++){
                            if(!ch[z]&&a[z][0]<=k){
                                if(you[z][ans[k-1]]){
                                    if(aa[z].size()==2){
                                        ch[z]=1;pos[k]=z;OK=1;
                                        aa[z].erase(ans[k-1]);
                                        ans[k]=(*aa[z].begin()).first;break;
                                    }
                                }
                            }
                        }
                        if(!OK){
                            ok=0;break;
                        }
                        else{
                            for(int z=1;z<n;z++){
                                if(aa[z].count(ans[k-1])) aa[z].erase(ans[k-1]);
                            }
                        }
                    }
                }
                if(ok){
                    
                    if(check()){
                        okk=1;break;
                    }
                }
                for(int k=1;k<n;k++){
                    aa[k].clear();
                    for(int z=1;z<=a[k][0];z++)
                    aa[k][a[k][z]]=1;
                }
                for(int k=1;k<n;k++) pos[k+1]=ch[k]=0;
                pos[2]=i;
                ans[1]=a[i][2],ans[2]=a[i][1];ch[i]=1;
                ok=0;
                for(int k=1;k<n;k++){
                    if(k^i){
                        if(a[k][0]==2){
                            if(you[k][ans[1]]){
                                pos[3]=k;ch[k]=1;
                                ans[3]=sum[k]-ans[1];
                                ok=1;break;
                            }
                            else if(you[k][ans[2]]){
                                pos[3]=k;ch[k]=1;
                                ans[3]=sum[k]-ans[2];
                                ok=1;break;
                            }
                        }
                        else if(a[k][0]==3){
                            if(you[k][ans[1]]&&you[k][ans[2]]){
                                pos[3]=k;ch[k]=1;
                                ans[3]=sum[k]-ans[1]-ans[2];ok=1;break;
                            }
                        }
                    }
                }
                for(int i=1;i<=2;i++){
                    for(int k=1;k<n;k++){
                        if(aa[k].count(ans[i])) aa[k].erase(ans[i]);
                    }
                }
                if(ok){
                    for(int k=4;k<=n;k++){
                        int OK=0;
                        for(int z=1;z<n;z++){
                            if(!ch[z]&&a[z][0]<=k){
                                if(you[z][ans[k-1]]){
                                    if(aa[z].size()==2){
                                        ch[z]=1;pos[k]=z;
                                        aa[z].erase(ans[k-1]);OK=1;
                                        ans[k]=(*aa[z].begin()).first;break;
                                    }
                                }
                            }
                        }
                        if(!OK){
                            ok=0;break;
                        }
                        else{
                            for(int z=1;z<n;z++){
                                if(aa[z].count(ans[k-1])) aa[z].erase(ans[k-1]);
                            }
                        }
                    }
                }
                if(ok){
                    if(check()){
                        okk=1;break;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}