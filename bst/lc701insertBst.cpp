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
    TreeNode *insertBst(TreeNode *root,int val){
      if(!root) return new TreeNode(val);
      if(root->val<val) root->right=insertBst(root->right,val);
      else root->left=insertBst(root->left,val);
      return root;
    }
};
void printTree(TreeNode* root){
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
  TreeNode n0(4),n1(2),n2(7),n3(1),n4(3);
  n0.left=&n1,n0.right=&n2,n1.left=&n3,n1.right=&n4;
  printTree(&n0);
  auto ans0=s0.insertBst(&n0,5);
  printTree(ans0);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

