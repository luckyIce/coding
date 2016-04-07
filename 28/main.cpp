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
ListNode* swapPairs(ListNode *head){
    ListNode dummy(-1);
    dummy.next=head;
    ListNode *h=&dummy;
    ListNode *first=h->next;
    first&&ListNode *second=first->next;
    while(first&&second){
        first->next=second->next;//delete second item from list
        //头插法插入second
        second->next=h->next;
        h->next=second;
        //update h first second
        h=first;
        first=h->next;
        first&&ListNode *second=first->next;
    }
    return dummy.next;
}
