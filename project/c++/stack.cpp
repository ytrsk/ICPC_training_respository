#include <bits/stdc++.h>
using namespace std;
const int defaultSize=600;
template <typename E> class Queue {
private:
  void operator =(const Queue&) {}
  Queue(const Queue&) {}

public:
  Queue() {}
  virtual ~Queue() {}
  virtual void clear() = 0;
  virtual void enqueue(const E&) = 0;
  virtual E dequeue() = 0;
  virtual const E& frontValue() const = 0;
  virtual int length() const = 0;
};
template <typename E> class AQueue: public Queue<E> {
private:
  int maxSize;
  int front;
  int rear;
  E *listArray;

public:
  AQueue(int size =defaultSize) {
    maxSize = size+1;
    rear = 0;  front = 1;
    listArray = new E[maxSize];
  }

  ~AQueue() { delete [] listArray; }
  void clear() { rear = 0; front = 1; }
  void enqueue(const E& it) {
    rear = (rear+1) % maxSize;
    listArray[rear] = it;
  }
  E dequeue() {
    E it = listArray[front];
    front = (front+1) % maxSize;
    return it;
  }

  const E& frontValue() const {
    return listArray[front];
  }
  virtual int length() const
   { return ((rear+maxSize) - front + 1) % maxSize; }
};
template <typename E> class Stack {
private:
    void operator =(const Stack&) {}
    Stack(const Stack&) {}

public:
    Stack() {}
    virtual ~Stack() {}
    virtual void clear() = 0;
    virtual void push(const E& it) = 0;
    virtual E pop() = 0;
    virtual const E& topValue() const = 0;
    virtual int length() const = 0;
};
template <typename E>
class QStack : public Stack<E>{
   private:
     int maxSize;
     AQueue<E> QA;
     AQueue<E> QB;
   public:

     QStack(int size = defaultSize): QA(size), QB(size){
        maxSize = size;
     }
     ~QStack() { }
     void clear(){
         QA.clear();
     }
     void push(const E& it) {
         while(QA.length()) QB.enqueue(QA.dequeue());
         QA.enqueue(it);
         while(QB.length()) QA.enqueue(QB.dequeue());
     }
     E pop() {
         return QA.dequeue();
     }
     const E& topValue() const{
        return QA.frontValue();
     }
     virtual int length() const {
        return QA.length();
     }
};
int a[100007];
int main(){
    int n,m,t;cin>>n>>m>>t;
    QStack<int> A;
    for(int i=1;i<=t;i++){
        A.clear();int top=1,ok=1;
        for(int k=1;k<=n;k++){
            cin>>a[k];
            if(A.length()&&A.topValue()==a[k]) A.pop();
            else if(top>a[k]||A.length()+a[k]-top+1>m){
                ok=0;break;
            }
            else{
                for(int z=top;z<a[k];z++) A.push(z);
                top=a[k]+1;
            }
        }
        if(ok) printf("T\n");
        else printf("F\n");
    }
    return 0;
}
