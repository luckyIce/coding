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
    int index=0;
    for(auto num:nums){
        if(index==0||num!=nums[index-1]){
            nums[index]=num;
            index++;
        }
    }
    return index;
}
int main(){
    vector<int> nums={1,1,2};
    cout<<removeDuplicates(nums);
    return 0;
}

