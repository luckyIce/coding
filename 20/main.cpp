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
    int x=0;
    for(auto i:nums){
        x^=i;
    }
    return x;
}

