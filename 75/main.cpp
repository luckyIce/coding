/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int strStr(const string& haystack,const string& needle){
    if(needle.empty()){
        return 0;
    }
    for(auto i=0;i<haystack.size()-needle.size()+1;i++){
        int j=0;
        for(;j<needle.size();j++){
            if(haystack[i+j]!=needle[j]){
                break;
            }
        }
        if(j==needle.size()){
            return i+1;
        }
    }
    return -1;
}
int main() {
   string haystack="haslucky";
   string needle="luck";
   cout<<strStr(haystack,needle);
    return 0;
}


