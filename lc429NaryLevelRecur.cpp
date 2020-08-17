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
    vector<TreeNode*> children;
};
class solution{
  public:
    vector<vector<int>> levelOrder(TreeNode* root){
      if(!root) return {};
      vector<vector<int>> ans;
      preorder(root,0,ans);
      return ans;
    }
    void preorder(TreeNode* root,int depth,vector<vector<int>>& ans){
      if(!root) return;
      while(ans.size()<=depth) ans.push_back({});
      ans[depth].push_back(root->val);
      for(auto e:root->children){
        preorder(e,depth+1,ans);
      }
    }
};
int main(){
  solution s0;
  TreeNode n1={1,{}};
  TreeNode n3={3,{}};
  TreeNode n2={2,{}};
  TreeNode n4={4,{}};
  TreeNode n5={5,{}};
  TreeNode n6={6,{}};
  n1.children.push_back(&n3);
  n1.children.push_back(&n2);
  n1.children.push_back(&n4);
  n3.children.push_back(&n5);
  n3.children.push_back(&n6);
  auto ans=s0.levelOrder(&n1);
  for(auto e:ans) showVector(e);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

