/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> twoSum(const vector<int>& nums,int target){
    unordered_map<int,int> mapping;
    vector<int> result;
    for(int i=0;i<nums.size();i++){
        mapping[nums[i]]=i+1;//index start from zero
    }
    for(int i=0;i<nums.size();i++){
        int gap=target-nums[i];
        if(mapping.find(gap)!=mapping.end()&&gap>nums[i]){
            result.push_back(i+1);
            result.push_back(mapping[gap]);
            break;
        }
    }
    return result;
}
int main(){
    vector<int> nums={2,7,11,15};
    int target=9;
    auto result=twoSum(nums,target);
    return 0;
}

