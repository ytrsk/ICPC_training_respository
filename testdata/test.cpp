#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("test.in","w",stdout);
    int r=10;
    while(r--){
        int n=100000;int m=200000;
        cout<<n<<" "<<m<<endl;
        for(int i=2;i<=n;i++){
            cout<<i<<" "<<rand()%(i-1)+1<<endl;
        }
        for(int i=1;i<=m-(n-1);i++){
            int x=rand()%n+1,y=rand()%n+1;
            cout<<x<<" "<<y<<endl;
        }
        int q=1000;
        cout<<q<<endl;
        for(int i=1;i<=q;i++){
            int x=rand()%n+1,y=rand()%n+1;
            cout<<x<<" "<<y<<endl;
        }
    }
    printf("0 0");
    return 0;
}
