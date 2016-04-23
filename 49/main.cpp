/*************************************************************************
  > File Name: main.cpp
  > Author:
  > Mail:
  > Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(const vector<int>& nums){
    vector<int> data=nums;
    sort(data.begin(),data.end());
    vector<vector<int>> result;
    for(int i=0;i<data.size();i++){
        if(i>0&&data[i]==data[i-1]){
            continue;
        }
        int begin=i+1;
        int end=data.size()-1;
        while(begin<end){
            if(begin>i+1&&data[begin]==data[begin-1]){
                begin++;
                continue;
            }
            if(end<data.size()-1&&data[end]==data[end+1]){
                end--;
                continue;
            }
            if(data[i]+data[begin]+data[end]==0){
                vector<int> tmp;
                tmp.push_back(data[i]);
                tmp.push_back(data[begin]);
                tmp.push_back(data[end]);
                result.push_back(tmp);
                begin++;
                end--;
            }
            else if(data[i]+data[begin]+data[end]<0){
                begin++;
            }
            else{
                end--;
            }
        }
    }
    return result;
}
int main(){
    vector<int> nums={-1,0,1,2,-1,-4};
    auto result=threeSum(nums);
    return 0;
}

