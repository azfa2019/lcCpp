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
    int sumNumbers(TreeNode* root){
      if(!root) return 0;
      int ans=0;
      function<void(TreeNode*,int)> trav=[&](TreeNode* t,int num){
        if(!t) return;
        num=num*10+t->val;
        if(t->lChild||t->rChild){
          trav(t->lChild,num);
          trav(t->rChild,num);
        } else{
          ans+=num;
        }
      };
      trav(root,0);
      return ans;
    }
};
int main(){
  solution s0;
  TreeNode* n4=new TreeNode(4);
  TreeNode* n9=new TreeNode(9);
  TreeNode* n0=new TreeNode(0);
  TreeNode* n5=new TreeNode(5);
  TreeNode* n1=new TreeNode(1);
  n4->lChild=n9;
  n4->rChild=n0;
  n9->lChild=n5;
  n9->rChild=n1;
  printTree(n4); cout<<endl;
  //TreeNode* ans=s0.trim0(n3,1,3);
  auto ans=s0.sumNumbers(n4);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

