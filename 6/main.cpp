/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
using namespace std;
vector<int> twoSum(vector<int>& nums,int target){
    unordered_map<int,int> mapping;
    for(int i=0;i<nums.size();i++){
        mapping[nums[i]]=i;
    }
    vector<int> result;
    for(int i=0;i<nums.size();i++){
        const int gap=target-nums[i];
        if(mapping.find(gap)!=mapping.end()&&mapping.find(gap)!=mapping[nums[i]]){
            result.push(min(mapping.find(gap),mapping[nums[i]]));
            result.push(max(mapping.find(gap),mapping[nums[i]]));
            break;
        }
    }
    return result;
}

