#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
char s[200007];
int ans[200007];
int main(){
    int t=read();
    while(t--){
        int n=read();scanf("%s",s+1);
        int ok=0;
        for(int i=0;i<=9;i++){
            int x1=0,x2=0,now=1;
            for(int k=1;k<=n;k++){
                int x=s[k]-'0';
                if(x<i){
                    if(x>=x1) x1=x,ans[k]=1;
                    else{
                        now=0;break;
                    }
                }
                else if(x>i){
                    if(x>=x2) x2=x,ans[k]=2;
                    else{
                        now=0;break;
                    }
                }
                else{
                    if(x>=x2) x2=x,ans[k]=2;
                    else if(x>=x1) x1=x,ans[k]=1;
                    else{
                        now=0;break;
                    }
                }
            }
            if(now==1){
                ok=1;break;
            }
        }
        if(!ok) printf("-");
        else for(int i=1;i<=n;i++) printf("%d",ans[i]);
        printf("\n");
    }

    return 0;
}
