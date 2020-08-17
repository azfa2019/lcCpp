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
class solution{
  public:
    vector<vector<int>> subsets(vector<int>& num){
      vector<vector<int>> ans;
      vector<int> cur;
      for(int i=0;i<=num.size();i++){
        dfs(num,i,0,cur,ans);
      }
      return ans;
    }
    void dfs(vector<int>& num,int n,int s,vector<int>& cur,vector<vector<int>>& ans){
      if(cur.size()==n) {
        ans.push_back(cur);
        return;
      }
      for (int i=s;i<num.size();i++){
        cur.push_back(num[i]);
        dfs(num,n,i+1,cur,ans);
        cur.pop_back();
      }
    }
};
int main(){
  vector<int> num{1,2,3};
  solution s0;
  auto ans=s0.subsets(num);
  for(auto e:ans){
    cout<<"{";
    for (auto f:e){
      cout<<f<<" ";
    }
    cout<<"}"<<endl;
  }
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

