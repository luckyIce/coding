/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int removeDuplicates(vector<int> nums){
    int times=0;
    int index=0;
    for(auto num:nums){
        if(index==0||nums[index-1]!=num){
            nums[index]=num;
            index++;
            times=1;
        }
        else if(nums[index-1]==num&&times==1){
            nums[index]=num;
            index++;
            times=2;
        }
    }
    return index;
}
int main(){
    vector<int> nums={1,1,1,1,1,2,1};
    cout<<removeDuplicates(nums);
    return 0;
}

