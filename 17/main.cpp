/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
void setZeros(vector<vector<int> >& matrix){
    //record which rows and cols should be set zero
    const int m=matrix.size();
    const int n=matrix[0].size();
    vector<bool> row(m,false);
    vector<bool> col(n,false);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                row[i]=true;
                col[j]=true;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i]||col[j]){
                matrix[i][j]=0;
            }
        }
    }
}

