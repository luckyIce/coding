/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
//rotate matrix by 90 degree
void swap(int &x,int &y){
    int tmp=x;
    x=y;
    y=tmp;
}
void rotate(vector<vector<int> >& matrix){
    //rotate matrix by 90 digree swaps x and y coordinate
    const int n=matrix.size();
    //computer stores data from top bottom while in math y axis goes from bottom to top
    //so we first stores data from bottom to top
    for(int j=0;j<n;j++){//swap row i with row n-i
        for(int i=0;i<n/2;i++){
            swap(matrix[i][ j],matrix[n-1-i][j]);
        }
    }
    //swap points above the line which is the positive diagonal with those under the line
    for(int j=0;j<n;j++){
        for(int i=j+1;i<n;i++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
}

