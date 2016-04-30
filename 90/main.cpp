/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
void calGaussianKernel(float* data,int r){
    for(int i=0;i<r;i++){
            data[i]=exp(i-r/2);
    }
}
int main(){
    int r=3;
    float* data=new float[r];
    calGaussianKernel(data,r);
    delete []data;
    return 0;
}

