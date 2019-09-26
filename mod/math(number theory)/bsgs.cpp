const int modb=76543;
int head[modb],next1[modb],from[modb],e1,to[modb];
void insert(int u,int v){
	++e1;from[e1]=u;to[e1]=v;next1[e1]=head[u%modb];head[u%modb]=e1;
}
int find(int x){
	for(int i=head[x%modb];i;i=next1[i])
	if(from[i]==x) return to[i];
	return -1;
}
ll bsgs(int a,int b,int c){
	memset(head,0,sizeof(head));e1=0;
	if(b==1) return 0;
	int len=(int)sqrt(c+0.5);
	ll x=1,p=1;
	for(int i=0;i<len;i++,p=p*a%c) insert(p*b%c,i);
	for(ll i=len;;i+=len){
		x=x*p%c;ll j=find(x);
		if(j!=-1) return i-j;
		if(i>c) return -1;
	}
}
