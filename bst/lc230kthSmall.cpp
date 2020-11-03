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
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val):val(val),left(nullptr),right(nullptr){};
};
class Solution0{
  public:
    int kthSmallest(TreeNode *root,int k){
      return inOrder(root,k);
    }
  public:
    int inOrder(TreeNode *root,int &k){
      if(!root) return -1;
      int x=inOrder(root->left,k);
      if(k==0) return x;
      if(--k==0) return root->val;
      return inOrder(root->right,k);
    }
};
int main(){
  Solution0 s0;
  TreeNode n0(3),n1(1),n2(4),n3(2),n4(3);
  n0.left=&n1,n0.right=&n2,n1.right=&n3;
  auto ans0=s0.kthSmallest(&n0,4);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

