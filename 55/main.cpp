/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
void rotate(vector<vector<int>>& matrix){
    //竖直反转
    for(auto &vec:matrix){
        reverse(vec.begin(),vec.end());
    }
    //正对交线反转
    const int N=matrix.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0;j < N-i; ++j) {//因为为正方形图像
           swap(matrix[i][j],matrix[N-1-j][N-1-i]);
        }
    }
}
int main(){
    vector<vector<int>> nums={{1,2},{3,4}};
    rotate(nums);
    return 0;
}

