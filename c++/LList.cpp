#include <bits/stdc++.h>
#define T pair<int,int>
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
void addition(LList<T> &a,LList<T> &b,LList<T> &c){
    c.clear();
    a.moveToStart();
    b.moveToStart();
    int cnt1=0,cnt2=0;
    while(cnt1<a.length()&&cnt2<b.length()){
        T nowa=a.getValue(),nowb=b.getValue();
        if(nowa.second==nowb.second){
            if(nowa.first+nowb.first!=0) c.append(make_pair(nowa.first+nowb.first,nowa.second));
            a.next();b.next();cnt1++;cnt2++;
        }
        else if(nowa.second>nowb.second) c.append(nowa),a.next(),cnt1++;
        else c.append(nowb),b.next(),cnt2++;
    }
    while(cnt1<a.length()){
        T nowa=a.getValue();
        cnt1++;c.append(nowa);a.next();
    }
    while(cnt2<b.length()){
        T nowb=b.getValue();
        cnt2++;c.append(nowb);b.next();
    }
}
void multi(LList<T> &a,LList<T> &b,LList<T> &c){
    c.clear();a.moveToStart();
    LList<T> add_res;
    for(int i=0;i<a.length();i++){
        b.moveToStart();
        LList<T> temp;
        T nowa=a.getValue();
        for(int k=0;k<b.length();k++){
            T nowb=b.getValue();
            temp.append(make_pair(nowa.first*nowb.first,nowa.second+nowb.second));
            b.next();
        }
        addition(temp,c,add_res);
        c.clear();
        add_res.moveToStart();
        for(int k=0;k<add_res.length();k++){
            c.append(add_res.getValue());
            add_res.next();
        }
        add_res.clear();
        a.next();
    }
}
void print(LList<T> &x){
    x.moveToStart();
    cout<<x.length()<<"\n";
    for(int i=0;i<x.length();i++){
        cout<<x.getValue().first<<" "<<x.getValue().second<<"\n";x.next();
    }
}
int main(){
    LList<T> a;LList<T> b;LList<T> ans_add,ans_mul;
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        a.append(make_pair(x,y));
    }
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        b.append(make_pair(x,y));
    }
    addition(a,b,ans_add);
    print(ans_add);
    multi(a,b,ans_mul);
    print(ans_mul);
    return 0;
}
