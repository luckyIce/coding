/*************************************************************************
  > File Name: main.cpp
  > Author:
  > Mail:
  > Created Time: Tue Mar 15 17:17:55 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){ }
};
void flatter(TreeNode* root){
    if(root!=nullptr){
        stack<TreeNode*> s;
        TreeNode* p=root;
        s.push(p);
        while(!s.empty()){
            p=s.top();
            s.pop();
            if(p->right!=nullptr){
                s.push(p->right);
            }
            if(p->left!=nullptr){
                s.push(p->left);
            }
            p->left=nullptr;
            if(!s.empty()){
                p->right=s.top();
            }
            else{
                p->right=nullptr;
            }
        }
    }
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
vector<vector<int> > levelorderTraversal(TreeNode* root){
    vector<vector<int> > result;
    int level=1;
    if(root==nullptr){
        return result;
    }
    queue<const TreeNode*> q;
    const TreeNode* last=root;//last stands for the last item in the current level
    const TreeNode* cur=root;
    q.push(cur);
    while(!q.empty()){
        cur=q.front();
        q.pop();
        if(level>result.size()){
            result.push_back(vector<int>());
        }
        result[level-1].push_back(cur->val);
        if(cur->left){
            q.push(cur->left);
        }
        if(cur->right){
            q.push(cur->right);
        }
        if(cur==last){//最后元素的最又孩子为下一层的最后元素
            level++;
            if(cur->left){
                last=cur->left;
            }
            if(cur->right){
                last=cur->right;
            }

        }
    }
    return result;
}

int main() {
    vector<char> values={'3','9','#','#','2','1','#','#','7'};
    TreeNode *root=preorderBuild(values);
    flatter(root);
    vector<vector<int> > result=levelorderTraversal(root);
    return 0;
}



