/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int leftMost(const vector<int>& nums,int index){
    int value=nums[index];
    int i=index;
    for(;i>=0;i--){
        if(nums[i]<value){
            break;
        }
    }
    return i+1;
}
int rightMost(const vector<int>& nums,int index){
    int value=nums[index];
    int i=index;
    for(;i<nums.size();i++){
        if(nums[i]<value){
            break;
        }
    }
    return i-1;
}
int LargestRectangle(const vector<int>& nums){
    int largest=0;
    for(int i=0;i<nums.size();i++){
        largest=max(largest,nums[i]*(rightMost(nums,i)-leftMost(nums,i)+1));
    }
    return largest;
}
int main() {
   vector<int> nums={2,1,5,6,2,3};
   cout<<LargestRectangle(nums)<<endl;
    return 0;
}

