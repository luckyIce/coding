/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
void add(vector<int>& digits int digit){
    int carry=digit;
    for(auto it=digits.rbegin();it!=digits.rend();it++){
        *it+=carry;
        carry=*it/10;
        *it%=10;
    }
    if(carry>0){
        digits.push_front(carry);
    }

}
vector<int> plusOne(vector<int>& digits){
    add(digits,1);
    return digits;
}

