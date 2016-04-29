/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
string simplyPath(const string& s){

    vector<string> parts;
    for(auto i=s.begin();i!=s.end();){
        ++i;//i is the index of '/'
        auto j=find(i,s.end(),'/');
        string str=string(i,j);
        if(str.empty()){
            break;
        }
        if(str!="."&&str!=".."){
            parts.push_back(str);
        }
        else if(str==".."){
            if(!parts.empty())
                parts.pop_back();
        }
        i=j;
    }
    stringstream ss;
    for(auto it=parts.begin();it!=parts.end();it++){
        ss<<'/'<<*it;
    }
    return ss.str();
}
int main() {
   string s="/home/" ;
   cout<<simplyPath(s)<<endl;
    return 0;
}

