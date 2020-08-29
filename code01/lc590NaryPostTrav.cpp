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
    vector<TreeNode*> children;
};
class solution{
  public:
    vector<int> postTrav(TreeNode* root){
      if(!root) return {};
      stack<TreeNode*> s;
      deque<int> ans;
      s.push(root);
      TreeNode* node;
      while(!s.empty()){
          node=s.top();s.pop();
          ans.push_front(node->val);
          if(node->children.size()>0){
            for (auto it=node->children.begin();it!=node->children.end();it++) s.push(*it);
          }
      }
      return vector<int>(ans.begin(),ans.end());
    }
};
int main(){
  solution s0;
  TreeNode t={1,{}};
  TreeNode n3={3,{}};
  TreeNode n2={2,{}};
  TreeNode n4={4,{}};
  TreeNode n5={5,{}};
  TreeNode n6={6,{}};
  t.children.push_back(&n3);
  t.children.push_back(&n2);
  t.children.push_back(&n4);
  n3.children.push_back(&n5);
  n3.children.push_back(&n6);
  auto ans=s0.postTrav(&t);
  showVector(ans);
  cout<<"================================"<<endl;
  TreeNode p1={1,{}};
  TreeNode p2={2,{}};
  TreeNode p3={3,{}};
  TreeNode p4={4,{}};
  TreeNode p5={5,{}};
  TreeNode p6={6,{}};
  TreeNode p7={7,{}};
  TreeNode p8={8,{}};
  TreeNode p9={9,{}};
  TreeNode p10={10,{}};
  TreeNode p11={11,{}};
  TreeNode p12={12,{}};
  TreeNode p13={13,{}};
  TreeNode p14={14,{}};
  p1.children.push_back(&p2);
  p1.children.push_back(&p3);
  p1.children.push_back(&p4);
  p1.children.push_back(&p5);
  p3.children.push_back(&p6);
  p3.children.push_back(&p7);
  p4.children.push_back(&p8);
  p5.children.push_back(&p9);
  p5.children.push_back(&p10);
  p7.children.push_back(&p11);
  p8.children.push_back(&p12);
  p9.children.push_back(&p13);
  p11.children.push_back(&p14);
  ans=s0.postTrav(&p1);
  showVector(ans);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

