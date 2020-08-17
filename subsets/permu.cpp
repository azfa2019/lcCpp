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
    vector<vector<int>> permu(vector<int>num){
      vector<vector<int>> ans;
      vector<int> cur;
      vector<bool> used(num.size(),false);
      for(int i=0;i<=num.size();i++){
        dfs(num,i,cur,ans,used);
      }
      return ans;
    }
    void dfs(vector<int>& num,int n, vector<int>& cur,vector<vector<int>>& ans,vector<bool> used){
      if(cur.size()==n){
        ans.push_back(cur);
        return;
      }
      for(int i=0;i<num.size();i++){
        if(used[i]) continue;
        used[i]=true;
        cur.push_back(num[i]);
        dfs(num,n,cur,ans,used);
        cur.pop_back();
        used[i]=false;
      }
    }
};
int main(){
  vector<int> num{0,1,2};
  solution s0;
  auto ans =s0.permu(num);
  for(auto e:ans){
    cout<<"(";
    for(auto f:e) cout<<f<<" ";
    cout<<")"<<endl;
  }
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

