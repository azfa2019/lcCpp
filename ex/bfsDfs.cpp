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
class Solution0{
  public:
    pair<vector<string>,map<string,string>> bfs(map<string,vector<string>>g,string s){
      vector<string> ans;
      map<string,bool>seen;
      map<string,string>parent;
      for(auto e:g) seen[e.first]=false;
      queue<string> q;
      q.push(s);
      seen[s]=true;
      parent[s]="none";
      while(q.size()>0){
        string v=q.front();q.pop();
        ans.push_back(v);
        for(auto w:g[v]){
          if(!seen[w]){
            q.push(w);
            seen[w]=true;
            parent[w]=v;
          }
        }
      }
      return pair(ans,parent);
    }
    vector<string> dfs(map<string,vector<string>>g,string s){
      vector<string> ans;
      map<string,bool>seen;
      for(auto e:g) seen[e.first]=false;
      stack<string> q;
      q.push(s);
      seen[s]=true;
      while(q.size()>0){
        string v=q.top();q.pop();
        ans.push_back(v);
        for(auto w:g[v]){
          if(!seen[w]){
            q.push(w);
            seen[w]=true;
          }
        }
      }
      return ans;
    }
};

int main(){
  Solution0 s0;
  map<string,vector<string>> g{
    {"A",{"B","C"}},
      {"B",{"A","C","D"}},
      {"C",{"A","B","D","E"}},
      {"D",{"B","C","E","F"}},
      {"E",{"C","D"}},
      {"F",{"D"}}
  };
  auto ans0=s0.bfs(g,"A");
  showVector(ans0.first);
  for(auto e:ans0.second) cout<<e.first<<": "<<e.second<<endl;

  string s="E";
  auto parent=ans0.second;
  while(s!="none") {
    cout<<s<<" ";
    s=parent[s];
  }
  cout<<endl;
  cout<<"================================"<<endl;
  ans0=s0.bfs(g,"E");
  showVector(ans0.first);
  for(auto e:ans0.second) cout<<e.first<<": "<<e.second<<endl;
  cout<<"================================"<<endl;
  auto ans1=s0.dfs(g,"A");
  showVector(ans1);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

