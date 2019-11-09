#include <bits/stdc++.h>
using namespace std;
int a[500007];
int main(){
    ios::sync_with_stdio(false);
   //freopen("test.in","w",stdout);
    int n=10000,m=5000;
    int z[10007];for(int i=1;i<=n;i++) z[i]=i;random_shuffle(z+1,z+n+1);
    cout<<n<<" "<<m<<endl;
    for(int i=1;i<=n;i++){
        cout<<z[i]<<" ";
    }
    for(int i=1;i<=n;i++) a[i]=i;
    random_shuffle(a+1,a+n+1);
    for(int i=1;i<=m;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
