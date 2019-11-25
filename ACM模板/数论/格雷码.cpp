int e1,ans[100007];
void gray_code(int x){
    e1=1;ans[e1]=0;
    for(int i=0;i<x;i++){
        for(int k=e1;k;k--) ans[++e1]=ans[k]^(1<<i);
    }
}
