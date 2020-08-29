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
    int minHeight(TreeNode* root){
      if(!root) return 0;
      if(!root->lChild&&!root->rChild) return 1;
      int l=root->lChild?minHeight(root->lChild):INT_MAX;
      int r=root->rChild?minHeight(root->rChild):INT_MAX;
      return min(l,r)+1;
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
  auto ans=s0.minHeight(&n3);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

