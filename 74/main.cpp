/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isPalindrome(string s){
    transform(s.begin(),s.end(),s.begin(),::tolower);
    auto left=s.begin();
    auto right=prev(s.end());
    while(left<right){
        if(!::isalnum(*left))++left;
        else if(!::isalnum(*right))--right;
        else if(*left!=*right){
            return false;
        }
        else{
            ++left;
            --right;
        }
    }
    return true;
}
int main() {
   string   s="A man, a plan, a canal: panama" ;
   if(isPalindrome(s)){
       cout<<"good"<<endl;
   }
   else{
       cout<<"bad"<<endl;
   }


    return 0;
}

