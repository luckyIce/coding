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
ListNode* removeDuplicates(ListNode *head){
    auto q=head;
    auto p=q->next;
    while(p){
        if(p->val==q->val){
            q->next=p->next;
            delete p;
        }
        else{
            q=q->next;
        }
    p=q->next;
    }
    return head;
}
int main() {
   vector<int> nums={1,1,2};
   ListNode dummy(-1);
   for(auto num:nums){
       dummy.insert_back(num);
   }
   auto p=removeDuplicates(dummy.next);
   dummy.print();
   dummy.destructor();
    return 0;
}



