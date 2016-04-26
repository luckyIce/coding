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
ListNode* rotateRight(ListNode* head,int n){
    int len=0;
    auto p=head;
    for(;p->next;p=p->next){
        len++;
    }
    len++;
    p->next=head;
    n=len-n%len;
    auto q=head;
    for(int i=1;i<n;i++){
        q=q->next;
    }
    head=q->next;
    q->next=nullptr;
    return head;
}
int main() {
    ListNode dummy(-1);
    for(int i=1;i<6;i++){
        dummy.insert_back(i);
    }
    int n=4;
    auto p=rotateRight(dummy.next,n);
    dummy.next=p;
    dummy.print();
    dummy.destructor();
    return 0;
}



