/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > threeSum(vector<int>& nums){
    vector<vector<int> > result;
    if(nums.size()<3){
        return result;
    }
    const int target=0;
    sort(nums.begin(),nums.end());
    for(auto i=nums.begin();i<nums.end()-2;i++){
        if((i-1)&&*i==*(i-1)){
            i++;
            continue;
        }
        auto j=i+1;//*j stands for the smallest item
        auto k=nums.end()-1;//*k stands for the biggest item
        while(j<k){
            if(*i+*j+*k<target){
                ++j;
            }
            else if(*i+*j+*k>target){
                --k;
            }
            else{
                vector<int> tmp;
                tmp.push_back(*i);
                tmp.push_back(*j);
                tmp.push_back(*k);
                result.push_back(tmp);
                ++j;
                --k;
            }
        }
    }
    return result;
}

