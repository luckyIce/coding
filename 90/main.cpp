/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
void calGaussianKernel(float* kernel,int size,double sigma){
    double scale=-0.5/(sigma*sigma);
    const double PI=3.141592653;
    double cons=-scale/PI;
    double sum=0;
    for(int i=0;i<size;i++){
        for (int j = 0; j < size; ++j) {
            int x=i-size/2;
            int y=j-size/2;
            kernel[i*size+j]=cons*exp(scale*(x*x+y*y));
            sum+=kernel[i*size+j];
        }
    }
    for (int i = 0; i < size*size; ++i) {
        kernel[i]/=sum;
    }
}
int main(){
    int size=3;
    float* data=new float[size*size];
    double sigma=0.84089642;
    calGaussianKernel(data,size,sigma);
    for (int i = 0; i < size*size; ++i) {
        if(i%size==0){
            cout<<endl;
        }
        cout<<data[i]<<" ";

    }
    delete []data;
    return 0;
}

