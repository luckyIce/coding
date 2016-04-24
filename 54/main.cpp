/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int trap(const vector<int>& nums){
    int max=0;
    int index=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>max){
            max=nums[i];
            index=i;
        }
    }
    int height=0;
    int total=0;
    for(int i=0;i<index;i++){
        if(nums[i]>height){
            height=nums[i];
        }
        total+=height-nums[i];
    }
    height=0;
    for(int i=nums.size()-1;i>index;i--){
        if(nums[i]>height){
            height=nums[i];
        }
        total+=height-nums[i];
    }
    return total;
}
int main() {
   vector<int> nums={0,1,0,2,1,0,1,3,2,1,2,1};
   cout<<trap(nums);
    return 0;
}
