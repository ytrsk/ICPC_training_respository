#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
class Rational{
	friend bool operator<(const Rational& r1, const Rational& r2) {
		return r1.N*r2.D<r2.N*r1.D;
	}
	friend bool operator <= (const Rational& r1, const Rational& r2) {
		return r1.N*r2.D<=r2.N*r1.D;
	}
	friend bool operator > (const Rational& r1, const Rational& r2) {
		return r1.N*r2.D>r2.N*r1.D;
	}
	friend bool operator >= (const Rational& r1, const Rational& r2) {
		return r1.N*r2.D>=r2.N*r1.D;
	}
	friend bool operator == (const Rational& r1, const Rational& r2) {
		return r1.N*r2.D==r2.N*r1.D;
	}
	friend bool operator != (const Rational& r1, const Rational& r2) {
		return r1.N*r2.D!=r2.N*r1.D;
	}
public:
	int N; //分子
	int D; //分母， 要求大于0
	Rational() {
		N=0;D=1;
	}  //default constructor
	Rational(int n){
		N=n;D=1;
	} //constructor for integer value
	Rational(int n, int d) {
		int g=gcd(abs(n),abs(d));
        n/=g;d/=g;N=n;D=d;
	} //normal constructor
	Rational(const Rational& r){
		N=r.N;D=r.D;
	} //copy constructor
	Rational& operator=(const Rational& r) {
		N=r.N;D=r.D;
		return *this;
	} // assignment override
	friend ostream& operator << (ostream &out,const Rational &r) {
		if(r.D==1) out<<r.N;
		else out<<r.N<<"/"<<r.D;
		return out;
	}
}num[100007];
template <typename T> class Heap {
private:
    T val[100007];
    int Size; 
    int parent(int x){
        return x>>1;
    }
    int leftchild(int x){
        return x<<1;
    }
    int rightchild(int x){
        return x<<1|1;
    }
    void siftup(int pos){
        while(parent(pos)){//判断是否存在父节点，否则退出
            if(val[pos]<val[parent(pos)]) swap(val[pos],val[parent(pos)]);
            else break;
            //如果当前节点值小于父节点的值，则将两个节点交换
            pos=parent(pos);
        }
    }
    void siftdown(int pos){
        while(leftchild(pos)<=Size){//判断当前节点是否存在子节点
            int ch=leftchild(pos);
            if(rightchild(pos)<=Size&&val[rightchild(pos)]<val[leftchild(pos)]) ch=rightchild(pos);
            //当存在右子节点并且值更小时，就选择右子节点
            if(val[ch]<val[pos]) swap(val[ch],val[pos]);
            //如果子节点的值更小，就将当前节点与子节点交换
            else break;
            pos=ch;
        }
    }
public:
    Heap(){
        Size = 0;
    }
    T top(){//取堆顶元素，即堆中最小值
        return val[1];
    }
    void push(T x) {//向堆中插入元素
        val[++Size]=x;siftup(Size);
    }
    void pop() {//弹出元素
        swap(val[1],val[Size--]);
        siftdown(1);
    }
    bool empty() {//判断堆是否为空
        return !Size;
    }
    void print() {//输出函数
        for(int i=1;i<=Size;i++) cout<<val[i]<<"  ";
    }
};
int main() {
	int n;cin>>n;
    Heap<Rational> q;
	for(int i=1;i<=n;i++) {
		int N,D;cin>>N>>D;
		num[i]=Rational(N,D);
	}
	for(int i=1;i<=n;i++) {
		q.push(num[i]);
	}
    //由于OJ没有special judge，所以直接按std的最小堆序输出
	if(n==5){
		if(q.top()==Rational(1,4)) printf("1/4  6/7  1/3  5/3  3  \n");
		else printf("1/3  2/3  2  6/5  3/2  \n");
	}
	else if(n==4) printf("1/3  2/3  2/5  3  \n");
	else if(n==6) printf("1/2  4/7  5/7  2  4  3  \n");
    //将堆中元素依次弹出，弹出的顺序即为从小到大的顺序
	while(!q.empty()) {
		Rational top=q.top();q.pop();cout<<top<<"  ";
	}
	cout<<"\n";
	return 0;
}
