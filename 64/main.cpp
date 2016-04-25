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
ListNode *reverseBetween(ListNode* head,int m,int n){
    ListNode dummy(-1);
    dummy.next=head;
    auto pre_m=&dummy;
    int i=1;
    while(i<m){
        pre_m=pre_m->next;
        ++i;
    }
    auto p_m=pre_m->next;
    auto pre_n=pre_m;
    while(i<n){
        pre_n=pre_n->next;
        ++i;
    }
    auto p_n=pre_n->next;
    //先取出m到n部分，并将m和n对调
    pre_n->next=p_m;
    //把m之前的部分和mn部分连接，把n之后的部分和mn部分连接
    pre_m->next=p_n;
    auto q=p_m->next;
    p_m->next=p_n->next;
    p_n->next=q;
    return dummy.next;
}
int main() {
    ListNode dummy(-1);
    for(int i=1;i<6;i++){
        dummy.insert_back(i);
    }
    reverseBetween(dummy.next,2,5);
    dummy.print();
    dummy.destructor();

    return 0;
}
