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
    int leafSum(TreeNode* root){
      if(!root) return {};
      int sum=0,maxdepth=0;
      function<void(TreeNode*,int)> dfs=[&](TreeNode* n,int d){
        if(!n) return;
        if(d>maxdepth) {
          maxdepth=d;
          sum=0;
        }
        if(d==maxdepth) sum+=n->val;
        dfs(n->lChild,d+1); 
        dfs(n->rChild,d+1); 
      };
      dfs(root,0);
      return sum;
    }
};
int main(){
  solution s0;
  TreeNode n1={1,nullptr,nullptr};
  TreeNode n2={2,nullptr,nullptr};
  TreeNode n3={3,nullptr,nullptr};
  TreeNode n4={4,nullptr,nullptr};
  TreeNode n5={5,nullptr,nullptr};
  TreeNode n6={6,nullptr,nullptr};
  TreeNode n7={7,nullptr,nullptr};
  TreeNode n8={8,nullptr,nullptr};
  n1.lChild=&n2;
  n1.rChild=&n3;
  n2.lChild=&n4;
  n2.rChild=&n5;
  n3.rChild=&n6;
  n4.lChild=&n7;
  n6.rChild=&n8;
  auto ans=s0.leafSum(&n1);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

