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
    int rob(TreeNode* root){
      if(!root) return 0;
      if(m.count(root)) return m[root];
      int ll=root->lChild?rob(root->lChild->lChild):0;
      int lr=root->lChild?rob(root->lChild->rChild):0;
      int rl=root->rChild?rob(root->rChild->lChild):0;
      int rr=root->rChild?rob(root->rChild->rChild):0;
      return m[root]=max(root->val+ll+lr+rl+rr,rob(root->lChild)+rob(root->rChild));
    }
  private:
    unordered_map<TreeNode*,int> m;
};
class solution2{
  public:
    int rob(TreeNode* root){
      int l=0,r=0;
      return rob(root,l,r);
    }
  private:
    int rob(TreeNode* root,int& l,int& r){
      if(!root) return 0;
      int ll=0,lr=0,rl=0,rr=0;
      l=rob(root->lChild,ll,lr);
      r=rob(root->rChild,rl,rr);
      return max(root->val+ll+lr+rl+rr,l+r);
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
  n3->lChild=n2;
  n3->rChild=n3a;
  n2->rChild=n3b;
  n3a->rChild=n1;
  printTree(n3); cout<<endl;
  auto ans01=s0.rob(n3);
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
  p3->lChild=p4;
  p3->rChild=p5;
  p4->lChild=p1;
  p4->rChild=p3a;
  p5->rChild=p1a;
  auto ans02=s0.rob(p3);
  cout<<ans02<<endl;
  cout<<"================================"<<endl;
  solution2 s2;
  ans01=s2.rob(n3);
  cout<<ans01<<endl;
  ans02=s2.rob(p3);
  cout<<ans02<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

