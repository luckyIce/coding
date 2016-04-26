/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
    void insert_back(int x){
        ListNode* node=new ListNode(x);
        ListNode* p=this->next;
        if(!p){
            this->next=node;
        }
        else{
            while(p&&p->next){
                p=p->next;
            }
            p->next=node;
        }
    }
    void print(){
        ListNode* p=next;
        while (p) {
            cout<<p->val;
            p=p->next;
        }
    }
    void destructor(){
        auto p=next;
        while(p){
            auto q=p;
            p=p->next;
            delete q;
        }
    }
};
ListNode* reverse(ListNode* head){
    //头插法会reverse输入元素
    ListNode dummy(-1);
    ListNode dummy2(-1);
    dummy.next=head;
    auto q=dummy.next;
    auto p=dummy.next;
    while(p){
        q=p;
        dummy.next=p->next;//delete p
        p=dummy.next;
        q->next=dummy2.next;//insert p
        dummy2.next=q;
    }
    return dummy2.next;
}
ListNode* reorderList(ListNode* head){
    ListNode dummy(-1);
    dummy.next=head;
    auto slow=&dummy;
    auto fast=&dummy;
    while(fast&&fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    ListNode dummy2(-1);
    dummy2.next=slow->next;//断开
    slow->next=nullptr;
    dummy2.next=reverse(dummy2.next);
    ListNode dummy3(-1);
    auto p=dummy.next;
    auto q=dummy2.next;
    auto r=&dummy3;
    while(p&&q){
        dummy.next=p->next;
        dummy2.next=q->next;
        r->next=p;
        r=p;
        r->next=q;
        r=q;
        p=dummy.next;
        q=dummy2.next;
    }
    if(p){
        r->next=p;
        r=p;
    }
    if(q){
        r->next=q;
        r=q;
    }
    r->next=nullptr;
    return dummy3.next;
}
int main() {
    ListNode dummy(-1);
    for (int i = 0; i < 4; ++i) {
        dummy.insert_back(i+1);
    }
    dummy.next=reorderList(dummy.next);
    dummy.print();
    dummy.destructor();
    return 0;
}


