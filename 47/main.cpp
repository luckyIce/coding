/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int longestConsecutive(const vector<int>& nums){
    unordered_map<int,bool> used;
    for(auto num:nums){
        used[num]=false;
    }
    int longest=0;
    for(auto num:nums){
        if(used[num]){
            continue;
        }
        used[num]=true;
        int length=1;
        for(int j=num+1;used.find(j)!=used.end();++j){
            used[j]=true;
            length++;
        }
        for(int j=num-1;used.find(j)!=used.end();--j){
            used[j]=true;
            length++;
        }
        longest=max(longest,length);
    }
    return longest;
}
int main(){
    vector<int> nums={100,4,200,1,3,2};
    cout<<longestConsecutive(nums);
    return 0;
}

