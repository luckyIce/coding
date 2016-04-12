/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
void reverse(char *begin,char *end){
    const int len=end-begin;
    for(int i=0;i<len/2;i++){
        char tmp=*(begin+i);
        *(begin+i)=*(end-1-i);
        *(end-1-i)=tmp;
    }
}
string addBinary(string a,string b){
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    const int n=a.size()>b.size()?a.size():b.size();
    int carry=0;
    string result;
    for(int i=0;i<n;i++){
        const int ai=i<a.size()?a[i]-'0':0;
        const int bi=i<b.size()?b[i]-'0':0;
        const int val=ai+bi+carry;
        carry=val/2;
        result.insert(result.begin(),val%2+'0');
    }
    if(carry==1){
        result.insert(result.begin(),1);
    }
    return result;
}
int main(){
    string a,b;
    cin>>a>>b;
    cout<<addBinary(a,b)<<endl;
    return 0;
}

