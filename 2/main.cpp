/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int>& nums){
    if(nums.size()<=2)return nums.size();
    int index=1;
    for(int i=2;i<nums.size();i++){
        if(nums[i]!=nums[index-1]){
            nums[++index]=num[i];
        }
    }
    return index;
}

