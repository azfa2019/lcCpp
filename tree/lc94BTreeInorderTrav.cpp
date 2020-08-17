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
    //TreeNode(int x):val(x){};
};
class solution{
  public:
    void travRecurHelper(TreeNode* root,vector<int>& ans){
      if (root==nullptr) return;
      travRecurHelper(root->lChild,ans);
      ans.push_back(root->val);
      travRecurHelper(root->rChild,ans);
    }
    vector<int> travRecur(TreeNode* root){
      vector<int> ans{};
      travRecurHelper(root,ans);
      return ans;
    }
    void travNonRecurHelper(TreeNode* root,vector<int>& ans){
      //if(root==nullptr) return;
      TreeNode* node=root;
      stack<TreeNode*> s;
      while(node!=nullptr||!s.empty()){
        while(node!=nullptr){
          s.push(node);
          node=node->lChild;
        }
        if(!s.empty()){
          node=s.top();s.pop();
          ans.push_back(node->val);
          node=node->rChild;
        }
      }
    }
    vector<int> travNonRecur(TreeNode* root){
      vector<int> ans{};
      travNonRecurHelper(root,ans);
      return ans;
    }
};
int main(){
  solution s0;
  TreeNode root{1,nullptr,nullptr};
  TreeNode A{2,nullptr,nullptr};
  TreeNode B{3,nullptr,nullptr};
  root.rChild=&A;
  A.lChild=&B;
  auto ans=s0.travRecur(&root);
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
  ans=s0.travRecur(&root0);
  showVector(ans);
  cout<<"================================"<<endl;
  ans=s0.travNonRecur(&root);
  showVector(ans);
  ans=s0.travNonRecur(&root0);
  showVector(ans);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

