const int maxn=100007;
int res[maxn],n;
int lowbit(int x){
	return x&-x;
}
int query(int x){
	int ans=0;
	for(;x;x-=lowbit(x)) ans+=res[x];
}
int insert(int o,int x){
	for(;o<=n;o+=lowbit(o)) res[o]+=x;
}
int main(){
	return 0;
}
