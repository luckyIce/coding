/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;
string simplifyPath(const string &s){
    vector<string> strs;//store sub dir part
    //find next item between '/'
    for(auto i=0;i<s.size();){
        ++i;//skip '/'
        if(i==s.size()){
            break;
        }
        auto last=s.find_first_of("/",i);
        string str=string(s.cbegin()+i,s.cbegin()+last);
        i=last;//next search start at the item next to current '/'
        if(!str.empty()&&str!="."){
            if(str==".."&&!(strs.empty())){
                strs.pop_back();
            }
            else{
                strs.push_back(str);
            }
        }

    }
    stringstream ss;
    if(strs.empty()){
        return "/";
    }
    for(auto it=strs.cbegin();it!=strs.cend();it++){
        ss<<"/"<<*it;
    }
    return ss.str();
}
int main(){
    string s("/a/./b/../../c/");
    cout<<simplifyPath(s)<<endl;
    return 0;
}
