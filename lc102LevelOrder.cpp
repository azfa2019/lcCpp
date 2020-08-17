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
    vector<vector<int>> levelOrder0(TreeNode* root){
      if(!root) return {};
      vector<vector<int>> ans;
      vector<TreeNode*> cur,next;
      cur.push_back(root);
      while(cur.size()>0){
        ans.push_back({});
        for(auto node:cur){
          ans.back().push_back(node->val);
          if(node->lChild) next.push_back(node->lChild);
          if(node->rChild) next.push_back(node->rChild);
        }
        cur.swap(next);
        next.clear();
      }
      return ans;
    }
    void dfs(TreeNode* root,int depth,vector<vector<int>>& ans){
      if(!root) return;
      while (ans.size()<=depth) ans.push_back({});
      ans[depth].push_back(root->val);
      dfs(root->lChild,depth+1,ans);
      dfs(root->rChild,depth+1,ans);
    }
    vector<vector<int>> levelOrder1(TreeNode* root){
      vector<vector<int>> ans;
      dfs(root,0,ans);
      return ans;
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
  auto ans=s0.levelOrder0(&n3);
  for(auto e:ans) showVector(e);
  cout<<"================================"<<endl;
  ans=s0.levelOrder1(&n3);
  for(auto e:ans) showVector(e);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

