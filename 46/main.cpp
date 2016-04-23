/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int find_kth(vector<int>::const_iterator A,int m,vector<int>::const_iterator B,int n,int k){//assume m<=n
    if(m>n){
        return find_kth(B,n,A,m,k);
    }
    if(m==0){
        return B[k-1];
    }
    if(k==1){
        return min(*A,*B);
    }
    int a=min(k/2,m);
    int b=k-a;
    if(*(A+a-1)<*(B+b-1)){
        return find_kth(A+a,m-a,B,n,k-a);
    }
    else if(*(A+a-1)>*(B+b-1)){
        return find_kth(A,m,B+b,n-b,k-b);
    }
    else{
        return *(A+a-1);
    }
}
double findMedianSortedArray(const vector<int>& A,const vector<int>& B){
    const int m=A.size();
    const int n=B.size();
    int total=m+n;
    if(total&0x1){
        return find_kth(A.begin(),m,B.begin(),n,total/2+1);
    }
    else{
        return 0.5*static_cast<double>(find_kth(A.begin(),m,B.begin(),n,total/2)+find_kth(A.begin(),m,B.begin(),n,total/2+1));
    }
}
int main(){
    vector<int> A={1,3,5,7};
    vector<int> B={2,4,6,8};
    cout<<findMedianSortedArray(A,B);
    return 0;
}

