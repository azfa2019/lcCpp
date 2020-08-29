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
    int distrCoins(TreeNode* root){
      int ans=0;
      balance(root,ans);
      return ans;
    }
  private:
    int balance(TreeNode* root,int& ans){
      if(!root) return 0;
      int l=balance(root->lChild,ans);
      int r=balance(root->rChild,ans);
      ans+=abs(l)+abs(r);
      return l+r+root->val-1;
    }
};
int main(){
  solution s0;
  TreeNode* n0=new TreeNode(0);
  TreeNode* n0a=new TreeNode(0);
  TreeNode* n0b=new TreeNode(0);
  TreeNode* n1=new TreeNode(1);
  TreeNode* n2=new TreeNode(2);
  TreeNode* n3=new TreeNode(3);
  TreeNode* n3a=new TreeNode(3);
  TreeNode* n3b=new TreeNode(3);
  TreeNode* n4=new TreeNode(4);
  TreeNode* n4a=new TreeNode(4);
  TreeNode* n4b=new TreeNode(4);
  TreeNode* n5=new TreeNode(5);
  TreeNode* n5a=new TreeNode(5);
  TreeNode* n5b=new TreeNode(5);
  TreeNode* n6=new TreeNode(6);
  TreeNode* n8=new TreeNode(8);
  TreeNode* n_3=new TreeNode(-3);
  n1->lChild=n0a;
  n1->rChild=n0b;
  n0a->rChild=n3;
  printTree(n1); cout<<endl;
  auto ans01=s0.distrCoins(n1);
  cout<<ans01<<endl;
  cout<<"================================"<<endl;
  TreeNode* p0=new TreeNode(0);
  TreeNode* p1=new TreeNode(1);
  TreeNode* p1a=new TreeNode(1);
  TreeNode* p1b=new TreeNode(1);
  TreeNode* p_1=new TreeNode(-1);
  TreeNode* p2=new TreeNode(2);
  TreeNode* p_2=new TreeNode(-2);
  TreeNode* p3=new TreeNode(3);
  TreeNode* p3a=new TreeNode(3);
  TreeNode* p_3=new TreeNode(-3);
  TreeNode* p4=new TreeNode(4);
  TreeNode* p5=new TreeNode(5);
  TreeNode* p5a=new TreeNode(5);
  TreeNode* p5b=new TreeNode(5);
  TreeNode* p6=new TreeNode(6);
  TreeNode* p7=new TreeNode(7);
  TreeNode* p8=new TreeNode(8);
  TreeNode* p_5=new TreeNode(-5);
  p1->lChild=p0;
  p1->rChild=p2;
  auto ans02=s0.distrCoins(p1);
  cout<<ans02<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

