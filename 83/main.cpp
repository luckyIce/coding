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
string countAndSay(int n){
    string s=to_string(n);
    stringstream ss;
    for(int i=0;i<s.size();){
        int j=i+1;
        int count=1;
        while(s[j]==s[i]){
            count++;
            j++;
        }
        ss<<count<<s[i];
        i=j;
    }
    return ss.str();
}
int main() {
   int n=21;
   cout<<countAndSay(n)<<endl;
    return 0;
}

