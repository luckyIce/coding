/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;
int roman2Int(const string& s){
    map<char,int> Map={ {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000} };
    int result=0;
    for(size_t i=0;i<s.size();i++){
        if(i<s.size()-1){
            if(Map[s[i]]>=Map[s[i+1]]){
                result+=Map[s[i]];
            }
            else{
                result-=Map[s[i]];
            }
        }
        else{
            result+=Map[s[i]];
        }
    }
    return result;
}
int main() {
   string s="MCMLXXVI";
   cout<<roman2Int(s)<<endl;
    return 0;
}

