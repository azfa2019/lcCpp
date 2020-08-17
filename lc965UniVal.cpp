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
    bool uniVal(TreeNode* root){
      if(!root) return true;
      if(root->lChild&&(root->lChild->val!=root->val)) return false;
      if(root->rChild&&(root->rChild->val!=root->val)) return false;
      return uniVal(root->lChild)&&uniVal(root->rChild);
    }
};
int main(){
  solution s0;
  TreeNode n1a={1,nullptr,nullptr};
  TreeNode n1b={1,nullptr,nullptr};
  TreeNode n1c={1,nullptr,nullptr};
  TreeNode n1d={1,nullptr,nullptr};
  TreeNode n1e={1,nullptr,nullptr};
  TreeNode n1f={1,nullptr,nullptr};
  n1a.lChild=&n1b;
  n1a.rChild=&n1c;
  n1b.lChild=&n1d;
  n1b.rChild=&n1e;
  n1c.rChild=&n1f;
  auto ans=s0.uniVal(&n1a);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  TreeNode p1a={2,nullptr,nullptr};
  TreeNode p1b={2,nullptr,nullptr};
  TreeNode p1c={2,nullptr,nullptr};
  TreeNode p1d={5,nullptr,nullptr};
  TreeNode p1e={2,nullptr,nullptr};
  p1a.lChild=&p1b;
  p1a.rChild=&p1c;
  p1b.lChild=&p1d;
  p1b.rChild=&p1e;
  ans=s0.uniVal(&p1a);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

