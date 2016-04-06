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
void rotateRight(ListNode *head,int k){
    ListNode dummy(-1);
    dummy.next=head;
    if(head==nullptr||k==0)return head;
    ListNode *rotate=head;
    ListNode *rotate_prev=&dummy;
    ListNode *last=rotate->next;
    ListNode *last_prev=rotate;
    int i=1;
    while(i<k){
        last=last->next;
        last_prev=last_prev->next;
        i++;
    }
    while(last){
        rotate=rotate->next;
        rotate_prev=rotate_prev->next;
        last_prev=last_prev->next;
        last=last->next;
    }
    rotate_prev->next=nullptr;
    dummy->next=rotate;
    last_prev->next=head;
}

