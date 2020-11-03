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
    bool canFinish(int num,vector<pair<int,int>>&pre){
      vector<int>v(num,0);
      graph=vector<vector<int>>(num);
      for(auto p:pre) graph[p.first].push_back(p.second);
      for(int i=0;i<num;i++) if(dfs(i,v)) return false;
      return true;
    }
  private:
    vector<vector<int>>graph;
    bool dfs(int cur,vector<int>&v){
      if(v[cur]==1) return true;
      if(v[cur]==2) return false;
      v[cur]=1;
      for(int i:graph[cur])
        if(dfs(i,v)) return true;
      v[cur]=2;
      return false;
    }
};
int main(){
  Solution0 s0;
  vector<pair<int,int>>pre{{1,0},{2,6},{1,7},{6,4},{7,0},{0,5}};
  int num=8;
  bool ans0=s0.canFinish(num,pre);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

