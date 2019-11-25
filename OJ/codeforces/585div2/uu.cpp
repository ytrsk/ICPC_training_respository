#include  <bits/stdc++.h>
using namespace std;
int main()
{

    int last=clock();
    while(1){
        if(clock()-last>20){ofstream out;
    out.open("Clock");
            time_t t = time(NULL);
            tm *tp = localtime(&t);
            out<<tp->tm_hour<<":"<<tp->tm_min<<":"<<tp->tm_sec;
            last=clock();out.close();
        }

    }
	return 0;
}
