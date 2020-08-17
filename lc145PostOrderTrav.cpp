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
    void postOrderRecurHelper(TreeNode* root,vector<int>& ans){
      if(root==nullptr) return;
      postOrderRecurHelper(root->lChild,ans);
      postOrderRecurHelper(root->rChild,ans);
      ans.push_back(root->val);
    }
    vector<int> postOrderRecur(TreeNode* root){
      vector<int> ans;
      postOrderRecurHelper(root,ans);
      return ans;
    }
    vector<int> postOrderNonRecur(TreeNode *root){
      stack<TreeNode*> s;
      deque<int> ans;
      s.push(root);
      while(s.size()>0){
        TreeNode* n=s.top();s.pop();
        ans.push_front(n->val);
        if(n->lChild) s.push(n->lChild);
        if(n->rChild) s.push(n->rChild);
      }
      return vector<int>(ans.begin(),ans.end());
    }
};

int main(){
  solution s0;
  TreeNode t{4,nullptr,nullptr};
  TreeNode n1{1,nullptr,nullptr};
  TreeNode n3{3,nullptr,nullptr};
  TreeNode n2{2,nullptr,nullptr};
  t.lChild=&n1;
  t.rChild=&n3;
  n3.lChild=&n2;
  auto ans=s0.postOrderRecur(&t);
  showVector(ans);
  cout<<"================================"<<endl;
  ans=s0.postOrderNonRecur(&t);
  showVector(ans);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

