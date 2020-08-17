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

class Solution{
  public:
//https://www.youtube.com/watch?v=bD8RT0ub--0
    void bfs(map<string,vector<string>>& g, const string& s){
      map<string,bool> seen;
      for (auto e:g) seen[e.first]=false;
      queue<string> q;
      q.push(s); seen[s]=true;
      while(q.size()>0){
        string v=q.front();q.pop();
        cout<<v<<endl;
        vector<string> vs=g[v];
        for (auto e:vs){
          if(!seen[e]) {
            q.push(e); seen[e]=true;
          }
        }
      }
    }
    void dfs(map<string,vector<string>> g,string s){
      map<string,bool> seen;
      for(auto e: g) seen[e.first]=false;
      stack<string> s0;
      s0.push(s); seen[s]=true;
      while(s0.size()>0){
        string v=s0.top(); s0.pop();
        cout<<v<<endl;
        vector<string> vs=g[v];
        for (auto e:vs){
          if(!seen[e]){
            s0.push(e);
            seen[e]=true;
          }
        }
      }
    }
};
int main(){
  map<string,vector<string>> g{{"A",{"B","C"}},
    {"B",{"A","C","D"}},
    {"C",{"A","B","D","E"}},
    {"D",{"B","C","E","F"}},
    {"E",{"C","D"}},
    {"F",{"D"}}};
  Solution s0;
  s0.bfs(g,"E");
  cout<<"================================"<<endl;
  s0.dfs(g,"A");
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

