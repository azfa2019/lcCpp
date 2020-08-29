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
    int subArraySum(vector<int>& num,int k){
      int n=num.size();
      vector<int> sum(n+1,0);
      for(int i=1;i<=n;i++) sum[i]=sum[i-1]+num[i-1];
      int ans=0;
      for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
          if (sum[j+1]-sum[i]==k) ans++;
      return ans;
    }
    int subArraySum1(vector<int> nums,int k){
      if(nums.size()==0) return 0;
      unordered_map<int,int> count{{0,1}};
      int curSum=0; int ans=0;
      for(int num:nums){
        curSum+=num;
        ans+=count[curSum-k];
        ++count[curSum];
      }
      return ans;
    }
};
int main(){
  solution s0;
  vector<int> num{1,1,1};
  auto ans=s0.subArraySum(num,2);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  ans=s0.subArraySum1(num,2);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

