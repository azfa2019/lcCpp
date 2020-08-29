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
    int maxDepth(TreeNode* root){
      if(!root) return 0;
      int l=maxDepth(root->lChild);
      int r=maxDepth(root->rChild);
      return max(l,r)+1;
    }
};
int main(){
  solution s0;
  TreeNode p3={3,nullptr,nullptr};
  TreeNode p9={9,nullptr,nullptr};
  TreeNode p20={20,nullptr,nullptr};
  TreeNode p15={15,nullptr,nullptr};
  TreeNode p7={7,nullptr,nullptr};
  p3.lChild=&p9;
  p3.rChild=&p20;
  p20.lChild=&p15;
  p20.rChild=&p7;

  auto ans=s0.maxDepth(&p3);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

