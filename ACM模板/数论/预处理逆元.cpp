const int mod=998244353;
int inv[100007];
void pre_inv(int n){
    inv[1]=1;
    for(int i=2;i<=n;i++) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
}