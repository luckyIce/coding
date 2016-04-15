/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
#include<stringstream>
using namespace std;
string countAndSay(int n){
    string s("1");
    while(--n){//n stands for the index in unresoved sequence,index starts from one
        s=getNext(s);
    }
    return s;
}
string getNext(const string &s){
    stringstream ss;
    //count how many same num in the prefix of s
    for(auto it=s.cbegin();it!=s.cend();){
        //find the char which is not the same char in *it
        auto last=s.find_if_not(it,s.cend());
        ss<<distance(last-it)<<*it;//put in the number and char
        it=last;
    }
    return ss.str();
}
