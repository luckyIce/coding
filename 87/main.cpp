/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<stack>
#include<string>
using namespace std;
int longestValidParen(const string& s){
    size_t length=0;
    size_t last=-1;//the index of the last right paren
    stack<int> left;//the index of the left paren
    for(size_t i=0;i<s.size();i++){
        if(s[i]=='('){
            left.push(i);
        }
        else{
            if(left.empty()){
                last=i;
            }
            else{
                left.pop();
                if(left.empty()){
                    length=max(length,i-last);
                }
                else{
                    length=max(length,i-left.top());
                }
            }
        }
    }
    return length;
}
int main() {
   string s="())())";
   cout<<longestValidParen(s)<<endl;

    return 0;
}

