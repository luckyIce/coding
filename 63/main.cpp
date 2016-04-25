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
ListNode* addTwo(ListNode h1,ListNode h2){
    ListNode dummy(-1);
    int carry=0;
    auto p1=h1.next,p2=h2.next;
    int tmp;
    while(p1&&p2){
        tmp=p1->val+p2->val+carry;
        dummy.insert_back(tmp%10);
        carry=tmp/10;
        p1=p1->next;
        p2=p2->next;
    }
    while (carry!=0) {
        while(p1){
            tmp=p1->val+carry;
            dummy.insert_back(tmp%10);
            carry=tmp/10;
            p1=p1->next;
        }
        while(p2){
            tmp=p2->val+carry;
            dummy.insert_back(tmp%10);
            carry=tmp/10;
            p2=p2->next;
        }
    }
    while(p1){
        dummy.insert_back(p1->val);
    }
    while(p2){
        dummy.insert_back(p2->val);
    }
    return dummy.next;
}
int main() {
    ListNode head1(-1);
    head1.insert_back(2);
    head1.insert_back(4);
    head1.insert_back(3);
    ListNode head2(-1);
    head2.insert_back(5);
    head2.insert_back(6);
    head2.insert_back(4);
    ListNode* node=addTwo(head1,head2);
    ListNode dummy(-1);
    dummy.next=node;
    dummy.print();
    auto p=dummy.next;
    dummy.destructor();
    return 0;
}

