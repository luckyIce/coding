/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
string simplifyPath(const string &s){
    vector<string> strs;//store sub dir part
    //find next item between '/'
    for(auto it=s.cbegin();it!=s.cend();){
        ++it;//skip '/'
        auto last=find_if(it,s.cend(),'/');
        string str=string(it,last);
        if(!str.empty()&&str!='.'){
            if(str==".."){
                strs.empty()||strs.pop_back();
            }
            else{
                strs.push_back(str);
            }
        }

    }
    stringstream ss;
    if(str.empty()){
        return "/";
    }
    for(auto it=strs.cbegin();it!=strs.cend();it++){
        ss<<"/"<<*it;
    }
    return ss.str();
}
