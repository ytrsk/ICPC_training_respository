typedef long long ll;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
void exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;y=0;return;
	}
	exgcd(b,a%b,y,x);y-=x*(a/b);
}
