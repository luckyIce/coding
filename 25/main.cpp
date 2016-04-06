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
ListNode *deleteDuplicates(ListNode *head){
    if(head==nullptr) return head;
    ListNode dummy(-1);
    dummy.next=head;
    ListNode *cur=head;
    ListNode *prev=&dummy;
    ListNode *post=nullptr;
    while(cur){
        //decide whether current node is a duplicated one
        if(post&&post->val!=cur->val){//if not test next item
            cur=post;
            post=post->next;
            prev=cur;
        }
        else{//remove duplicate
            int value=cur->val;
            while(cur&&cur->val==value){
                prev->next=cur->next;
                delete cur;
                cur=prev->next;
            }
        }

    }
    if(prev){
        prev->next=nullptr;
    }

}
