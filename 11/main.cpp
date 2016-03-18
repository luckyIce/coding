/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
bool check(char ch,vector<bool>& used){
    if(ch=='.')return true;
    if(used[ch-'1'])return false;
    used[ch-'1']=true;
    return true;
}
bool isValidSudoku(const vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        //test whether row i has conflict
        vector<bool> used(9);
        fill(used.begin(),used.end(),false);
        for(int j=0;i<9;j++){
            if(!check(board[i][j]),used){
                return false;
            }
        }
        //test whether col i has conflict
        fill(used.begin(),used.end(),false);
        for(int j=0;i<9;j++){
            if(!check(board[j][i]),used){
                return false;
            }
        }
    }
    //test 9 little board
    for(int r=0;r<3;r++){
        for(int c=0;c<3;c++){
            //test every little board
            vector<bool> used(9);
            fill(used.begin(),used.end(),false);
            for(int i=3r;i<3r+3;i++){
                for(int j=3r;j<3r+3;j++){
                    if(check(!board[i][j],used)){
                        return false;
                    }



                }

            }

        }
    }
    return true;
}

