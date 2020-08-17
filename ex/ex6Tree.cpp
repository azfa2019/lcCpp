#include<iostream>
using namespace std;
struct TreeNode{
  int val;
  TreeNode* left=nullptr;
  TreeNode* right=nullptr;
  TreeNode(int x):val(x){}
  ~TreeNode(){
    delete left;
    delete right;
    left=nullptr;
    right=nullptr;
  }
};
int main(){
  TreeNode* root=new TreeNode(1);
  root->left=new TreeNode(2);
  root->right=new TreeNode(3);
  int a=20;
  int * ptr2=& a;
  TreeNode* ptr=root->left;
  cout<< ptr->val<<endl;
  cout<< ptr<<endl;
  return 0;
}

