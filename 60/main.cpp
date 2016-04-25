/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<map>
#include<unordered_set>
using namespace std;
int candy(const vector<int>& data){
    vector<int> ratings;
    for(auto value:data){
        if(ratings.empty()||ratings.back()!=value){
            ratings.push_back(value);
        }
    }
    vector<int> small;//store index which has lower rating than their neighbor
    unordered_set<int> upstream;
    unordered_set<int> downstream;
    unordered_set<int> big;
    if(ratings[0]<ratings[1]){
        small.push_back(0);
    }
    else{
        downstream.insert(0);
    }
    const int N=ratings.size();
    if(ratings[N-1]<ratings[N-2]){
        small.push_back(N-1);
    }
    else{
        upstream.insert(N-1);
    }
    for(int i=1;i<ratings.size()-1;i++){
        if(ratings[i]<ratings[i-1]&&ratings[i]<ratings[i+1]){
            small.push_back(i);
        }
        else if(ratings[i]>ratings[i-1]&&ratings[i]>ratings[i+1]) {
            big.insert(i);
        }
        else if(ratings[i]>ratings[i-1]&&ratings[i]<ratings[i+1]){
            upstream.insert(i);
        }
        else{
            downstream.insert(i);
        }
    }
    vector<int> cost(ratings.size());

    for(int i=0;i<small.size();i++){
        int value=small[i];
        cost[value]=1;
        //left item
        int j=value-1;
        int count=1;//current one have count candy
        while(downstream.find(j)!=downstream.end()){
            cost[j]=++count;
            j--;
        }
        //right item
        j=value+1;
        count=1;//current one have count candy
        while(upstream.find(j)!=upstream.end()){
            cost[j]=++count;
            j++;
        }
    }
    for(auto value:big){
        cost[value]=max(cost[value-1],cost[value+1])+1;
    }
    int total=0;
    int j=0;
    for(int i=0;i<data.size();i++){
        if(i!=0&&data[i]!=data[i-1]){
            ++j;
        }
        total+=cost[j];
    }
    return total;
}
int main() {
   vector<int> ratings={5,4,3,4,3,2,2,3,4};
   cout<<candy(ratings);
    return 0;
}

