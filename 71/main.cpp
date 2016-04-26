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
int swapPair(ListNode* pre){
    if(!pre){
        return -1;
    }
    ListNode *p=pre->next;
    if(!p){
        return -1;
    }
    ListNode *q=p->next;
    if(!q){
        return -1;
    }
    p->next=q->next;//delete q
    q->next=p;//头插法
    pre->next=q;
    return 0;
}
ListNode* swapPairs(ListNode* head){
    ListNode dummy(-1);
    dummy.next=head;
    auto pre_p=&dummy;
    while(swapPair(pre_p)==0){
        pre_p=pre_p->next->next;
    }
    return dummy.next;
}
int main() {
    vector<int> nums={1,2,3,4};
    ListNode dummy(-1);
    for(auto num:nums){
        dummy.insert_back(num);
    }
    dummy.next=swapPairs(dummy.next);
    dummy.print();
    dummy.destructor();

    return 0;
}

