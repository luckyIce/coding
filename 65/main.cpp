/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
    void insert_back(int x){
        ListNode* node=new ListNode(x);
        ListNode* p=this->next;
        if(!p){
            this->next=node;
        }
        else{
            while(p&&p->next){
                p=p->next;
            }
            p->next=node;
        }
    }
    void print(){
        ListNode* p=next;
        while (p) {
            cout<<p->val<<',';
            p=p->next;
        }
    }
    void destructor(){
        auto p=next;
        while(p){
            auto q=p;
            p=p->next;
            delete q;
        }
    }
};
ListNode* partition(ListNode *head,int x){
    ListNode leftDummy(-1);
    ListNode rightDummy(-1);
    for(auto p=head;p;p=p->next){
        if(p->val<x){
            leftDummy.insert_back(p->val);
        }
        else{
            rightDummy.insert_back(p->val);
        }
    }
    auto p=leftDummy.next;
    for(;p->next;p=p->next);
    p->next=rightDummy.next;
    return leftDummy.next;
}
int main() {
   vector<int> nums={1,3,4,32,5,6};
   ListNode dummy(-1);
   for(auto num:nums){
       dummy.insert_back(num);
   }
   int x=6;
   auto p=partition(dummy.next,x);
   dummy.destructor();
   dummy.next=p;
   dummy.print();
   dummy.destructor();
    return 0;
}

