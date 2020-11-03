#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <memory>
using namespace std;
  template<typename T>
void showVector(vector<T> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << *it<<" "; //'\t' ; 
    cout << '\n'; 
} 
struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x):val(x),left(nullptr),right(nullptr){};
};
class Solution0{
  public:
    vector<int> distanceK(TreeNode*root,TreeNode*target,int k){
      buildGraph(nullptr,root);
      queue<TreeNode*>q;
      q.push(target);
      unordered_set<TreeNode*>seen;
      vector<int>ans;
      seen.insert(target);
      int step=0;
      while(!q.empty()&&step<=k){
        int size=q.size();
        while(size--){
          TreeNode* cur=q.front();q.pop();
          if(step==k) ans.push_back(cur->val);
          for(auto next:g[cur]){
            if(seen.count(next)) continue;
            seen.insert(next);
            q.push(next);
          }
        }
        step++;
      }
      return ans;
    }
  private:
    void buildGraph(TreeNode* parent,TreeNode* child){
      if(!child) return;
      if(parent){
        g[parent].push_back(child);
        g[child].push_back(parent);
      }
      if(child->left) buildGraph(child,child->left);
      if(child->right) buildGraph(child,child->right);
    }
    unordered_map<TreeNode*,vector<TreeNode*>>g;
};
int main(){
  Solution0 s0;
  TreeNode n3(3),n5(5),n1(1),n6(6),n2(2),n0(0),n8(8),n7(7),n4(4);
  n3.left=&n5,n3.right=&n1;
  n5.left=&n6,n5.right=&n2;
  n1.left=&n0,n1.right=&n8;
  n2.left=&n7,n2.right=&n4;
  auto ans0=s0.distanceK(&n3,&n5,2);
  showVector(ans0);
  //auto g=s0.buildGraph(nullptr,&n3);
  //for(auto e:g[&n2]) cout<<e->val<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

