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
string findLastWord(const string& s){
    auto first=find_if(s.rbegin(),s.rend(),::isalpha);
    auto last=find_if_not(first,s.rend(),::isalpha);
    string result(first,last);
    reverse(result.begin(),result.end());
    return result;
}
int main(){
    string s="helo world!";
    cout<<findLastWord(s)<<endl;
    return 0;
}


