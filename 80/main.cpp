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
string longestCommonPrefix(const string& s1,const string& s2){
    auto it1=s1.begin();
    auto it2=s2.begin();
    for(;it1!=s1.end()&&it2!=s2.end();it1++,it2++){
        if(*it1!=*it2){
            break;
        }
    }
    return string(s1.begin(),it1);
}
string longestCommonPrefix(const vector<string>& strs){
    if(strs.size()<2){
        return *strs.begin();
    }
    string s=longestCommonPrefix(*strs.begin(),*(strs.begin()+1));
    for(auto str:strs){
        s=longestCommonPrefix(s,str);
    }
    return s;
}
int main() {
   vector<string> strs={"lucky","lumm","luaaa","lubbb"};
   cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}

