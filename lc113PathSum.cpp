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
    vector<vector<int>> pathSum(TreeNode* root,int sum){
      if(!root) return {};
      vector<int> cur; vector<vector<int>> ans;
      helper(root,sum,cur,ans);
      return ans;
    }
  private:
    void helper(TreeNode* root,int sum,vector<int>& cur,vector<vector<int>>& ans){
      if(!root) return;
      if(!root->lChild && !root->rChild){
        if(root->val==sum){
          cur.push_back(root->val);
          ans.push_back(cur);
          cur.pop_back();
        }
        return;
      }
      int newSum=sum-root->val;
      cur.push_back(root->val);
      helper(root->lChild,newSum,cur,ans);
      helper(root->rChild,newSum,cur,ans);
      cur.pop_back();
    }
};
int main(){
  solution s0;
  TreeNode* n5=new TreeNode(5);
  TreeNode* n4=new TreeNode(4);
  TreeNode* n8=new TreeNode(8);
  TreeNode* n11=new TreeNode(11);
  TreeNode* n13=new TreeNode(13);
  TreeNode* n4a=new TreeNode(4);
  TreeNode* n7=new TreeNode(7);
  TreeNode* n2=new TreeNode(2);
  TreeNode* n5a=new TreeNode(5);
  TreeNode* n1=new TreeNode(1);
  n5->lChild=n4;
  n5->rChild=n8;
  n4->lChild=n11;
  n8->lChild=n13;
  n8->rChild=n4a;
  n11->lChild=n7;
  n11->rChild=n2;
  n4a->lChild=n5a;
  n4a->rChild=n1;
  printTree(n5); cout<<endl;
  //TreeNode* ans=s0.trim0(n3,1,3);
  auto ans=s0.pathSum(n5,22);
  for(auto e:ans) showVector(e);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

