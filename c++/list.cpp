#include <bits/stdc++.h>
#define deT int
using namespace std;
template <typename E> class Link{
private:
    static Link<E> * freelist;
public:
    E element;
    Link* next;
    Link* prev;
    Link(const E& it,Link *prevp,Link * nextp){
        element = it;
        prev = prevp;
        next = nextp;
    }
    Link(Link* prevp = NULL,Link* nextp = NULL) {
        prev = prevp;
        next = nextp;
    }

    void* operator new(size_t){
        if (freelist == NULL) return ::new Link;
        Link<E> *temp = freelist;
        freelist = freelist->next;
        return temp;
    }
    void operator delete(void *ptr){
        ((Link<E> *)ptr)->next = freelist;
        freelist = (Link<E> *)ptr;
    }

};
template <typename E> Link<E> * Link<E>::freelist = NULL;
template <typename E> class LList{
private:
    Link<E>* head;
    Link<E>* tail;
    Link<E>* curr;
    int cnt;
    void init(){
        curr = head = new Link<E>;
        curr->next = tail = new Link<E>(head);

        cnt = 0;
    }
    void removeall(){
        while (head != NULL){
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public:
    LList(){
        init();
    }
    ~LList(){
        removeall();
    }
    void clear(){
        removeall();
        init();
    }
    void insert(const E& it){
        curr->next = curr->next->prev = new Link<E>(it,curr,curr->next);
        cnt ++;
    }
    void append(const E& it){
        tail->prev = tail->prev->next = new Link<E>(it,tail->prev,tail);
        cnt ++;
    }
    void prev() {
        if (curr == head) return;
        curr = curr->prev;
    }
    void next() {
        if (curr != tail) curr = curr->next;
    }
    int length() const {
        return cnt;
    }
    const E& getValue() const {
        return curr->next->element;
    }
    void moveToStart() {
        curr = head;
    }
    void moveToEnd() {
        curr = tail;
    }
};
void addition(LList<deT> &a,LList<deT> &b,LList<deT> &c){
    c.clear();
    int x=min(a.length(),b.length());
    a.moveToStart();
    b.moveToStart();
    for(int i=0;i<x;i++){
        c.append(a.getValue()+b.getValue());
        a.next();b.next();
    }
    int y=max(a.length()-x,b.length()-x);
    if(a.length()>x){
        while(y--){
            c.append(a.getValue());
            a.next();
        }
    }
    else if(b.length()>x){
        while(y--){
            c.append(b.getValue());
            b.next();
        }
    }
}
void multi(LList<deT> &a,LList<deT> &b,LList<deT> &c){
    c.clear();a.moveToStart();
    LList<int> res;
    for(int i=0;i<a.length();i++){
        b.moveToStart();
        LList<int> res1;
        for(int k=0;k<i;k++) res1.append(0);
        for(int k=0;k<b.length();k++){
            res1.append(a.getValue()*b.getValue());
            b.next();
        }
        addition(res1,c,res);
        c.clear();
        res.moveToStart();
        for(int k=0;k<res.length();k++){

            c.append(res.getValue());
            res.next();
        }
        res.clear();
        a.next();
    }
}
void print(LList<int> &x){
    x.moveToStart();
    for(int i=0;i<x.length();i++){
        cout<<x.getValue()<<" ";x.next();
    }
    cout<<"\n";
}
int main(){
    LList<int> a;LList<int> b;LList<int> ans_add;
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;cin>>x;a.append(x);
    }
    for(int i=1;i<=m;i++){
        int x;cin>>x;b.append(x);
    }
    addition(a,b,ans_add);
    print(ans_add);
    LList<int> ans_mul;
    multi(a,b,ans_mul);
    print(ans_mul);
    return 0;
}
