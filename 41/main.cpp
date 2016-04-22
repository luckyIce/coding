/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string lastWord(const string& s){
    auto first=find_if(s.rbegin(),s.rend(),::isalpha);
    auto end=find_if_not(first,s.rend(),::isalpha);
    return distance(first,end);
}
int main(){
    string s="lkua cky";
    cout<<lastWord(s);
    return 0;
}
