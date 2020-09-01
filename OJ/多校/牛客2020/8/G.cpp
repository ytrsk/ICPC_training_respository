#include <bits/stdc++.h>
using namespace std;
const char *cmp[4][3] {
	{"one","two","three"},
	{"diamond","squiggle","oval"},
	{"solid","striped","open"},
	{"red","green","purple"}
};
void read(char *buf) {
	int buflen = 0;
	char c = getchar();
	while (!( (c >= 'a' && c <= 'z') || c == '*')) c = getchar();
	while (( (c >= 'a' && c <= 'z') || c == '*')) {
		buf[buflen++] = c;
		c = getchar();
	}
	buf[buflen] = 0;
}
int a[257][4];
int main() {
	int T,cnt=0;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++) {
		int n;
		scanf("%d",&n);
        bitset<257> ss[4][3];
        bitset<257> S;
        for(int i=1;i<=n;i++) S[i]=1;
		for (int i=1;i<=n;i++) {
			char tmp[4][20];
			for (int j=0;j<4;j++) read(tmp[j]);
			int cur[4] = {3,3,3,3};
            a[i][0]=a[i][1]=a[i][2]=a[i][3]=3;
			for (int j=0;j<4;j++)
				for (int k=0;k<3;k++) if (strcmp(tmp[j],cmp[j][k]) == 0) cur[j] = k,a[i][j]=k;
            for(int j=0;j<4;j++){
                if(a[i][j]<3) ss[j][a[i][j]].set(i);
                else{
                    for(int k=0;k<3;k++) ss[j][k].set(i);
                }
            }
			//cur[4]代表四个属性，值0,1,2代表值，3代表野卡
		}
        int ok=0;
        for(int i=1;i<=n;i++){
            if(ok) break;
            for(int k=i+1;k<=n;k++){
                bitset<257> s;s=S;
                s[i]=s[k]=0;
                if(ok) break;
                for(int j=0;j<4;j++)
                if(a[i][j]<3&&a[k][j]<3){
                    if(a[i][j]==a[k][j]) s&=ss[j][a[i][j]];
                    else s&=ss[j][3-a[i][j]-a[k][j]];
                }
                if(s.count()){
                    int z=s._Find_first();
                    ok=1;
                    printf("Case #%d: %d %d %d\n",++cnt,i,k,z);
                    break;
                }
            }
        }
        if(!ok) printf("Case #%d: -1\n",++cnt);
	}
	return 0;
}