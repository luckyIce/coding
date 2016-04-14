/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
string decimalToRoman(int num){
    const int radix[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
    const string symbol[]={"M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string roman;
    //radix[i]=1000
    //symbol[i]="CM"
    int big=0;
    int multiple=0;
    for(int i=0;i<13&&num>0;i++){//i<13 can be removed
        multiple=num/radix[i];
        num=num%radix[i];
        for(int j=0;j<multiple;j++){//put multiple symbol[i] to roman
            roman+=symbol[i];
        }
    }
    return roman;
}
int main(){
    int num;
    cin>>num;
    cout<<decimalToRoman(num)<<endl;
    return 0;
}

