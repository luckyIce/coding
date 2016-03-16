/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
using namespace std;
int longestConsecutive(const vector<int>& nums){
    unordered_map<int,bool> used;
    for(auto i:nums){
        used[i]=false;
    }
    int longest=0;
    for(auto i:nums){
        if(used[i]){
            continue;
        }
        else{
            int length=1;
            used[i]=true;
            for(int j=i+1;used.find(j)!=used.end();j++){
                length++;
                used[j]=true;
            }
            for(int j=i-1;used.find(j)!=used.end();j--){
                length++;
                used[j]=true;
            }
            longest=max(longest,length);
        }
    }
    return longest;
}

