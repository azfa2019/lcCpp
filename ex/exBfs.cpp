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

class Trans{
  // https://www.youtube.com/watch?v=bD8RT0ub--0
 public:
  map<string,string> bfs(map<string,vector<string>>& g,const string& s){
    queue<string> q{};
    set<string> seen{};
    q.push(s);
    seen.insert(s);
    map<string,string> parent{{s,"None"}};

    while(q.size()>0){
      string vertex=q.front();
      q.pop();
      cout<<vertex<<endl;
      vector <string> nodes=g[vertex];
      for (string e:nodes){
        if(seen.find(e)==seen.end()){
          q.push(e);
          seen.insert(e);
          parent.insert({e,vertex});
        }
      }
    }
    return parent;
  }
   int dfs(map<string,vector<string>>& g,const string& s){
    stack<string> q{};
    set<string> seen{};
    q.push(s);
    seen.insert(s);

    while(q.size()>0){
      string vertex=q.top();
      q.pop();
      cout<<vertex<<endl;
      vector <string> nodes=g[vertex];
      for (string e:nodes){
        if(seen.find(e)==seen.end()){
          q.push(e);
          seen.insert(e);
        }
      }
    }
    return 0;
  }
};
int main(){
  map<string,vector<string>> g{{"A",{"B","C"}},
    {"B",{"A","C","D"}},
    {"C",{"A","B","D","E"}},
    {"D",{"B","C","E","F"}},
    {"E",{"C","D"}},
    {"F",{"D"}}};
  Trans b;
  map<string,string> parent=b.bfs(g,"A");
  for(auto e: parent) cout<<e.first<<", "<<e.second<<endl;
  cout<<"================================"<<endl;
  parent=b.bfs(g,"E");
  for(auto e: parent) cout<<e.first<<", "<<e.second<<endl;
  cout<<"================================"<<endl;
  string v="B";
  while (v!="None"){
    cout<<v<<endl;
    v=parent[v];
  }
  //b.dfs(g,"A");
  cout<<"================================"<<endl;
  //b.dfs(g,"E");
  cout<<"================================"<<endl;
  return 0;
}
