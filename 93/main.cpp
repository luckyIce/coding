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
vector<int> postorderTraversal(TreeNode* root){
    vector<int> result;
    if(root==nullptr){
        return result;
    }
    const TreeNode* cur=root;
    const TreeNode* pre=nullptr;
    stack<const TreeNode*> s;
    s.push(cur);
    if(cur->right){
        s.push(cur->right);
    }
    if(cur->left){
        s.push(cur->left);
    }
    while(!s.empty()){
        cur=s.top();
        if(cur->left==nullptr&&cur->right==nullptr){
            result.push_back(cur->val);
            s.pop();
            pre=cur;
        }
        else if((cur->right!=nullptr&&pre!=cur->right)||(cur->left!=nullptr&&pre!=cur->left)){
            if(cur->right){
                s.push(cur->right);
            }
            if(cur->left){
                s.push(cur->left);
            }
        }
        else{
            s.pop();
            result.push_back(cur->val);
            pre=cur;
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
    vector<int> result=postorderTraversal(root);
    return 0;
}



