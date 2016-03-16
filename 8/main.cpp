/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int removeElement(vector<int>& nums,int target){
    int index=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=target){
            nums[index]=nums[i];
            ++index;
        }
    }
    return index;
}

