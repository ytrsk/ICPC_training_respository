#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=100007;
const ll inf=0x3f3f3f3f;
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int a1,a2,a3,a4,a5,b1,b2,b3,b4,b5;
int main(){
    int t=read();
    while(t--){
        a1=read(),a2=read(),a3=read(),a4=read(),a5=0;
        b1=read(),b2=read(),b3=read(),b4=read(),b5=0;
        while((a1||a2||a3||a4||a5)&&(b1||b2||b3||b4||b5)){
            if(a3||a4) b5=0;
            if(a5){
                if(b1){
                    a5--;b1--;b3++;continue;
                }
                if(b2){
                    a5--;b2--;b4++;continue;
                }               
            }
            if(a1){
                if(b3){
                    a1--;a3++;b3--;b5++;
                    continue;
                }
                if(b4){
                    a1--;a3++;b4--;
                    continue;
                }
            }
            if(a2){
                if(b3){
                    a2--;a4++;b3--;b5++;
                    continue;
                }
                if(b4){
                    a2--;a4++;b4--;
                    continue;
                }
            }
            if(a3){
                if(b3){
                    a3--;a5++;b3--;b5++;
                    continue;
                }
                if(b4){
                    a3--;a5++;b4--;
                    continue;
                }
            }
            if(a4){
                if(b3){
                    a4--;b3--;b5++;
                    continue;
                }
                if(b4){
                    a4--;b4--;
                    continue;
                }
            }
            if(a3){
                if(b1){
                    a3--;a5++;b1--;b3++;
                    continue;
                }
                if(b2){
                    a3--;a5++;b2--;b4++;
                    continue;
                }
            }
            if(a4){
                if(b1){
                    a4--;b1--;b3++;
                    continue;
                }
                if(b2){
                    a4--;b2--;b4++;
                    continue;
                }
            }
            if(a1){
                if(b1){
                    a1--;a3++;b1--;b3++;continue;
                }
                if(b2){
                    a1--;a3++;b2--;b4++;continue;
                }
            }
            if(a2){
                if(b1){
                    a2--;a4++;b1--;b3++;continue;
                }
                if(b2){
                    a2--;a4++;b2--;b4++;continue;
                }
            }

            if(b5){
                if(a5){
                    a5--;b5--;continue;
                }
                if(a1){
                    a1--;a3++;b5--;continue;
                }
                if(a2){
                    a2--;a4++;b5--;continue;
                }
            }
            if(a5&&(b3||b4)) a5=0;
        }
        if(a1+a2+a3+a4+a5){
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}