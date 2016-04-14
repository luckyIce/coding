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
// string longestCommonPrefix(const vector<const string> &strs){
    // if(strs.empty()){
        // return "";
    // }
    // for(int index=0;index<strs[0].size();index++){
        // for(int i=1;i<strs.size();i++){
            // if(index==strs[i].size()||strs[i][index]!=strs[0][index]){
                // return strs[0].substr(0,index);
            // }
        // }
    // }
    // return strs[0];
// }
string longestCommonPrefix(const vector<const string> &strs){
    if(strs.empty()){
        return "";
    }
    //find the first i strings's longestCommonPrefix 循环不定式
    int len=strs[0].size();//len stands for the length of longestCommonPrefix of the first strings
    for(int i=1;i<strs.size();i++){
        for(int j=0;j<len;j++){//the first j chars must be the same in two strings
            if(strs[i][j]!=strs[0][j]){
                len=j;
                break;
            }
        }
    }
    return strs[0].substr(0,len);

}
int main(){
    vector<const string> strs={"lucky","lumm"};
    vector<int > i={1,2,3};
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}
