/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

//get the sequence which each item is respected by decimal
//get the sequence which each item is respected by gray code
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> getSequenceByDecimal(int n){
    vector<int> result;
    result.push_back(0);
    result.push_back(1);
    for(int i=2;i<=n;i++){
        //reverse travel item in result and add '1' in the leftest position
        //that is to say 对result里的每一个元素加上 2的i次方再加入result
        vector<int> tmp=result;
        int plus=2;
        for(auto it=tmp.rbegin();it!=tmp.rend();it++){
            result.push_back(*it+plus);
            plus*=2;
        }
    }
    return result;
}
string convert(int &value){//it can convert value less than
    string binaryNum(10,'0');
    for(int i=9;i>=0&&value>0;i--){
        binaryNum[i]+=value%2;
        value/=2;
    }
    return binaryNum;
}
vector<string> getGraySequence(int n){
    vector<int> resultInt=getSequenceByDecimal(n);
    vector<string> resultGray;
    for(auto it=resultInt.begin();it!=resultInt.end();it++){
        resultGray.push_back(convert(*it));
    }
    return resultGray;
}
int main(){
    int n;
    cin>>n;
    getGraySequence(n);

}

