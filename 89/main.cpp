/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isOperator(const string& s){
    if(s.size()==1&&string("+-*/").find(s)!=string::npos){
        return true;
    }
    else{
        return false;
    }
}
int evalRPN(vector<string>& strs){
    auto value=strs.back();
    strs.pop_back();
    if(isOperator(value)){
        int y=evalRPN(strs);
        int x=evalRPN(strs);
        if(value=="+"){
            return x+y;
        }
        else if(value=="-"){
            return x-y;
        }
        else if(value=="*"){
            return x*y;
        }
        else{
            return x/y;
        }

    }
    else{
        return stoi(value);
    }
}
int main() {
   // vector<string> strs={"2","1","+","3","*"};
   vector<string> strs={"4","13","5","/","+"};
   cout<<evalRPN(strs)<<endl;
    return 0;
}

