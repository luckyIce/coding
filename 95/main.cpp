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
void levelorderTraversal(TreeNode* root,int level,vector<vector<int> >& result){
    if(root!=nullptr){
        if(level>result.size()){
            result.push_back(vector<int>());
        }
        result[level-1].push_back(root->val);
        levelorderTraversal(root->left,level+1,result);
        levelorderTraversal(root->right,level+1,result);
    }
}
vector<vector<int> > levelorderTraversal(TreeNode* root){
    vector<vector<int> > result;
    if(root==nullptr){
        return result;
    }
    levelorderTraversal(root,1,result);
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
    vector<char> values={'3','9','#','#','2','1','#','#','7'};
    TreeNode *root=preorderBuild(values);
    vector<vector<int> > result=levelorderTraversal(root);
    return 0;
}



