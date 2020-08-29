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
#include<sstream>
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
    int maxPathSum(TreeNode* root){
      if(!root) return 0;
      int ans=INT_MIN;
      maxPathSum(root,ans);
      return ans;
    }
  private:
    int maxPathSum(TreeNode* root,int& ans){
      if(!root) return 0;
      int l=max(0,maxPathSum(root->lChild,ans));
      int r=max(0,maxPathSum(root->rChild,ans));
      int sum=root->val+l+r;
      ans=max(ans,sum);
      return root->val+max(l,r);
    }
};
int main(){
  solution s0;
  TreeNode* n1=new TreeNode(1);
  TreeNode* n2=new TreeNode(2);
  TreeNode* n3=new TreeNode(3);
  TreeNode* n4=new TreeNode(4);
  TreeNode* n4a=new TreeNode(4);
  TreeNode* n4b=new TreeNode(4);
  TreeNode* n5=new TreeNode(5);
  TreeNode* n6=new TreeNode(6);
  TreeNode* n8=new TreeNode(8);
  TreeNode* n_3=new TreeNode(-3);
  n1->lChild=n2;
  n1->rChild=n3;
  n2->lChild=n4a;
  n2->rChild=n4b;
  printTree(n1); cout<<endl;
  auto ans01=s0.maxPathSum(n1);
  cout<<ans01<<endl;
  cout<<"================================"<<endl;
  TreeNode* p1=new TreeNode(1);
  TreeNode* p_1=new TreeNode(-1);
  TreeNode* p2=new TreeNode(2);
  TreeNode* p_2=new TreeNode(-2);
  TreeNode* p3=new TreeNode(3);
  TreeNode* p_3=new TreeNode(-3);
  TreeNode* p4=new TreeNode(4);
  TreeNode* p5=new TreeNode(5);
  TreeNode* p6=new TreeNode(6);
  TreeNode* p8=new TreeNode(8);
  TreeNode* p_5=new TreeNode(-5);
  p_1->lChild=p_2;
  p_1->rChild=p_3;
  auto ans02=s0.maxPathSum(p_1);
  cout<<ans02<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

