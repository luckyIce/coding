/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
bool find(vector<int> &indexs,int index){
    const int n=indexs.size();
    int begin=0;
    int end=n;
    int mid=(begin+end)/2;
    while(begin!=end){
        if(indexs[mid]==index){
            return true;
        }
        if(indexs[mid]<index){
            begin=mid+1;
        }
        else{
            end=mid;
        }
    }
    return false;
}
int candy(vector<int> &ratings){
    const int n=ratings.size();
    //each one must be in one of these classes
    //ones in first class are those whose rating are less than the both side of their neiborhood so they should be given one candy
    //ones  in second class are those whose rating are betwen their neiborhood so they should be given one more than their junior rating neiborhood
    //one in third class are those whose rating are more than the both side of their neiborhood so they should be given one more than their senior rating neiborhood
    //decide each item belonging to which class
    vector<int> firstclass;//store their index
    vector<int> secondclass;//store their index
    vector<int> thirdclass;//store their index
    for(int i=1;i<n-1;i++){
        if(ratings[i]<ratings[i-1]&&ratings[i]<ratings[i+1]){
            firstclass.push_back(i);

        }
        else if(ratings[i]>ratings[i-1]&&ratings[i]>ratings[i+1])
        {
            thirdclass.push_back(i);
        }
        else if(ratings[i]==ratings[i-1]||ratings[i]==ratings[i+1])
        {
            thirdclass.push_back(i);
        }
        else{

            secondclass.push_back(i);
        }

    }
    int sum=n;//how many candy should be given
    for(auto it=firstclass.begin();it!=firstclass.end();it++){
        //left side
        int left=*it-1;
        int extra=0;
        while(find(secondclass,left)||find(firstclass,left)){
            if(find(secondclass,left)){
                ++extra;
                sum+=extra;
            }
            left--;
        }
        int right=*it+1;
        while(find(secondclass,right)||find(firstclass,right)){
            if(find(secondclass,right)){
                ++extra;
                sum+=extra;
            }
            right--;
        }
    }

}

