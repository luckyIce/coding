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
string baseOfStr(const string &s){
    string result=s;
    sort(s.begin(),s.end());
    return result;
}
map<string,vector<string> groupsOfStrs(const vector<string> &strs){
    map groups;
    for(auto element:strs){
        string key=baseOfStr(element);
        if(!find(key,groups)){
            groups.add(key,vector<string>());
        }
        groups[key].push_back(element);
    }
    return groups;
}
void outPutStrInGroup(map<string,vector<string> groups){
    for(auto element:groups){
        for(auto str:element){
            cout<<str<<" ";
        }
        cout<<endl;
    }
}


