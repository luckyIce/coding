/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int medianTwoSortedArray(const vector<int>&A,const vector<int>&B){
    int beginA=0;
    int endA=A.size();
    int beginB=0;
    int endB=B.size();
    int midA;
    int midB;
    while(beginA!=endA&&beginB!=endB){
        midA=beginA+(endA-beginA)/2;
        midB=beginB+(endB-beginB)/2;
        if(A[midA]==B[midB]){
            return A[midA];
        }
        if((endA-beginA)%2!=0){//the number is odd
            if(endA-beginA==1){
                return A[midA]>B[midB]?A[midA]:B[midB];
            }
            if(A[midA]<B[midB]){
                beginA=midA;
                endB=midB+1;
            }
            else{
                beginB=midB;
                endA=midA+1;
            }
        }
        else{
            if(A[midA]<B[midB]){
                beginA=midA;
                endB=midB;
            }
            else{
                beginB=midB;
                endA=midA;
            }
        }
    }
    if(beginA==endA){
        midB=beginB+(endB-beginB)/2;
        return B[midB];
    }
    else{
        midA=beginA+(endA-beginA)/2;
        return A[midA];
    }
}
int main(){
    vector<int> A={1,3,5,7};
    vector<int> B={2,4,6,8};
    cout<<medianTwoSortedArray(A,B);
}

