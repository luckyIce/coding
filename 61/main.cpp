/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int singleNumber(const vector<int>& nums){
    int result=0;
    for(auto num:nums){
        result^=num;
    }
    return result;
}
int main(){
    vector<int> nums={1,3,4,3,4,5,1};
    cout<<singleNumber(nums);
    return 0;

}

