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
};
class solution{
  public:
    vector<vector<int>> vertTrav(TreeNode* root){
      if(!root) return {};
      int minx=INT_MAX;
      int maxx=INT_MIN;
      map<pair<int,int>,set<int>> h;
      trav(root,0,0,minx,maxx,h);
      vector<vector<int>> ans(maxx-minx+1);
      for(auto e:h){
        int x=e.first.second-minx;
        ans[x].insert(end(ans[x]),begin(e.second),end(e.second));
      }
      return ans;
    }
    void trav(TreeNode* root,int x,int y,int& minx,int& maxx,map<pair<int,int>,set<int>>& h){
      if(! root) return;
      minx=min(minx,x); maxx=max(maxx,x);
      h[{y,x}].insert(root->val);
      if(root->lChild) trav(root->lChild,x-1,y+1,minx,maxx,h);
      if(root->rChild) trav(root->rChild,x+1,y+1,minx,maxx,h);
    }
};
int main(){
  solution s0;
  TreeNode n1={1,nullptr,nullptr};
  TreeNode n2={2,nullptr,nullptr};
  TreeNode n3={3,nullptr,nullptr};
  TreeNode n4={4,nullptr,nullptr};
  TreeNode n5={5,nullptr,nullptr};
  TreeNode n6={6,nullptr,nullptr};
  TreeNode n7={7,nullptr,nullptr};
  n1.lChild=&n2;
  n1.rChild=&n3;
  n2.lChild=&n4;
  n2.rChild=&n5;
  n3.lChild=&n6;
  n3.rChild=&n7;
  auto ans=s0.vertTrav(&n1);
  for(auto e:ans) showVector(e);
  cout<<"================================"<<endl;
  TreeNode t3={3,nullptr,nullptr};
  TreeNode t9={9,nullptr,nullptr};
  TreeNode t20={20,nullptr,nullptr};
  TreeNode t15={15,nullptr,nullptr};
  TreeNode t7={7,nullptr,nullptr};
  t3.lChild=&t9;
  t3.rChild=&t20;
  t20.lChild=&t15;
  t20.rChild=&t7;
  ans=s0.vertTrav(&t3);
  for(auto e:ans) showVector(e);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

