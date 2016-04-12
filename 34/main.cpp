/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
string longestSubString(string s){
    //find out whether a substring is palindromic
    const int n=s.size();
    bool f[n][n];
    fill_n(&f[0][0],n*n,false);
    //init the substring which has one item true
    //init the substring which has two items true or false depending on whether
    //items in it are equal
    for(int i=0;i<s.size()-1;i++){
        f[i][i]=true;
        if(s[i]==s[i+1]){
            f[i][i+1]=true;
        }
        else{
            f[i][i+1]=false;
        }
    }
    for(int len=3;len<=s.size();len++){
        for(int i=0;i<=s.size()-len;i++){
            int j=i+len-1;
            if(s[i]==s[j]&&f[i+1][j-1]){
                f[i][j]=true;
            }
            else{
                f[i][j]=false;
            }
        }
    }
    //find the longest palindromic
    int max_len=0;
    int begin_index=0;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            if(f[i][j]&&j+1-i>max_len){
                max_len=j+1-i;
                begin_index=i;
                continue;
            }
            if(!f[i][j]){//if the substr is not palindromic the string is not a palindromic too
                break;
            }
        }
    }
    string result(s.begin()+begin_index,s.begin()+begin_index+max_len);
    return result;
}
int main(){
    string s;
    cin>>s;
    cout<<longestSubString(s)<<endl;
    return 0;
}
