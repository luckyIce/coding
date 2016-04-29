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
string int2Roman(int num){
    const int radix[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    string roman;
    for(size_t i=0;num>0;i++){
        int count=num/radix[i];
        for(;count>0;--count){
            roman+=symbol[i];
        }
        num=num%radix[i];
    }
    return roman;
}
int main() {
   int n=1990;
   cout<<int2Roman(n);
    return 0;
}

