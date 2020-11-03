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
    bool isValidBst(TreeNode *root){
      return isValidBst(root,LLONG_MIN,LLONG_MAX);
    }
  private:
    bool isValidBst(TreeNode *root,long minVal,long maxVal){
      if(!root) return true;
      if(root->val<=minVal || root->val>=maxVal) return false;
      return (isValidBst(root->left,minVal,root->val)&&isValidBst(root->right,root->val,maxVal));
    }
};
class Solution1{
  public:
    bool isValidBst(TreeNode *root){
      prev_=nullptr;
      return inOrder(root);
    }
  private:
    TreeNode *prev_;
    bool inOrder(TreeNode *root){
      if(!root) return true;
      if(!inOrder(root->left)) return false;
      if(prev_&& root->val<=prev_->val) return false;
      prev_=root;
      return inOrder(root->right);
    }
};
int main(){
  Solution0 s0;
  TreeNode n0(2),n1(1),n2(3);
  n0.left=&n1,n0.right=&n2;
  cout<<s0.isValidBst(&n0)<<endl;
  TreeNode p0(1),p1(2),p2(3);
  p0.left=&p1,p0.right=&p2;
  cout<<s0.isValidBst(&p0)<<endl;
  cout<<"================================"<<endl;
  Solution1 s1;
  cout<<s1.isValidBst(&n0)<<endl;
  cout<<s1.isValidBst(&p0)<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

