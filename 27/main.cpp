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
    ListNode(int x):val(x),next(nullptr)
};
ListNode* removeNthFromEnd(ListNode* head,int n){
    ListNode dummy(-1);
    dummy.next=head;
    ListNode* p=head;
    ListNode* q=head;
    int i=0;
    while (i<n) {
        q=q->next;
        i++;
    }
    while (q->next) {
        p=p->next;
        q=q->next;
    }
    ListNode *r=p->next;
    p->next=r->next;
    delete r;
    return dummy.next;
}
