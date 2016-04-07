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
void reverse(ListNode *head){
    ListNode dummy(-1);
    dummy.next=nullptr;
    ListNode *cur=head;
    cur&&ListNode *post=cur->next;
    //头插法
    while(cur){
        post=cur->next;
        cur->next=dummy.next;
        dummy.next=cur;
        cur=post;
    }
    //reset head
    head=dummy.next;
}
void reorderList(ListNode *head){
    ListNode *slow=head;
    ListNode *fast=head;
    ListNode *prev=nullptr;
    // find division point
    while(fast&&fast->next){
        prev=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    //division list into two half lists
    prev->next=nullptr;
    //reverse the latter list
    reverse(slow);
    ListNode *first=head;
    ListNode *second=slow;
    ListNode *post_first=nullptr;
    while(first->next){
        post_first=first->next;
        first->next=slow;
        slow=slow->next;
        first->next->next=post_first;
        first=post_first;
    }
    first->next=slow;
}
