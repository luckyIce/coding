/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<stack>
using namespace std;
bool isValid(const string& s){
    unordered_map<char,char> paren={ {'(',')'} , {'[',']'} , {'{','}'} };
    unordered_set<char> left_paren={'(','{','['};
    stack<char> stk;
    for(auto c:s){
        if(left_paren.find(c)!=left_paren.end()){
            stk.push(c);
        }
        else if(!stk.empty()&&paren[stk.top()]==c){
                stk.pop();
        }
        else{
            return false;
        }
    }
    if(stk.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main() {
   string s="({}])";
   if(isValid(s)){
       cout<<"true"<<endl;
   }
   else{
       cout<<"flase"<<endl;

   }
    return 0;
}




