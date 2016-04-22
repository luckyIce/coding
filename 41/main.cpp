/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int lastWord(const string& s){
    int len=0;
    int length=0;
    //第一种情况为单词第一个字母
    //len=0
    //len++
    //第二种情况为单词中间字母
    //len++
    //第三种情况为单词最后一个字母
    //len++ return
    for(auto c:s){
        if(c!=' '){
            ++len;
        }
        else{
            if(len>0){
                length=len;
            }
            len=0;
        }
    }
    if(len>0){
        length=len;
    }
    return length;
}
int main(){
    string s="lkua   ";
    cout<<lastWord(s);
    return 0;
}
