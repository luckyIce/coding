/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool isValid(const string& s){
    stack<char> match;
    string left="([{";
    string right=")]}";
    for(auto c:s){
        if(left.find(c)!=string::npos){
            match.push(c);
        }
        else{
            if(match.empty()||right[left.find(match.top())]!=c){
                return false;
            }
            match.pop();
        }
    }
    return match.empty();
}
int main(){
    string s="((()))";
    if(isValid(s)){
        cout<<"match"<<endl;
    }
    else{
        cout<<" not match"<<endl;
    }
    return 0;

}

