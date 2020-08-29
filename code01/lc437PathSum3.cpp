#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
#include<climits>
using namespace std;
  template<typename T>
void showVector(vector<T> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << *it<<" "; //'\t' ; 
  cout << '\n'; 
} 
class TreeNode{
  public:
    int val;
    TreeNode* lChild;
    TreeNode* rChild;
    TreeNode(int x):val(x),lChild(nullptr),rChild(nullptr){};
};
void printTree(TreeNode* root){
  if(!root) {
    cout<<"null ";
    return;
  }
  if(!root->lChild && !root->rChild) cout<<root->val<<" ";
  else{
    cout<<root->val<<" ";
    printTree(root->lChild);
    printTree(root->rChild);
  }
}
class solution{
  public:
    int pathSum(TreeNode* root,int sum){
      if(!root) return 0;
      return helper(root,sum)+helper(root->lChild,sum)+helper(root->rChild,sum);
    }
  private:
    int helper(TreeNode* root,int left){
      if(!root) return 0;
      left-=root->val;
      return (left==0?1:0)+helper(root->lChild,left)+helper(root->rChild,left);
    }
};
class solution1{
  public:
    int pathSum(TreeNode* root,int sum){
      if(!root) return 0;
      sums={{0,1}};
      ans=0;
      helper(root,0,sum);
      return ans;
    }
  private:
    void helper(TreeNode* root,int cur,int sum){
      if(!root) return;
      cur+=root->val;
      ans+=sums[cur-sum];
      ++sums[cur];
      helper(root->lChild,cur,sum);
      helper(root->rChild,cur,sum);
      --sums[cur];
    }
    unordered_map<int,int> sums;
    int ans;
};
int main(){
  solution s0;
  TreeNode* n10=new TreeNode(10);
  TreeNode* n5=new TreeNode(5);
  TreeNode* n_3=new TreeNode(-3);
  TreeNode* n3=new TreeNode(3);
  TreeNode* n2=new TreeNode(2);
  TreeNode* n11=new TreeNode(11);
  TreeNode* n3a=new TreeNode(3);
  TreeNode* n_2=new TreeNode(-2);
  TreeNode* n1=new TreeNode(1);
  TreeNode* n1_0=new TreeNode(1);
  TreeNode* n0=new TreeNode(0);
  n10->lChild=n5;
  n10->rChild=n_3;
  n5->lChild=n3;
  n5->rChild=n2;
  n_3->rChild=n11;
  n3->lChild=n3a;
  n3->rChild=n_2;
  n2->rChild=n1;
  n11->rChild=n0;
  n2->lChild=n1_0;
  printTree(n10); cout<<endl;
  //TreeNode* ans=s0.trim0(n3,1,3);
  auto ans=s0.pathSum(n10,8);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  solution1 s1;
  ans=s1.pathSum(n10,8);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

