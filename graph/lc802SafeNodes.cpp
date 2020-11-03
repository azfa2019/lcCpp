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
    vector<int> safeNodes(vector<vector<int>>&g){
      vector<int>ans;
      vector<State>states(g.size(),UNKNOWN);
      for(int i=0;i<g.size();i++){
        if(dfs(i,g,states)==SAFE) ans.push_back(i);
      }
      return ans;
    }
  private:
    enum State{SAFE,UNSAFE,UNKNOWN,VISITING};
    State dfs(int cur,vector<vector<int>>&g,vector<State>&states){
      if(states[cur]==VISITING) return UNSAFE;
      if(states[cur]!=UNKNOWN) return states[cur];
      states[cur]=VISITING;
      for(int i:g[cur]) if (dfs(i,g,states)==UNSAFE) return states[cur]=UNSAFE;
      return states[cur]=SAFE;
    }
};
int main(){
  Solution0 s0;
  vector<vector<int>>g{{1,2},{2,3},{5},{0},{5},{},{}};
  auto ans0=s0.safeNodes(g);
  showVector(ans0);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

