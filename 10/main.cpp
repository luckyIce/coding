/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;
int fac(int n){
    int result=1;
    for(int i=n;i>1;i-- ){
        result*=i;
    }
    return result;
}
string getPermutation(int n,int k){
    string s(n,'0');
    int remains=n;//remains stands for how many number left
    int score=k-1;//score stands for the location of the item which is the result
    for(int i=0;i<n;i++){
        int a=score/fac(remains-1)+1;//a is the rank in the remaining numbers
        s[i]+=a;
        remains=score%fac(remains-1);
        --remains;
    }
    bool used[n+1];//used shows whether a item can be used or not
    //init used
    for(int i=0;i<n+1;i++){
        used[i]=false;
    }
    for(int i=1;i<n;i++){
        int result=s[i]-'0';// the final result is the rank in the whole numbers
        int count=0;
        for(int j=0;j<n+1;j++){
            if(used[j]==false){
                ++count;
                if(count==result){
                    result=j;
                }
            }
        }
        s[i]=result+'0';
    }
    return s;
}

