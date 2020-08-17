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
    int longUniPath(TreeNode* root){
      int ans=0;
      longPath(root,ans);
      return ans;
    }
  private:
    int longPath(TreeNode* root,int& ans){
      if(!root) return 0;
      int l=longPath(root->lChild,ans);
      int r=longPath(root->rChild,ans);
      int pl=0,pr=0;
      if(root->lChild&&root->val==root->lChild->val) pl=l+1;
      if(root->rChild&&root->val==root->rChild->val) pr=r+1;
      ans=max(ans,pl+pr);
      return max(pl,pr);
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
  TreeNode* n5a=new TreeNode(5);
  TreeNode* n5b=new TreeNode(5);
  TreeNode* n6=new TreeNode(6);
  TreeNode* n8=new TreeNode(8);
  TreeNode* n_3=new TreeNode(-3);
  n1->lChild=n4;
  n1->rChild=n5;
  n4->lChild=n4a;
  n4->rChild=n4b;
  n5->rChild=n5b;
  printTree(n1); cout<<endl;
  auto ans01=s0.longUniPath(n1);
  cout<<ans01<<endl;
  cout<<"================================"<<endl;
  TreeNode* p1=new TreeNode(1);
  TreeNode* p1a=new TreeNode(1);
  TreeNode* p1b=new TreeNode(1);
  TreeNode* p_1=new TreeNode(-1);
  TreeNode* p2=new TreeNode(2);
  TreeNode* p_2=new TreeNode(-2);
  TreeNode* p3=new TreeNode(3);
  TreeNode* p_3=new TreeNode(-3);
  TreeNode* p4=new TreeNode(4);
  TreeNode* p5=new TreeNode(5);
  TreeNode* p5a=new TreeNode(5);
  TreeNode* p5b=new TreeNode(5);
  TreeNode* p6=new TreeNode(6);
  TreeNode* p7=new TreeNode(7);
  TreeNode* p8=new TreeNode(8);
  TreeNode* p_5=new TreeNode(-5);
  p5->lChild=p4;
  p5->rChild=p5a;
  p4->lChild=p1a;
  p4->rChild=p1b;
  p5a->lChild=p5b;
  auto ans02=s0.longUniPath(p5);
  cout<<ans02<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

