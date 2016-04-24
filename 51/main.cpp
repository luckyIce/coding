/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
void nextPermutation(vector<int>& nums){
    auto it=nums.rbegin()+1;
    for(;it!=nums.rend();it++){//find first item
        if(*it<*(it-1)){
            break;
        }
    }
    if(it==nums.rend()){
        reverse(nums.begin(),nums.end());
    }
    auto change=nums.rbegin();
    for(;*change<=*it;change++);
    swap(*it,*change);
    reverse(nums.rbegin(),it);
}
int main(){
    vector<int> nums={6,8,7,4,3,2};
    nextPermutation(nums);
    return 0;
}

