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
vector<int> inorderTraversal(TreeNode* root){
    vector<int> result;
    std::stack<const TreeNode*> s;
    const TreeNode* p=root;
    while (p!=nullptr||(!s.empty())) {
        while(p!=nullptr){
            s.push(p);
            p=p->left;
        }
        p=s.top();
        result.push_back(p->val);
        s.pop();
        p=p->right;
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
    vector<int> result=inorderTraversal(root);
    return 0;
}



