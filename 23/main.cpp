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
ListNode* partition(ListNode* head,int x){
    ListNode left_dummy(-1);
    ListNode right_dummy(-1);
    ListNode *left_tail=&left_dummy;
    ListNode *right_tail=&right_dummy;
    for(ListNode *cur=head;cur;cur=cur->next){
        if(cur->val<x){
            left_tail->next=cur;
            left_tail=cur;
        }
        else{
            right_tail->next=cur;
            right_tail=cur;
        }
    }
    left_tail->next=right_dummy.next;
    right_tail->next=nullptr;

}
