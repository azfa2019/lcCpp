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
#include<sstream>
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
    vector<int> freqSum(TreeNode* root){
      vector<int> ans;
      unordered_map<int,int> freqs;
      int maxFreq=-1;
      treeSum(root,ans,freqs,maxFreq);
      return ans;
    }
  private:
    int treeSum(TreeNode* root,vector<int>& ans,unordered_map<int,int>& freqs,int& maxFreq){
      if(!root) return 0;
      int sum=root->val+treeSum(root->lChild,ans,freqs,maxFreq)+treeSum(root->rChild,ans,freqs,maxFreq);;
      int freq=++freqs[sum];
      if(freq>maxFreq){
        maxFreq=freq;
        ans.clear();
      }
      if(freq==maxFreq) ans.push_back(sum);
      return sum;
    }
};
int main(){
  solution s0;
  TreeNode* n1=new TreeNode(1);
  TreeNode* n2=new TreeNode(2);
  TreeNode* n3=new TreeNode(3);
  TreeNode* n4=new TreeNode(4);
  TreeNode* n5=new TreeNode(5);
  TreeNode* n6=new TreeNode(6);
  TreeNode* n8=new TreeNode(8);
  TreeNode* n_3=new TreeNode(-3);
  n5->lChild=n2;
  n5->rChild=n_3;
  printTree(n5); cout<<endl;
  auto ans01=s0.freqSum(n5);
  showVector(ans01);
  cout<<"================================"<<endl;
  TreeNode* p1=new TreeNode(1);
  TreeNode* p2=new TreeNode(2);
  TreeNode* p3=new TreeNode(3);
  TreeNode* p4=new TreeNode(4);
  TreeNode* p5=new TreeNode(5);
  TreeNode* p6=new TreeNode(6);
  TreeNode* p8=new TreeNode(8);
  TreeNode* p_5=new TreeNode(-5);
  p5->lChild=p2;
  p5->rChild=p_5;
  auto ans02=s0.freqSum(p5);
  showVector(ans02);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

