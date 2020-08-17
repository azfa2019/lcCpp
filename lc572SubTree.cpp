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
    bool subTree(TreeNode* s,TreeNode* t){
      if(!t) return true;
      if(!s) return false;
      if (sameTree(s,t)) return true;
      return subTree(s->lChild,t)||subTree(s->rChild,t);
    }
    bool sameTree(TreeNode* s,TreeNode* t){
      if(!s&&!t) return true;
      if(!s||!t) return false;
      return(s->val==t->val)&&sameTree(s->lChild,t->lChild)&&sameTree(s->rChild,t->rChild);
    }
};
int main(){
  solution s0;
  TreeNode n3={3,nullptr,nullptr};
  TreeNode n4={4,nullptr,nullptr};
  TreeNode n5={5,nullptr,nullptr};
  TreeNode n1={1,nullptr,nullptr};
  TreeNode n2={2,nullptr,nullptr};
  TreeNode n0={0,nullptr,nullptr};
  n3.lChild=&n4;
  n3.rChild=&n5;
  n4.lChild=&n1;
  n4.rChild=&n2;
  //n2.lChild=&n0;
  TreeNode p4={4,nullptr,nullptr};
  TreeNode p1={1,nullptr,nullptr};
  TreeNode p2={2,nullptr,nullptr};
  p4.lChild=&p1;
  p4.rChild=&p2;
  auto ans=s0.subTree(&n3,&p4);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

