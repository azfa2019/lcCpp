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
    TreeNode* deleteLeaf(TreeNode* root,int target){
      if(!root) return nullptr;
      root->lChild=deleteLeaf(root->lChild,target);
      root->rChild=deleteLeaf(root->rChild,target);
      return root->lChild||root->rChild||root->val!=target?root:nullptr;
    }
};
int main(){
  solution s0;
  TreeNode* n1=new TreeNode(1);
  TreeNode* n2=new TreeNode(2);
  TreeNode* n3=new TreeNode(3);
  TreeNode* n2a=new TreeNode(2);
  TreeNode* n2b=new TreeNode(2);
  TreeNode* n4=new TreeNode(4);
  n1->lChild=n2;
  n1->rChild=n3;
  n2->lChild=n2a;
  n3->lChild=n2b;
  n3->rChild=n4;
  printTree(n1); cout<<endl;
  //TreeNode* ans=s0.trim0(n3,1,3);
  TreeNode* ans=s0.deleteLeaf(n1,2);
  printTree(ans); cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

