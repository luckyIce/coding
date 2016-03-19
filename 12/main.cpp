/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//对于每个柱子，找到其左右两边最高的柱子，该柱子能容纳的水的面积就是min(max_left,max_right)-height
int trap(const vector<int>& A){
    const int n=A.size();
    int *max_left=new int[n]();
    int *max_right=new int[n]();
    max_left[0]=0;
    max_right[n-1]=0;
    for(int i=1;i<n;i++){
        max_left[i]=max(max_left[i-1],A[i]);
        j=n-1-i;
        max_right[j]=max(max_right[j+1],A[j]);
    }
    int sum=0;
    for(int i=1;i<n-1;i++){
        int height=min(max_left[i],max_right[i]);
        if(height>A[i]){
            sum+=height-A[i];
        }
    }
    delete[] max_left;
    delete[] max_right;
    return sum;
}

