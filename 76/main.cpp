/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int atoi(const string& s){
    int sum=0;
    int value;
    for(auto c:s){
        value=c-'0';
        sum=sum*10+value;
    }
    return sum;
}
int main() {
   string s="123454";
   cout<<atoi(s);
    return 0;
}

