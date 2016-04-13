/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
using namespace std;
bool isMatch(const char *s,const char *p){
    //递归法
    //边界条件
    if(*p=='\0'){
        return *s=='\0';
    }
    if(*(p+1)!='*'){
        if(*p=='.'||*p==*s){
            return isMatch(s+1,p+1);
        }
        return false;
    }
    else{
        if(*p=='.'){
            int num=1;//num stands for the number of chars match .*
            if(isMatch(s,p+2)){
                return true;
            }
            while(*(s+num-1)!='\0'){//the first part matchs .*
                if(isMatch(s+num,p+2)){
                    return true;
                }
                num++;
            }
        }
        else{
            int num=1;
            if(isMatch(s,p+2)){//match zero char
                return true;
            }
            while(true){
                bool change=true;
                for(int i=0;i<num&&change;i++){//test first num chars are equal to *p
                    if(*(s+i)!=*p){
                        change=false;
                    }
                }
                if(change==true){
                    if(isMatch(s+num,p+2)){
                        return true;
                    }
                }
                num++;
            }
        }
    }
}
int main(){
    const char *s="aab",*p="c*a*b";
    if(isMatch(s,p)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}
