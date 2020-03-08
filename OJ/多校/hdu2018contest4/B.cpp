#include <iostream>
#include <string>
using namespace std;


struct ListNode
{
    int value;
    ListNode* next;
    ListNode(int v)
    : value(v), next(NULL) {}
};

void display(ListNode* head) {
    while (head != NULL) {
        cout << head->value << ' ';
        head = head->next;
    }
    cout << endl;
}
ListNode* sortList(ListNode* head) {
    // 注意这样写，是不需要额外判断head是否为NULL的
    ListNode *newHead = NULL, *toInsert = head;
    while (toInsert != NULL) {
        ListNode *current = newHead, *last = NULL, *next = toInsert->next;
        // 从头往后找到第一个大于toInsert->value的元素
        while (current != NULL && current->value <= toInsert->value) {
            last = current;
            current = current->next;
        }

        if (last == NULL) {
            // 如果比任何已排序的数字都要小，那么就成为新的头部
            toInsert->next = newHead;
            newHead = toInsert;
        } else {
            // 否则插入到last的后面
            toInsert->next = last->next;
            last->next = toInsert;
        }
        display(newHead);
        toInsert = next;
    }
    return newHead;
}

// 打印链表



int main() {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);
    display(head);

    ListNode* head2 = sortList(head);
    display(head2);

    return 0; 
}