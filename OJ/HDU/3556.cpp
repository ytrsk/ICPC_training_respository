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
char s[10007];
int a[10007],n;
int Len[10007],you[10007];
char S[10007];
int len(int x){
    sprintf(S+1,"%d",a[x]);
    return strlen(S+1);
}
void ps(int x,char c){
    if(x<0) return;
    while(x--) putchar(c);
}
void print(){
    for(int i=1;i<=n;i++) Len[i]=len(i);
    you[n]=Len[n];
    for(int i=n-1;i;i--){
        you[i]=you[i+1]+3+Len[i];
    }
    int tot=you[1];
    for(int i=1;i<=n;i++){
        if(i<n){ps(tot-1,' ');putchar('1');putchar('\n');}
        ps(tot-you[i],' ');printf("%d",a[i]);
        if(i<n){putchar(' ');putchar('+');putchar(' ');ps(you[i+1],'-');}
        putchar('\n');
    }
}
int main(){
    while(scanf("%s",s+1)==1){
        int len=strlen(s+1);n=0;
            if(s[1]=='L'){
                a[++n]=0;a[++n]=2;
            }
            else{
                a[++n]=2;
            }
        for(int i=2;i<=len;i++){
            if(s[i]==s[i-1]){
                a[n]++;
            }
            else{
                a[n]--;a[++n]=2;
            }
        }
        print();
    }
    return 0;
}