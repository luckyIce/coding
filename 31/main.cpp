/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
using namespace std;
int strStr(const string& haystack,const string& needle){
    const int N=haystack.size();
    const int n=needle.size();
    for(int i=0;i<=N-n;i++){
        //i stands for the begin index of the match
        int j=i;//j stands for current char in haystack
        int k=0;//k stands for current char in needle
        while(k<n&&haystack[j]==needle[k]){
            j++;
            k++;

        }
        if(k=n){//find match
            return i;
        }
    }
    return -1;//no match
}
