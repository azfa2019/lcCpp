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
class FenwickTree{
  public:
    FenwickTree(int n):sums(n+1,0){};
    void update(int i,int delta){
      while(i<sums.size()) {
        sums[i]+=delta;
        i+=lowbit(i);
      }
    }
    int query(int i){
      int sum=0;
      while(i>0){
        sum+=sums[i];
        i-=lowbit(i);
      }
      return sum;
    }
  private:
    vector<int> sums;
    int lowbit(int x){return x&(-x);}
};
class solution0{
  public:
    vector<int> countSmaller(vector<int>& nums){
      set<int> sorted(nums.begin(),nums.end());
      FenwickTree tree(nums.size());
      vector<int> ans;
      unordered_map<int,int> ranks;
      int rank=0;
      for(auto e:sorted) ranks[e]=++rank;
      for(int i=nums.size()-1;i>=0;i--){
        tree.update(ranks[nums[i]],1);
        ans.push_back(tree.query(ranks[nums[i]]-1));
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};
struct BSTNode{
  int val; int count; int leftCount;
  BSTNode* left; BSTNode* right;
  BSTNode(int val):val(val),count(1),leftCount(0),left{nullptr},right{nullptr}{};
  ~BSTNode(){delete left; delete right;}
  int lessOrEqual(){return count+leftCount;}
};
class Solution1{
  public:
    vector<int> countSmaller(vector<int>& nums){
      if(nums.empty()) return {};
      reverse(nums.begin(),nums.end());
      unique_ptr<BSTNode> root(new BSTNode(nums[0]));
      vector<int> ans{0};
      for(int i=1;i<nums.size();++i){
        ans.push_back(insert(root.get(),nums[i]));
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
  private:
    int insert(BSTNode* root,int val){
      if(root->val==val){
        ++root->count;
        return root->leftCount;
      }
      else if(root->val>val){
        ++root->count;
        if(root->left==nullptr){
          root->left=new BSTNode(val);
          return 0;
        }
        return insert(root->left,val);
      }
      else{
        if(root->right==nullptr){
          root->right=new BSTNode(val);
          return root->lessOrEqual();
        }
        return root->lessOrEqual()+insert(root->right,val);
      }
    }
};
int main(){
  solution0 s0;
  vector<int> num{7,1,3,2,9,2,1};
  auto ans0=s0.countSmaller(num);
  showVector(ans0);
  cout<<"================================"<<endl;
  Solution1 s1;
  auto ans1=s1.countSmaller(num);
  showVector(ans1);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

