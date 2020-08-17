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
    TreeNode(int x):val(x),lChild(nullptr),rChild(nullptr){};
};
void printTree(TreeNode* root){
  if(!root) {
    cout<<"null ";
    return;
  }
  if(!root->lChild && !root->rChild) cout<<root->val<<" ";
  else{
    cout<<root->val<<" ";
    printTree(root->lChild);
    printTree(root->rChild);
  }
}
class solution{
  public:
    vector<string> btreePath(TreeNode* root){
      vector<string> res;
      helper1(root,"",res);
      return res;
    }
    void helper1(TreeNode* root,string out,vector<string>& res){
      if(!root) return;
      if(!root->lChild&&!root->rChild) res.push_back(out+to_string(root->val));
      helper1(root->lChild,out+to_string(root->val)+"->",res);
      helper1(root->rChild,out+to_string(root->val)+"->",res);
    }
    vector<vector<int>> bstPath(TreeNode* root){
      if(!root) return {};
      vector<int> cur;
      vector<vector<int>> ans;
      helper(root,cur,ans);
      return ans;
    }
    void helper(TreeNode* root,vector<int>& cur,vector<vector<int>>& ans){
      if(!root) return;
      cur.push_back(root->val);
      if(!root->lChild&& !root->rChild) {
        ans.push_back(cur);
        cur.pop_back();
        return;
      }
      helper(root->lChild,cur,ans);
      helper(root->rChild,cur,ans);
      cur.pop_back();
      return;
    }
};
int main(){
  solution s0;
  TreeNode* n1=new TreeNode(1);
  TreeNode* n2=new TreeNode(2);
  TreeNode* n3=new TreeNode(3);
  TreeNode* n5=new TreeNode(5);
  TreeNode* n4=new TreeNode(4);
  n1->lChild=n2;
  n1->rChild=n3;
  n2->rChild=n5;
  n2->lChild=n4;
  printTree(n1); cout<<endl;
  //TreeNode* ans=s0.trim0(n3,1,3);
  auto ans=s0.bstPath(n1);
  for(auto e:ans) showVector(e);
  cout<<"================================"<<endl;
  auto ans1=s0.btreePath(n1);
  for(auto e:ans1) cout<<e<<endl;;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

