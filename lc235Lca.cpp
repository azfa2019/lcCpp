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
      if(root->val>p->val&&root->val>q->val) return lca(root->lChild,p,q);
      if(root->val<p->val&&root->val<q->val) return lca(root->rChild,p,q);
      return root;
    }
};
int main(){
  solution s0;
  TreeNode* n6=new TreeNode(6);
  TreeNode* n2=new TreeNode(2);
  TreeNode* n8=new TreeNode(8);
  TreeNode* n0=new TreeNode(0);
  TreeNode* n7=new TreeNode(7);
  TreeNode* n4=new TreeNode(4);
  TreeNode* n3=new TreeNode(3);
  TreeNode* n5=new TreeNode(5);
  TreeNode* n9=new TreeNode(9);
  n6->lChild=n2;
  n6->rChild=n8;
  n2->lChild=n0;
  n2->rChild=n4;
  n8->lChild=n7;
  n8->rChild=n9;
  n4->lChild=n3;
  n4->rChild=n5;
  printTree(n6); cout<<endl;
  //TreeNode* ans=s0.trim0(n3,1,3);
  auto ans=s0.lca(n6,n2,n8);
  cout<<ans->val<<endl;
  cout<<"================================"<<endl;
  ans=s0.lca(n6,n2,n4);
  cout<<ans->val<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

