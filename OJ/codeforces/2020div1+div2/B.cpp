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
char s[maxn];
int a[maxn];
int main(){
    cin>>s+1;
    int len=strlen(s+1);
    int le=1,ri=len,top=0;
    while(le<ri){
        if(s[le]=='('&&s[ri]==')') a[++top]=le++,a[++top]=ri--;
        else if(s[le]==')') le++;
        else ri--;
    }
    sort(a+1,a+top+1);
    if(top==0) printf("0");
    else{printf("1\n%d\n",top); for(int i=1;i<=top;i++) printf("%d ",a[i]);
    }return 0;
}