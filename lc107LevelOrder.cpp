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
    vector<vector<int>> levelOrder(TreeNode* root){
      if(!root) return {};
      vector<vector<int>> ans;
      dfs(root,0,ans);
      reverse(ans.begin(),ans.end());
      return ans;
    }
    void dfs(TreeNode* root,int depth,vector<vector<int>>& ans){
      if(!root) return;
      while(ans.size()<=depth) ans.push_back({});
      ans[depth].push_back(root->val);
      dfs(root->lChild,depth+1,ans);
      dfs(root->rChild,depth+1,ans);
    }
    vector<vector<int>> level2(TreeNode* root){
      queue<TreeNode*> q;
      vector<vector<int>> ans;
      q.push(root);
      vector<int> cur;
      while(!q.empty()){
        int size=q.size();
        while(size--){
          TreeNode* node=q.front();q.pop();
          cur.push_back(node->val);
          if(node->lChild) q.push(node->lChild);
          if(node->rChild) q.push(node->rChild);
        }
        ans.push_back(cur);
        cur.clear();
      }
      reverse(ans.begin(),ans.end());
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
  auto ans=s0.levelOrder(&n3);
  for(auto e:ans) showVector(e);
  cout<<"================================"<<endl;
  ans=s0.level2(&n3);
  for(auto e:ans) showVector(e);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

