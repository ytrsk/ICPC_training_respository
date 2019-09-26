inv[1]=1;
for(int i=2;i<=n;i++) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
