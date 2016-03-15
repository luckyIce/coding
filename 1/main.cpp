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
    if(nums.empty()){
        return 0;
    }
    int index=0;
    for(int i=1;i<nums.size();i++){
        if(nums[index]!=nums[i]){
            nums[++index]=nums[i];
        }
    }
    return index+1;
}
int main(){

}
