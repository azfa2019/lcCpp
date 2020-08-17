#include <iostream>
using namespace std;
struct TreeNode{
  int val;
  TreeNode* left=nullptr;
  TreeNode* right=nullptr;
  TreeNode(int x): val(x){}
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
  cout<<root->val<<endl;
  cout<<root->left->left<<endl;
  return 0;
}
