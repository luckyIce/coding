/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int climbStairs(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int oneStepLess=1;
    int twoStepLess=0;
    int curr=0;
    for(int i=2;i<=n;i++){
        curr+=oneStepLess+twoStepLess;
        twoStepLess=oneStepLess;
        oneStepLess=curr;
    }
    return curr;
}

