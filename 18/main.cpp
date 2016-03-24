/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int canCompleCircuit(vector<int>& gas,vector<int>& cost){
    int total=0;
    int sum=0;//sum 代表一个小区间的剩余gas
    const int n=gas.size();
    int j=-1;
    for(int i=0;i<n;i++){
        total+=gas[i]-cost[i];
        sum+=gas[i]-cost[i];
        if(sum<0){
            j=i;//这里应该是j＝i+1，我们选择在最后进行修改
            sum=0;
        }
    }
    return total>=0?j+1:-1;
}

