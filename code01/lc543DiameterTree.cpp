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
    int diamterTree(TreeNode* root){
      ans=0;
      longPath(root);
      return ans;
    }
  private:
    int ans;
    int longPath(TreeNode* root){
      if(!root) return -1;
      int l=longPath(root->lChild)+1;
      int r=longPath(root->rChild)+1;
      ans=max(ans,l+r);
      return max(l,r);
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
  n2->lChild=n4;
  n2->rChild=n5;
  printTree(n1); cout<<endl;
  auto ans01=s0.diamterTree(n1);
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
  TreeNode* p7=new TreeNode(7);
  TreeNode* p8=new TreeNode(8);
  TreeNode* p_5=new TreeNode(-5);
  p1->lChild=p2;
  p1->rChild=p3;
  p2->lChild=p4;
  p2->rChild=p5;
  p5->lChild=p7;
  p4->rChild=p6;
  auto ans02=s0.diamterTree(p1);
  cout<<ans02<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

