const ll mod=1e13+7;
typedef long long ll;
ll fm(ll a,ll b) {
    return (a*b - (ll)((long double)a/mod*b)*mod+mod)%mod;
}
