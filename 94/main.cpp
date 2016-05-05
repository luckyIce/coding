/*************************************************************************
  > File Name: main.cpp
  > Author:
  > Mail:
  > Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){ }
};
vector<int> levelorderTraversal(TreeNode* root){
    vector<int> result;
    if(root==nullptr){
        return result;
    }
    const TreeNode* cur=root;
    std::queue<const TreeNode*> que;
    que.push(cur);
    while(!que.empty()){
        cur=que.front();
        que.pop();
        result.push_back(cur->val);
        if(cur->left!=nullptr){
            que.push(cur->left);
        }
        if(cur->right!=nullptr){
            que.push(cur->right);
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
    vector<int> result=levelorderTraversal(root);
    return 0;
}



