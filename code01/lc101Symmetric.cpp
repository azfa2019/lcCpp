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
    bool symmetric(TreeNode* root1,TreeNode*root2){
      if(!root1&&!root2) return true;
      if(!root1||!root2) return false;
      return root1->val==root2->val&&symmetric(root1->lChild,root2->rChild)&& symmetric(root1->rChild,root2->lChild);
    }
    bool symmetric0(TreeNode* root){
      return symmetric(root,root);
    }
};
int main(){
  solution s0;
  TreeNode p1={1,nullptr,nullptr};
  TreeNode p2={2,nullptr,nullptr};
  TreeNode p3={2,nullptr,nullptr};
  TreeNode p4={3,nullptr,nullptr};
  TreeNode p5={4,nullptr,nullptr};
  TreeNode p6={4,nullptr,nullptr};
  TreeNode p7={3,nullptr,nullptr};
  p1.lChild=&p2;
  p1.rChild=&p3;
  p2.lChild=&p4;
  p2.rChild=&p5;
  p3.lChild=&p6;
  p3.rChild=&p7;

  auto ans=s0.symmetric0(&p1);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

