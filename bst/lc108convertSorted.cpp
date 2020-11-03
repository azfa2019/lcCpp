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
struct TreeNode {
  int val;
  TreeNode *left,*right;
  TreeNode(int val):val(val),left(nullptr),right(nullptr){};
};
class Solution0{
  public:
    TreeNode *sortedArray2Bst(vector<int>& num){
      return buildBst(num,0,num.size()-1);
    }
  private:

    TreeNode *buildBst(vector<int>& num,int l,int r){
      if(l>r) return nullptr;
      int m=(l+r)/2;
      TreeNode *root=new TreeNode(num[m]);
      root->left=buildBst(num,l,m-1);
      root->right=buildBst(num,m+1,r);
      return root;
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
  TreeNode n0(0),n1(-3),n2(9),n3(-10),n4(5);
  n0.left=&n1,n0.right=&n2,n1.left=&n3,n2.left=&n4;
  vector<int>num{-10,-3,0,5,9};
  auto ans0=s0.sortedArray2Bst(num);
  printTree(ans0);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

