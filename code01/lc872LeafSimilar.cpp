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
    bool leafSimilar(TreeNode* root1,TreeNode* root2){
      vector<int> leaf1,leaf2;
      getLeaf(root1,leaf1);
      getLeaf(root2,leaf2);
      return leaf1==leaf2;
    }
    void getLeaf(TreeNode* root,vector<int>& ans){
      if(!root) return;
      if (root->lChild==nullptr &&root->rChild==nullptr)ans.push_back(root->val);
      getLeaf(root->lChild,ans);
      getLeaf(root->rChild,ans);
    }
};
int main(){
  solution s0;
  TreeNode n3={3,nullptr,nullptr};
  TreeNode n5={5,nullptr,nullptr};
  TreeNode n1={1,nullptr,nullptr};
  TreeNode n6={6,nullptr,nullptr};
  TreeNode n2={2,nullptr,nullptr};
  TreeNode n9={9,nullptr,nullptr};
  TreeNode n8={8,nullptr,nullptr};
  TreeNode n7={7,nullptr,nullptr};
  TreeNode n4={4,nullptr,nullptr};
  n3.lChild=&n5;
  n3.rChild=&n1;
  n5.lChild=&n6;
  n5.rChild=&n2;
  n1.lChild=&n9;
  n1.rChild=&n8;
  n2.lChild=&n7;
  n2.rChild=&n4;
  auto ans=s0.leafSimilar(&n3,&n3);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

