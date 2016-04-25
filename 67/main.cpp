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
ListNode* deleteDuplicates(ListNode* head){
    ListNode dummy(-1);
    dummy.next=head;
    auto pre=&dummy;
    auto p=pre->next;
    while(p){
        if(p->next&&p->val==p->next->val){
            int tmp=p->val;
            for(auto r=p;p;r=r->next){//remove equal items
                if(r->val==tmp){
                    pre->next=r->next;
                    delete r;
                }
                else{
                    p=r;
                    break;
                }
            }
        }
        else{
            pre=p;
            p=p->next;
        }
    }
    return dummy.next;
}
int main() {
    vector<int> nums={1,1,1,2,3};
    ListNode dummy(-1);
    for(auto num:nums){
        dummy.insert_back(num);
    }
    auto p=deleteDuplicates(dummy.next);
    dummy.next=p;
    dummy.print();
    dummy.destructor();
    return 0;
}

