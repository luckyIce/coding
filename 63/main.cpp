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
    void insert_back(ListNode& x){
        ListNode* p=this->next;
        if(!p){
           this->next=&x;
        }
        else{
            while(p&&p->next){
                p=p->next;
            }
            p->next=&x;
        }
    }
    void print(){
        ListNode* p=next;
        while (p) {
            cout<<p->val;
            p=p->next;
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
        ListNode* node= new ListNode(tmp%10);
        dummy.insert_back(*node);
        carry=tmp/10;
        p1=p1->next;
        p2=p2->next;
    }
    while (carry!=0) {
        while(p1){
        tmp=p1->val+carry;
        ListNode* node= new ListNode(tmp%10);
        dummy.insert_back(*node);
        carry=tmp/10;
        p1=p1->next;
        }
        while(p2){
        tmp=p2->val+carry;
        ListNode* node= new ListNode(tmp%10);
        dummy.insert_back(*node);
        carry=tmp/10;
        p2=p2->next;
        }
    }
    while(p1){
        ListNode* node=new ListNode(p1->val);
        dummy.insert_back(*node);
    }
    while(p2){
        ListNode* node=new ListNode(p2->val);
        dummy.insert_back(*node);
    }
    return dummy.next;
}
int main() {
    ListNode head1(-1);
    ListNode a(2);
    head1.insert_back(a);
    ListNode b(4);
    head1.insert_back(b);
    ListNode c(3);
    head1.insert_back(c);
    ListNode head2(-1);
    ListNode d(5);
    head2.insert_back(d);
    ListNode e(6);
    head2.insert_back(e);
    ListNode f(4);
    head2.insert_back(f);
    ListNode* node=addTwo(head1,head2);
    ListNode dummy(-1);
    dummy.next=node;
    dummy.print();
    return 0;
}

