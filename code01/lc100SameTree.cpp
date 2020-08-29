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
    bool sameTree(TreeNode* p,TreeNode*q){
      if(!p&&!q) return true;
      if(!p||!q) return false;
      if(p->val!=q->val) return false;
      return sameTree(p->lChild,q->lChild)&& sameTree(p->rChild,q->rChild);
    }
};
int main(){
  solution s0;
  TreeNode p1={1,nullptr,nullptr};
  TreeNode p2={2,nullptr,nullptr};
  TreeNode p3={1,nullptr,nullptr};
  TreeNode q1={1,nullptr,nullptr};
  TreeNode q2={1,nullptr,nullptr};
  TreeNode q3={2,nullptr,nullptr};
  p1.lChild=&p2;
  p1.rChild=&p3;
  q1.lChild=&q2;
  q1.rChild=&q3;

  auto ans=s0.sameTree(&p1,&q1);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

