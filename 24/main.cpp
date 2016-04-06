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
void removeDuplicates(ListNode *head){
    ListNode *tail=head;
    ListNode *cur=head->next;
    while(cur){
        if(cur->val==tail->val){
            tail->next=cur->next;
            delete cur;
        }
        else{
            tail=cur;
        }
        cur=tail->next;
    }
}

