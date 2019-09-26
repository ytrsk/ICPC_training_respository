#include <stdio.h>
#include <iostream>
#include <string.h>
#define ll long long
using namespace std;
const int maxn=1000007;
int you[maxn],q[maxn],tr[maxn][30],fail[maxn],rt=1,e1=1;
char s[maxn];
void ins(char *s){
	int u=rt,len=strlen(s+1);
	for(int i=1;i<=len;i++){
		if(!tr[u][s[i]-'a']) tr[u][s[i]-'a']=++e1;
		u=tr[u][s[i]-'a'];
	}
	you[u]++;
}
void getfail(){
	int ql=1,qr=0;q[++qr]=rt;fail[1]=0;
	while(ql<=qr){
		int u=q[ql++];
		for(int i=0;i<26;i++){
			if(!tr[u][i]) continue;
			int v=fail[u];
			while(v&&!tr[v][i]) v=fail[v];
			fail[tr[u][i]]=tr[v][i];
            q[++qr]=tr[u][i];
		}
	}
}
void acm(char *s){
    int len=strlen(s+1),u=rt,ans=0;
    for(int i=1;i<=len;i++){
        while(u&&!tr[u][s[i]-'a']) u=fail[u];
        if(tr[u][s[i]-'a']) u=tr[u][s[i]-'a'];
        for(int k=u;~you[k]&&k!=rt;k=fail[k]) ans+=you[k],you[k]=-1;
    }
    printf("%d\n",ans);
}
void init(){
    for(int i=1;i<=e1;i++) for(int k=0;k<26;k++) tr[i][k]=0;
    for(int i=1;i<=e1;i++) you[i]=0;
    e1=1;
}
int main(){
    int t;cin>>t;
    for(int i=0;i<26;i++) tr[0][i]=1;
    while(t--){
        init();
        int n;scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%s",s+1);ins(s);
        }
        getfail();
        scanf("%s",s+1);
        acm(s);
    }
	return 0;
}
