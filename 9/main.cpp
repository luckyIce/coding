/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
void swap(int &a,int &b){
    int tmp=a;
    a=b;
    b=tmp;
}
void nextPermutation(vector<int>& nums){
    //reverse iterate the sequence to find the first item that disable reverse incresed queue
    for(auto it=nums.rbegin()+1;it<nums.rend();it++){
        if((*it)<(*(it-1))){
            break;
        }
    }
    if(it!=nums.rend()){
        //find in the right side a item which is bigger than *it
        for(auto it_swap=nums.rbegin();it_swap<nums.rend();it_swap++)){
            if((*it_swap)>(*it)){
                break;
            }
        }
        //swap two items that found before
        //reverse the sequence from [rbegin,it)
        swap(*it,*it_swap);

    }
    auto beg=nums.rbegin();
    auto end=it;
    while(beg!=end){
        swap(*beg,*(end-1));
        ++beg;
        --end;
    }
}

