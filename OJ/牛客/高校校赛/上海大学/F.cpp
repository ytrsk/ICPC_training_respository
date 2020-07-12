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
int mod[2300],fad[2300];
int D5[2300],D6[2300];
void mop(int x){
    int y=mod[x]%10;
    printf("Mother's Day: May %d",mod[x]);
    int z=mod[x]/10;
    if(z^1){
        if(y==1) printf("st");
        else if(y==2) printf("nd");
        else if(y==3) printf("rd");
        else printf("th");
    }
    else printf("th");
    printf(", %d\n",x);
}
void fap(int x){
    int y=fad[x]%10;
    printf("Father's Day: June %d",fad[x]);
    int z=fad[x]/10;
    if(z^1){
        if(y==1) printf("st");
        else if(y==2) printf("nd");
        else if(y==3) printf("rd");
        else printf("th");
    }
    else printf("th");
    printf(", %d\n",x);
}
int main(){
    int t=read();
    mod[2000]=14,fad[2000]=18;
    D5[2000]=1;D6[2000]=4;
    for(int i=2001;i<=2103;i++){
        int d=(i%4==0)?366:365;
        if(i==2100) d=365;
        D5[i]=(D5[i-1]+d-1)%7+1;
        D6[i]=(D6[i-1]+d-1)%7+1;
        int cnt=0,now=D5[i];
        for(int k=1;;k++){
            if(now==7) cnt++;
            if(cnt==2){
                mod[i]=k;break;
            }
            now=now%7+1;
        }
        now=D6[i];cnt=0;
        for(int k=1;;k++){
            if(now==7) cnt++;
            if(cnt==3){
                fad[i]=k;break;
            }
            now=now%7+1;
        }
    }
    while(t--){
        int y=read(),m=read(),d=read();
        if(m<5) mop(y);
        else if(m>6) mop(y+1);
        else if(m==5){
            if(d<mod[y]) mop(y);
            else fap(y); 
        }
        else if(m==6){
            if(d<fad[y]) fap(y);
            else mop(y+1);
        }
    }
    return 0;
}