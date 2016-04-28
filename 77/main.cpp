/*************************************************************************
  > File Name: main.cpp
  > Author:
  > Mail:
  > Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string addBinary(string& a,string& b){
    stringstream ss;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int carry=0;
    int value=0;
    auto it_a=a.begin();
    auto it_b=b.begin();
    while(it_a!=a.end()&&it_b!=b.end()){
        value=*it_a-'0'+(*it_b-'0')+carry;
        carry=value/2;
        value=value%2;
        ss<<value;
        it_a++;
        it_b++;
    }
    while(it_a!=a.end()&&carry){
        value=*it_a-'0'+carry;
        carry=value/2;
        value=value%2;
        ss<<value;
        it_a++;
    }
    if(carry){
        ss<<carry;
        carry=0;
    }
    else{
        while(it_a!=a.end()){
            ss<<*it_a;
            it_a++;
        }
    }
    while(it_b!=b.end()&&carry){
        value=*it_b-'0'+carry;
        carry=value/2;
        value=value%2;
        ss<<value;
        it_b++;
    }
    if(carry){
        ss<<carry;
    }
    else{
        while(it_b!=b.end()){
            ss<<*it_b;
            it_b++;
        }
    }
    return ss.str();
}
int main() {
    string a="11";
    string b="1";
    string s=addBinary(a,b);
    reverse(s.begin(),s.end());
    cout<<s;
    return 0;
}
