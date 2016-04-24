/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int canCompleteCircuit(vector<int>& gas,vector<int>& cost){
    int total=0;
    int index=0;
    int i=0;
    for(;i<gas.size();){
        total+=gas[i]-cost[i];
        if(total<0){
            total=0;
            index=i+1;
        }
        i++;
    }
    if(total>=0){
        for(int j=0;j<i;j++){
            total+=gas[i]-cost[i];
            if(total<0){
                return -1;
            }
        }
        return index+1;
    }
    return -1;
}
int main() {
   vector<int> gas={5,6,4,5,6,5,8};
   vector<int> cost={4,5,8,5,5,6,4};
   cout<<canCompleteCircuit(gas,cost);
    return 0;
}

