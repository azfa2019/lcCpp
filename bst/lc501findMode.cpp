#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
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
  TreeNode *left,*right;
  TreeNode(int val):val(val),left(nullptr),right(nullptr){};
};
class Solution0{
  public:
    vector<int> findMode(TreeNode *root){
      inOrder(root);
      return ans_;
    }
  private:
    int val_=0,maxCount_=0,count_=0;
    vector<int> ans_;
    void inOrder(TreeNode *root){
      if(!root) return;
      inOrder(root->left);
      visit(root->val);
      inOrder(root->right);
    }

    void visit(int val){
      if(count_>0&&val_==val) count_++;
      else{
        val_=val;
        count_=1;
      }
      if(count_>maxCount_) {
        maxCount_=count_;
        ans_.clear();
      }
      if(count_==maxCount_) ans_.push_back(val);
    }
};
class Solution1{
  public:
    vector<int> findMode(TreeNode *root){
      inOrder(root);
      modeCount_=maxCount_;
      inOrder(root);
      return ans_;
    }
  private:
    int count_=0,maxCount_=0,val_=0,modeCount_=INT_MAX;
    vector<int> ans_;
    void inOrder(TreeNode *root){
      if(!root) return;
      inOrder(root->left);
      visit(root->val);
      inOrder(root->right);
    }
    void visit(int val){
      if(count_>0&&val_==val) ++count_;
      else{
        val_=val;
        count_=1;
      }
      if(count_>maxCount_) maxCount_=count_;
      if(count_==modeCount_) ans_.push_back(val);
    }
};
int main(){
  Solution0 s0;
  TreeNode n0(1),n1(2),n2(2),n3(2),n4(3);
  n0.right=&n1,n1.left=&n2;
  auto ans0=s0.findMode(&n0);
  showVector(ans0);
  cout<<"================================"<<endl;
  Solution1 s1;
  auto ans1=s1.findMode(&n0);
  showVector(ans1);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

