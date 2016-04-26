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
            cout<<p->val;
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
ListNode* removeNthFromEnd(ListNode* head,int n){
    ListNode dummy(-1);
    dummy.next=head;
    auto p=head;//pre of the deleted one
    auto r=head;
    for(int i=0;i<n;i++){
        r=r->next;
    }
    while(r->next){
        p=p->next;
        r=r->next;
    }
    auto q=p->next;
    p->next=q->next;
    delete q;
    return dummy.next;
}
int main() {
   vector<int> nums={1,2,3,4,5};
   ListNode dummy(-1);
   for(auto num:nums){
       dummy.insert_back(num);
   }
   int n=2;
   auto p=removeNthFromEnd(dummy.next,n);
   dummy.next=p;
   dummy.print();
   dummy.destructor();
    return 0;
}

