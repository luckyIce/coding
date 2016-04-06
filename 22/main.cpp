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
ListNode* reverseBetween(ListNode *head,int m,int n){
    //头插法
    ListNode *dummy(-1);
    dummy.next=head;
    ListNode* prev=&dummy;
    for(int i=0;i<m-1;i++){
        prev=prev->next;
    }
    //prev代表m元素前的元素
    ListNode *cur=prev->next;
    ListNode *post=cur->next;
    for(int i=m;i<n;i++){
        prev->next=post;
        cur->next=prev->next;
        prev->next=cur;
        cur=cur->next;
        post=post->next;
    }
    return dummy;
}
