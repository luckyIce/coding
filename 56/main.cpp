/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
void addOne(vector<int>&nums, int digit){
    int carry=digit;
    int tmp;
    for(auto it=nums.rbegin();it!=nums.rend()&&carry!=0;it++){
        tmp=*it+carry;
        *it=tmp%10;
        carry=tmp/10;
    }
    if(carry!=0){
        nums.insert(nums.begin(),carry);
    }
}
int main() {
   vector<int> nums={8,9,9,9};
   int digit=5;
   addOne(nums,digit);

    return 0;
}

