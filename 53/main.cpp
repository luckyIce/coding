/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
bool checked(char c,vector<bool>& used){
    if(c=='.'){
        return true;
    }
    if(used[c-'0'-1]){
        return false;
    }
    else{
        used[c-'0'-1]=true;
    }
}
bool isValidSudoku(const vector<vector<char>>& board){
    vector<bool> used(9,false);
    //检查行
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            if(!checked(board[i,j],used)){
                return false;
            }
        }
        fill(used.begin(),used.end(),false);
    }
    for (j = 0; j < 9; ++j) {
        for (i = 0; i < 9; ++i) {
            if(!checked(board[i,j],used)){
                return false;
            }
        }
        fill(used.begin(),used.end(),false);
    }
    for (r = 0; r < 3; ++r) {
        for (c = 0; c < 3; ++c) {
            for(int i=r*3;i<r*3+3;i++){
                for(int j=c*3;j<c*3+3;j++){
                    if(!checked(board[i,j],used));

                }
            }
            fill(used.begin(),used.end(),false);
        }
    }
    return true;
}

