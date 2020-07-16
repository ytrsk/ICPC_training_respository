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
string s[maxn],a;
int main(){
    int t=read();
    while(t--){
        int n=read();
        cin>>a;int pos=0;
        for(int i=0;i<n;i++){
            s[i]=a.substr(i,n-i);
            if(i) {s[i]+=a.substr(0,i);}
            if((n-i)%2==1){
                for(int k=n-(i);k<=n-(i)+(i)/2-1;k++){
                    swap(s[i][k],s[i][n-1-(k-(n-(i)))]);
                    //cout<<k<<" "<<n-1-(k-n+(i+1))<<endl;
                }
            }
       //     cout<<s[i]<<endl;
            if(s[i]<s[pos]) pos=i;
          
        }
        cout<<s[pos]<<"\n";
        cout<<pos+1<<"\n";
    }
    return 0;
}