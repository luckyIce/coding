/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
using namespace std;
int climbStairs(int n){
    int pre1=1;//n为0时只有一种方法
    int pre2=2;//n为1时只有一种方法
    int result=0;
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    for(int i=3;i<=n;i++){
        result=pre1+pre2;
        pre1=pre2;
        pre2=result;
    }
    return result;
}
int main() {
   int n=4;
   cout<<climbStairs(n);
    return 0;
}
