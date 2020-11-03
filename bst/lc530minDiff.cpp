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
    int getMinDiff(TreeNode *root){
      vector<int> sorted;
      inOrder(root,sorted);
      int minDiff=sorted.back();
      for(int i=1;i<sorted.size();++i) minDiff=min(minDiff,sorted[i]-sorted[i-1]);
      return minDiff;
    }
  private:
    void inOrder(TreeNode *root,vector<int>& sorted){
      if(!root) return;
      inOrder(root->left,sorted);
      sorted.push_back(root->val);
      inOrder(root->right,sorted);
    }
};
class Solution1{
  public:
  int getMinDiff(TreeNode *root){
    prev_=nullptr;
    minDiff_=INT_MAX;
    inOrder(root);
    return minDiff_;
  }
  private:
  int minDiff_;
  TreeNode *prev_;
  void inOrder(TreeNode *root){
    if(!root) return;
    inOrder(root->left);
    if(prev_) minDiff_=min(minDiff_,root->val-prev_->val);
    prev_=root;
    inOrder(root->right);
  }

};
int main(){
  Solution0 s0;
  TreeNode n0(1),n1(3),n2(2);
  n0.right=&n1,n1.left=&n2;
  cout<<s0.getMinDiff(&n0)<<endl;
  cout<<"================================"<<endl;
  Solution1 s1;
  cout<<s1.getMinDiff(&n0)<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

