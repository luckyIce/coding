/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int binarySearch(const vector<int> &nums,int value){
    int index=0;
    int begin=0;
    int end=nums.size();
    while(begin!=end){
        const int mid=begin+(end-begin)/2;
        if(nums[mid]==value){
            return mid+1;//index start from 0
        }
        if(nums[begin]<=nums[mid]){//the first half are sorted
            if(nums[mid]>value&&nums[begin]<=value){//value is in the first half
                end=mid;
            }
            else{
                begin=mid+1;
            }
        }
        else{
            if(nums[mid+1]<=value&&nums[end-1]>=value){
                begin=mid+1;
            }
            else{
                end=mid;
            }
        }
    }
    return -1;
}
int main(){
    vector<int> nums={4,5,6,7,0,1,2};
    int value=4;
    cout<<binarySearch(nums,value);
}

