/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int myAtoi(const string &str){
    int num=0;
    for(auto i:str){
        num=num*10;
        num=i-'0'+num;
    }
    return num;
}
int main(){
    string s;
    cin>>s;
    cout<<myAtoi(s)<<endl;
}
