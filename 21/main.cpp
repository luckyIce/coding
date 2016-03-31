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
ListNode *addTwoNumbers(ListNode *l1,ListNode *l2){
    ListNode dummy(-1);//头节点
    int carry=0;
    ListNode *pa=l1,*pb=l2;
    int tmp=0;
    int value=0;
    while(pa&&pb){
        tmp=pa->val+pb->val;
        pa=pa->next;
        pb=pb->next;
        carry=tmp/10;
        value=tmp%10;
        dummy->next=ListNode(value);
    }
    while(pa){
        value=pa->val;
        dummy->next=ListNode(value);
        pa=pa->next;
    }
    while(pb){
        value=pb->val;
        dummy->next=ListNode(value);
        pb=pb->next;
    }
    return dummy;
}

