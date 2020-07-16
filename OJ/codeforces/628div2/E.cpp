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
int s[maxn],z[20];
struct xxj{
	int a[20];
	void insert(int x){
		for(int i=19;~i;--i){
			if(x&(1<<i)){
				if(a[i]) x^=a[i];
				else{
					a[i]=x;
					break;
				}
			}
		}
	}
	int query(){
		int ans=0;
		for(int i=19;~i;i--){
			if(!(ans&z[i])) ans^=a[i];
		}
		return ans;
	}
}a[maxn<<1];
int n=0;
int main(){
    return 0;
}