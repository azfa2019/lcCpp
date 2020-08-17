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
struct TreeNode{
  int val;
  TreeNode* left=nullptr;
  TreeNode* right=nullptr;
  TreeNode(int x):val(x){};
  ~TreeNode(){
    delete left;
    delete right;
    left=nullptr;
    right=nullptr;
  }
};
class Solution{
 public:
  TreeNode* convert(vector<int> nums){
    return helper(nums,0,nums.size()-1);
  }
  TreeNode* helper(vector<int>nums,int l,int r){
    if(l>r) return nullptr;
    int m=l+(r-l)/2;
    TreeNode* root=new TreeNode(nums[m]);
    root->left=helper(nums,l,m-1);
    root->right=helper(nums,m+1,r);
    return root;
  }
};

int main(){

  vector<int> nums{-10,-3,0,5,9};
  Solution s0;
  TreeNode* root=s0.convert(nums);
  cout<<(root->left)->val<<endl;
  cout<<(root->right)->val<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

