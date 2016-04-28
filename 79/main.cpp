/*************************************************************************
  > File Name: main.cpp
  > Author:
  > Mail:
  > Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
bool isMatch(const char *s,const char *p){
    auto str=s;
    auto match=p;
    while(true){
        if(*str=='\0'&&*p=='\0')
            return true;
        if(*str=='\0'||*p=='\0')
            return false;
        if(*match=='.'){
            if(*(match+1)=='*'){
                while(*str!='\0'){
                    if(isMatch(str,p+2)){
                        return true;
                    }
                    str++;
                }
                if(*str=='\0'){
                    return isMatch(str,p+2);
                }
            }
            else{
                return isMatch(str+1,p+1);
            }
        }
        else{
            if(*str==*match){
                if(*(match+1)=='*'){
                    while(*str!='\0'){
                        if(isMatch(str,p+2)){
                            return true;
                        }
                        str++;
                    }
                    if(*str=='\0'){
                        return isMatch(str,p+2);
                    }

                }
                else{
                    return isMatch(str+1,p+1);
                }
            }
            else{
                return false;
            }

        }
    }
}
bool isMatch(const string& s,const string& p){
    return isMatch(s.c_str(),p.c_str());
}
int main() {
    string s="aaa";
    string p="a*";
    if(isMatch(s,p)){
        cout<<"match"<<endl;
    }
    else{
        cout<<"not match"<<endl;
    }
    return 0;
}

