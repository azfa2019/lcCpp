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
    TreeNode* prune(TreeNode* root){
      if(!root) return root;
      root->lChild=prune(root->lChild);
      root->rChild=prune(root->rChild);
      if(root->val==1||root->lChild||root->rChild) return root;
      //delete root; 
      return nullptr;
    }
    TreeNode* prune2(TreeNode* root){
      if(!root) return nullptr;
      if(root->val==0) return nullptr;
      root->lChild=prune2(root->lChild);
      root->rChild=prune2(root->rChild);
      return root;
    }
};
int main(){
  solution s0;
  TreeNode na={1,nullptr,nullptr};
  TreeNode nb={0,nullptr,nullptr};
  TreeNode nc={1,nullptr,nullptr};
  TreeNode nd={0,nullptr,nullptr};
  TreeNode ne={0,nullptr,nullptr};
  TreeNode nf={0,nullptr,nullptr};
  TreeNode ng={1,nullptr,nullptr};
  na.lChild=&nb;
  na.rChild=&nc;
  nb.lChild=&nd;
  nb.rChild=&ne;
  nc.lChild=&nf;
  nc.rChild=&ng;
  printTree(&na); cout<<endl;
  TreeNode* ans=s0.prune(&na);
  printTree(&na); cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

