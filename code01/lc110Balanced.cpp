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
class solution{
  public:
    bool balanced0(TreeNode* root){
      if(!root) return true;
      int lHeight=height0(root->lChild);
      int rHeight=height0(root->rChild);
      return (abs(lHeight-rHeight)<=1)&&balanced0(root->lChild)&&balanced0(root->rChild);
    }
    int height0(TreeNode* root){
      if(!root) return 0;
      return max(height0(root->lChild),height0(root->rChild))+1;
    }
    bool balanced1(TreeNode* root){
      if(!root) return true;
      bool balanced=true;
      height1(root,&balanced);
      return balanced;
    }
    int height1(TreeNode* root,bool* balanced){
      if(!root) return 0;
      int lHeight=height1(root->lChild,balanced);
      if(!*balanced) return -1;
      int rHeight=height1(root->rChild,balanced);
      if(!*balanced) return -1;
      if(abs(lHeight-rHeight)>1){
        *balanced=false;
        return -1;
      }
      return max(lHeight,rHeight)+1;
    }
};
int main(){
  solution s0;
  TreeNode n3={3,nullptr,nullptr};
  TreeNode n9={9,nullptr,nullptr};
  TreeNode n20={20,nullptr,nullptr};
  TreeNode n15={15,nullptr,nullptr};
  TreeNode n7={7,nullptr,nullptr};
  n3.lChild=&n9;
  n3.rChild=&n20;
  n20.lChild=&n15;
  n20.rChild=&n7;
  auto ans=s0.balanced0(&n3);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  TreeNode p1={1,nullptr,nullptr};
  TreeNode p2l={2,nullptr,nullptr};
  TreeNode p2r={2,nullptr,nullptr};
  TreeNode p3l={3,nullptr,nullptr};
  TreeNode p3r={3,nullptr,nullptr};
  TreeNode p4l={4,nullptr,nullptr};
  TreeNode p4r={4,nullptr,nullptr};
  p1.lChild=&p2l;
  p1.rChild=&p2r;
  p2l.lChild=&p3l;
  p2l.rChild=&p3r;
  p3l.lChild=&p4l;
  p3l.rChild=&p4r;
  ans=s0.balanced0(&p1);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  ans=s0.balanced1(&n3);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  ans=s0.balanced1(&p1);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  return 0;
}

