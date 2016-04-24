/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int fac(int n){
    int result=1;
    for(int i=1;i<=n;i++){
        result*=i;
    }
    return result;
}
string getPermutation(int n,int k){
    k=k-1;
    stringstream ss;
    vector<int> iVec(n,0);
    for(int i=n-1;i>1&&k>0;i--){
        int a=k/fac(i);
        k=k%fac(i);
        iVec.insert(iVec.begin(),a);
    }

    vector<bool> used(n,false);
    for(auto num:iVec){
        int count=-1;
        for(int i=0;i<n;i++){
            if(!used[i]){
                ++count;
                if(count==num){
                    ss<<i+1;
                    used[i]=true;
                    break;
                }
            }
        }
    }
    return ss.str();
}
int main() {
   int n=3,k=3;
   cout<<getPermutation(n,k);
    return 0;
}
