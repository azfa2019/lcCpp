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
    TreeNode* trim0(TreeNode* root,int L,int R){
      if(!root) return nullptr;
      if(root->val<L) return trim0(root->rChild,L,R);
      if(root->val>R) return trim0(root->lChild,L,R);
      root->lChild=trim0(root->lChild,L,R);
      root->rChild=trim0(root->rChild,L,R);
      return root;
    }
    void deleteTree(TreeNode* root){
      if (!root) return;
      deleteTree(root->lChild);
      deleteTree(root->rChild);
      delete root;
      root=nullptr;
    }
    TreeNode* trim1(TreeNode* root, int L,int R){
      if(!root) return nullptr;
      if(root->val<L){
        auto ans=trim1(root->rChild,L,R);
        deleteTree(root->lChild);
        delete root;
        root=nullptr;
        return ans;
      }
      if(root->val>R){
        auto ans=trim1(root->lChild,L,R);
        deleteTree(root->rChild);
        delete root;
        root=nullptr;
        return ans;
      }
      root->lChild=trim1(root->lChild,L,R);
      root->rChild=trim1(root->rChild,L,R);
      return root;
    }
};
int main(){
  solution s0;
  TreeNode* n3=new TreeNode(3);
  TreeNode* n0=new TreeNode(0);
  TreeNode* n4=new TreeNode(4);
  TreeNode* n2=new TreeNode(2);
  TreeNode* n1=new TreeNode(1);
  n3->lChild=n0;
  n3->rChild=n4;
  n0->rChild=n2;
  n2->lChild=n1;
  printTree(n3); cout<<endl;
  //TreeNode* ans=s0.trim0(n3,1,3);
  TreeNode* ans=s0.trim1(n3,1,3);
  printTree(ans); cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

