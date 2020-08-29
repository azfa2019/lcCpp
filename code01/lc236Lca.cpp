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
    TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
      if(!root||root==p||root==q) return root;
      TreeNode* l=lca(root->lChild,p,q);
      TreeNode* r=lca(root->rChild,p,q);
      if(l&&r) return root;
      return l?l:r;
    }
};
int main(){
  solution s0;
  TreeNode* n3=new TreeNode(3);
  TreeNode* n5=new TreeNode(5);
  TreeNode* n1=new TreeNode(1);
  TreeNode* n6=new TreeNode(6);
  TreeNode* n2=new TreeNode(2);
  TreeNode* n0=new TreeNode(0);
  TreeNode* n8=new TreeNode(8);
  TreeNode* n7=new TreeNode(7);
  TreeNode* n4=new TreeNode(4);
  n3->lChild=n5;
  n3->rChild=n1;
  n5->lChild=n6;
  n5->rChild=n2;
  n1->lChild=n0;
  n1->rChild=n8;
  n2->lChild=n7;
  n2->rChild=n4;
  printTree(n3); cout<<endl;
  //TreeNode* ans=s0.trim0(n3,1,3);
  auto ans=s0.lca(n3,n5,n1);
  cout<<ans->val<<endl;
  cout<<"================================"<<endl;
  ans=s0.lca(n3,n5,n4);
  cout<<ans->val<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

