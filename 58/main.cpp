/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
void setZeros(vector<vector<int>>& matrix){
    const int m=matrix.size();
    const int n=(*matrix.begin()).size();
    vector<bool> row(m,false);
    vector<bool> col(n,false);
    for (int i = 0; i < m; ++i) {
        for (int j= 0;j< n; ++j) {
            if(matrix[i][j]==0){
                row[i]=true;
                col[j]=true;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        if(row[i]==true){
            for (int j = 0; j < n; ++j) {
                matrix[i][j]=0;
            }
        }
    }
    for (int j = 0; j < n; ++j) {
        if(col[j]==true){
            for (int i = 0; i < m; ++i) {
                matrix[i][j]=0;
            }
        }
    }
}
int main() {
    vector<vector<int>> nums={ {1,2,3,4}, {5,6,0,4}, {7,0,8,4}, {9,9,0,3}};
    setZeros(nums);
    return 0;
}

