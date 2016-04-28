/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
string longestPalindrome(const string& s){
    const int N=s.size();
    int max_len=1;
    bool board[N][N];
    for(int i=0;i<N;i++){
        board[i][i+1]=true;
    }
    for(int len=2;len<=N;len++){
        for(int i=0;i<N-len+1;i++){
            if(len==2){
                if(s[i]==s[i+len-1]){
                    board[i][i+len]=true;
                    max_len=len;
                }
                else{
                    board[i][i+len]=false;
                }
            }
            else{
                if(s[i]==s[i+len-1]&&board[i+1][i+len-1]){
                    board[i][i+len]=true;
                    max_len=len;

                }
                else{
                    board[i][i+len]=false;
                }
            }
        }
    }
    for(int i=0;i<N-max_len+1;i++){
        if(board[i][i+max_len]){
            return s.substr(i,max_len);
        }
    }
    return "-1";
}
int main() {
   string s="levcelb";
   cout<<longestPalindrome(s);
    return 0;
}


