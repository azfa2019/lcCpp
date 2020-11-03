#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <memory>
using namespace std;
  template<typename T>
void showVector(vector<T> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << *it<<" "; //'\t' ; 
    cout << '\n'; 
} 
struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val):val(val),left(nullptr),right(nullptr){};
};
class Solution0{
  public:
    void recoverTree(TreeNode *root){
      inOrder(root);
      swap(first->val,second->val);
    }
  private:
    TreeNode *first=nullptr,*second=nullptr,*prev=nullptr;
    void inOrder(TreeNode *root){
      if(!root) return;
      inOrder(root->left);
      if(prev&&prev->val>=root->val) {
        if(!first) first=prev;
        second=root;
      }
      prev=root;
      inOrder(root->right);
    }
};
void printTree(TreeNode *root){
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()){
    auto node=q.front();q.pop();
    cout<<node->val<<" ";
    if(node->left) q.push(node->left);
    if(node->right) q.push(node->right);
  }
  cout<<endl;
}
int main(){
  Solution0 s0;
  TreeNode n0(3),n1(1),n2(4),n3(2),n4(3);
  n0.left=&n1,n0.right=&n2,n2.left=&n3;
  printTree(&n0);
  s0.recoverTree(&n0);
  printTree(&n0);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

