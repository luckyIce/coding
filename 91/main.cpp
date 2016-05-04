/*************************************************************************
	> File Name: main.cpp
	> Author:
	> Mail:
	> Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){ }
};
vector<int> preorderTraversal(TreeNode* root){
    vector<int> result;
    std::stack<const TreeNode*> s;
    if(root!=nullptr){
        s.push(root);
    }
    while(!s.empty()){
        const TreeNode *p=s.top();
        s.pop();
        result.push_back(p->val);
        if(p->right!=nullptr){
            s.push(p->right);
        }
        if(p->left!=nullptr){
            s.push(p->left);
        }
    }
    return result;
}
TreeNode* preorderBuild(vector<char> values,int &i){
    if(i>=values.size()||values[i]=='#'){
        return nullptr;
    }
    TreeNode* p=new TreeNode(values[i]-'0');
    p->left=preorderBuild(values,++i);
    p->right=preorderBuild(values,++i);
    return p;
}
TreeNode* preorderBuild(vector<char> values){
    int index=0;
    return preorderBuild(values,index);
}
int main() {
    vector<char> values={'1','#','2','3'};
    TreeNode *root=preorderBuild(values);
    vector<int> result=preorderTraversal(root);
    return 0;
}



