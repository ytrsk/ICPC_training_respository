#include <bits/stdc++.h>
#define mp make_pair
#define sqr(x) (x)*(x)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int maxn=500007;
const ll inf=1<<29;
#define rd(n) FastIO::read(n)
namespace FastIO {
	const int SIZE = 1 << 16;
	char buf[SIZE], obuf[SIZE], str[60];
	int bi = SIZE, bn = SIZE, opt;
	int read(char *s) {
		while (bn) {
			for (; bi < bn && buf[bi] <= ' '; bi++);
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		int sn = 0;
		while (bn) {
			for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		s[sn] = 0;
		return sn;
	}
	bool read(int& x) {
		int n = read(str), bf;

		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf < 0) x = -x;
		return 1;
	}
};
int a[maxn],b[maxn],n,L;
ll ans=0;
inline int abs(int x){
    return x<0?-x:x;
}
inline ll check(int x){
    ll Ans=0;
    for(register int i=0;i<n;++i){
        int now=abs(a[i]-b[(i+x)%n]);
        Ans+=min(now,L-now);
    }
    ans=min(ans,Ans);
    return Ans;
}
int main(){
    int T;rd(T);
    while(T--){
        rd(n);rd(L);
        for(int i=0;i<n;i++) rd(a[i]);
        for(int i=0;i<n;i++) rd(b[i]);
        int l=0,r=n-1;ans=(1LL<<60);
        while(l<r-3){
            int m1=l+(r-l)/3,m2=l+2*(r-l)/3;
            if(check(m1)<check(m2)) r=m2;
            else l=m1;
        }
        
        for(int i=max(l-3,0);i<=min(l+3,n-1);++i) ans=min(ans,check(i)); 
        printf("%lld\n",ans);
    }
    return 0;
}