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
        int a=score/fac(remains-1)+1;
        s[i]+=a;
        remains=score%fac(remains-1);
        --remains;
    }
    for(int i=1;i<n;i++){
        int result=s[i]-'0';//result stans for the true number which should locate here
        bool conflict=true;
        while(conflict){
            for(int j=0;j<i;j++){
                if(s[j]==result){
                    result++;
                    break;
                }
            }
            s[i]=result;
            conflict=false;
        }
    }
    return s;
}

