/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int removeTarget(vector<int>& nums,int target){
    int index=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=target){
            nums[index++]=nums[i];
        }
    }
    return index;
}
int main(){
    vector<int> nums={1,1,3,5,43,3,5,3};
    int target=3;
    cout<<removeTarget(nums,target);
    return 0;
}

