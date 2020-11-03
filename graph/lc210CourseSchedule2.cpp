#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
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
class Solution0{
  public:
    vector<int>findOrder(int num,vector<pair<int,int>>&pre){
      vector<vector<int>> graph(num);
      vector<int>ans,v(num,0);
      for(auto p:pre) graph[p.second].push_back(p.first);
      for(int i=0;i<num;i++) if(dfs(i,graph,v,ans)) return {};
      reverse(ans.begin(),ans.end());
      return ans;
    }
  private:
    bool dfs(int cur,vector<vector<int>>&graph,vector<int>&v,vector<int>&ans){
      if(v[cur]==1) return true;
      if(v[cur]==2) return false;
      v[cur]=1;
      for(int i:graph[cur]) if(dfs(i,graph,v,ans)) return true;
      v[cur]=2;
      ans.push_back(cur);
      return false;
    }
};
int main(){
  Solution0 s0;
  int num=4;
  vector<pair<int,int>>pre{{1,0},{2,0},{3,1},{3,2}};
  auto ans0=s0.findOrder(num,pre);
  showVector(ans0);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

