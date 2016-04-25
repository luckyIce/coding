/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int singleNumber(vector<int>& nums){
    int N=sizeof(int)*8;
    vector<int> count(N,0);
    for(int i=0;i<N;i++){
        for (int j = 0; j < nums.size(); ++j) {
            count[i]+=(nums[j]>>i)&0x1;
           count[i]%=3;
        }
    }
    int result=0;
    for (int i = 0; i < N; ++i) {
        result+=count[i]<<i;
    }
    return result;
}
int main(){
    vector<int> nums={1,3,3,4,5,1,3,1,4,4};
    cout<<singleNumber(nums);
    return 0;
}

