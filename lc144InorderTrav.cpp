#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
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
    vector<int> preorderRecur(TreeNode* root){
      vector<int> ans{};
      function <void(TreeNode*)> preorderRecurHelper=[&](TreeNode* n){
        if(!n) return;
        ans.push_back(n->val);
        preorderRecurHelper(n->lChild);
        preorderRecurHelper(n->rChild);
      };
      preorderRecurHelper(root);
      return ans;
    }
    vector<int> preorderNonRecur(TreeNode* root){
      vector<int> ans;
      preorderNonRecurHelper(root,ans);
      return ans;
    }
    void preorderNonRecurHelper(TreeNode* root,vector<int>& ans){
      TreeNode* node=root;
      stack<TreeNode*> s;
      while(node!=nullptr||!s.empty()){
        while(node!=nullptr){
          ans.push_back(node->val);
          s.push(node);
          node=node->lChild;
        }
        if(!s.empty()){
          node=s.top();s.pop();
          node=node->rChild;
        }
      }
    }
};
int main(){
  solution s0;
  TreeNode root{1,nullptr,nullptr};
  TreeNode A{2,nullptr,nullptr};
  TreeNode B{3,nullptr,nullptr};
  root.rChild=&A;
  A.lChild=&B;
  auto ans=s0.preorderRecur(&root);
  showVector(ans);
  TreeNode root0{1,nullptr,nullptr};
  TreeNode n2{2,nullptr,nullptr};
  TreeNode n3{3,nullptr,nullptr};
  TreeNode n4{4,nullptr,nullptr};
  TreeNode n5{5,nullptr,nullptr};
  TreeNode n6{6,nullptr,nullptr};
  TreeNode n7{7,nullptr,nullptr};
  root0.lChild=&n2;
  root0.rChild=&n3;
  n2.lChild=&n4;
  n2.rChild=&n5;
  n3.lChild=&n6;
  n3.rChild=&n7;
  ans=s0.preorderRecur(&root0);
  showVector(ans);
  cout<<"================================"<<endl;
  ans=s0.preorderNonRecur(&root);
  showVector(ans);
  ans=s0.preorderNonRecur(&root0);
  showVector(ans);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

