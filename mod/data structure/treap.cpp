#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
const int maxn=100007;
int tr[maxn][2],e1,r[maxn],root;
inline int min(int a,int b){
	return a<b?a:b;
}
struct string{
	int len;char s[21];
	bool operator < (string a) const{
		for(int i=1;i<=min(len,a.len);i++){
			if(s[i]!=a.s[i]) return s[i]<a.s[i];
		}
		return len<a.len;
	}
	bool operator == (string a) const{
	
		return !(*this<a)&&!(a<*this); 
	}
	bool operator > (string a) const{
		return a<*this;
	}
	bool operator != (string a) const{
		return !(*this==a);
	}
	void print(){
		for(int i=1;i<=len;i++){
			printf("%c",s[i]);
		}
	}
	void input(){
		scanf("%s",s+1);
		len=strlen(s+1);
	}
};
struct node{
	string name,tela,telb,email,home;
	bool operator < (node a) const{
		return name<a.name;
	}
	bool operator > (node a) const{
		return name>a.name;
	}
	bool operator == (node a)const{
		return name==a.name;
	}
	void print_s(){
		name.print();printf("\t");tela.print();printf("\t");telb.print();printf("\t");home.print();printf("\n");
	}
	void print_file(){
		name.print();printf(",");tela.print();printf(",");telb.print();printf(",");home.print();printf("\n");
	}
}n[maxn];
void rotate(int &o,int d){
	int x=tr[o][d^1];tr[o][d^1]=tr[x][d];tr[x][d]=o;o=x;
}
void insert(int &o,node x){
	if(!o){
		n[o=++e1]=x;
		r[e1]=rand();
	}
	else{
		int d=(x<n[o]);
		insert(tr[o][d^1],x);
		if(r[tr[o][d^1]]<r[o]) rotate(o,d); 
	}
}
bool del(int &o,string x){
	if(!o) return false;
	else if(n[o].name!=x){
		int d=(n[o].name<x);
		return del(tr[o][d],x);
	}
	else{
		if((long long)tr[o][0]*tr[o][1]==0LL) o=tr[o][0]+tr[o][1];
		else{
			int d=(r[tr[o][0]]<r[tr[o][1]]);
			rotate(o,d);return del(tr[o][d],x);
		}
	}
	return true;
}
int query(int o,string x){
	if(!o) return -1;
	else if(n[o].name==x) return o;
	else return query(tr[o][n[o].name>x],x);
}
void check_s(int o){
	if(!o) return;
	else{
		check_s(tr[o][0]);n[o].print_s();check_s(tr[o][1]);
	}
}
void check_f(int o){
	if(!o) return;
	else{
		check_f(tr[o][0]);n[o].print_file();check_f(tr[o][1]);
	}
}
int main(){
	srand(time(0));
	printf("1: insert\n2: browse\n3: delete\n4: edit\n5: query\n6: quit\nplease input the index of the operation you wanna execute:\t");
	int index=0;
	while(scanf("%d",&index)==1){
		switch(index){
			case 1:
				{
					node n1;
					printf("name:\t");n1.name.input();
					printf("tela:\t");n1.tela.input();
					printf("telb:\t");n1.telb.input();
					printf("home:\t");n1.home.input();
					insert(root,n1);
					break;
				}
			case 2:
				check_s(root);
				break;
			case 3:
				{
					printf("please input the name:\t");
					string x;x.input();
					if(del(root,x)) printf("delete successfully\n");
					else {
						printf("here is none named ");
						x.print();
						printf("\n");
					}	
					break;
				}
			case 4:
				{
					printf("please input the name:\t");
					string x;x.input();
					int a=query(root,x);
					if(a==-1){
						printf("sorry,we can't find the person named ");x.print();printf("\n");
					}
					else{
						printf("please input the information of the person\n");
						printf("tela:\t");n[a].tela.input();
						printf("telb:\t");n[a].telb.input();
						printf("home:\t");n[a].home.input();
					}
					break;
				}
			case 5:
				{
					printf("please input the name:\t");
					string x;x.input();
					int a=query(root,x);
					if(a==-1){
						printf("sorry,we can't find the person named ");x.print();printf("\n");
					}
					else{
						printf("tela:\t");n[a].tela.print();printf("\n");
						printf("telb:\t");n[a].telb.print();printf("\n");
						printf("home:\t");n[a].home.print();printf("\n");
					}
					break;
				}
			case 6:
				freopen("data.csv","w",stdout);
				check_f(root);
				return 0;
				break;
			default:
				printf("invalid input, please retry\n");
				break;

		}	
		printf("please input the index of the operation you wanna execute:\t");
	}
	return 0;
}
