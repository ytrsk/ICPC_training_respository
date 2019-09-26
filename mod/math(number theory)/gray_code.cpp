void gray_code(int x){
    cout<<x<<endl;e1=1;
    for(int i=0;i<x;i++){
        for(int k=e1;k;k--) ans[++e1]=ans[k]^now[i];
    }
    for(int i=1;i<=e1;i++) cout<<ans[i]<<" ";
}
