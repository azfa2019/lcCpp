#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
  int val;
  TreeNode* left=nullptr;
  TreeNode* right=nullptr;
  TreeNode(int x):val(x){}
  ~TreeNode(){
    delete left;
    delete right;
    left=nullptr;
    right=nullptr;
  }
};

class Solution{
 public:
  TreeNode* sortedArrayToBst(vector<int>& nums){
    return buildBst(nums,0,nums.size()-1);
  }
   private:
  TreeNode* buildBst(const vector<int>& nums,int l, int r){
    if(l>r) return nullptr;
    int m=l+(r-l)/2;
    TreeNode* root=new TreeNode(nums[m]);
    root->left=buildBst(nums,l,m-1);
    root->right=buildBst(nums,m+1,r);
    return root;
  }
};
int main(){
  vector<int> nums={-10,-3,0,5,9};

  Solution s1;
  TreeNode* res=s1.sortedArrayToBst(nums);
  cout<<res->left->val<<endl;
  return 0;
}


