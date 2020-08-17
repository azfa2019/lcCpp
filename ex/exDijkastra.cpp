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
 public:
  map<string,int> init_distance(map<string,map<string,int>>& g,string s){
    map<string,int> distance{{s,0}};
    for (auto e:g){
      if(e.first!=s) distance.insert(pair(e.first,1000));
    }
    return distance;
  };
  tuple<map<string,string>,map<string,int>>  dijkastra(map<string,map<string,int>>& g,const string& s){
    auto compare = [](pair<int,string> a,pair<int,string> b) { return a.first > b.first; };
    priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(compare)> q(compare);
    q.push(pair(0,s));
    set<string> seen{};
    map<string,string> parent{{s,"None"}};
    map<string,int> distance=init_distance(g,s);

    while(q.size()>0){
      auto pair0=q.top();
      int dist =pair0.first;
      string vertex=pair0.second;
      q.pop();
      seen.insert(vertex);
      //cout<<"dist="<<dist<<", vertex="<<vertex<<endl;
      for (auto e:g[vertex]){
        string w=e.first;
        if(seen.find(w)==seen.end()){
          int distNew=dist+g[vertex][w];
          if(distNew<distance[w]){
            q.push(pair(distNew,w));
            distance[w]=distNew;
            parent[w]=vertex;
          }
        }
      }
    }
    tuple<map<string,string>,map<string,int>> t{parent,distance};
    return t;
  }
  map<string,string> bfs(map<string,vector<string>>& g,const string& s){
    queue<string> q{};
    set<string> seen{};
    q.push(s);
    seen.insert(s);
    map<string,string> parent{{s,"None"}};

    while(q.size()>0){
      string vertex=q.front();
      q.pop();
      //cout<<vertex<<endl;
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
      //cout<<vertex<<endl;
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
  map<string,map<string,int>> g{
    {"A",{{"B",5},{"C",1}}},
        {"B",{{"A",5},{"C",2},{"D",1}}},
        {"C",{{"A",1},{"B",2},{"D",4},{"E",8}}},
        {"D",{{"B",1},{"C",4},{"E",3},{"F",6}}},
        {"E",{{"C",8},{"D",3}}},
        {"F",{{"D",6}}}
  };

  Trans b;
  auto t0=b.dijkastra(g,"A");
  auto parent=get<0>(t0);
  auto distance=get<1>(t0);
  for(auto e0:parent) cout<<e0.first<<","<<e0.second<<endl;
  for(auto e1:distance) cout<<e1.first<<","<<e1.second<<endl;;
  //map<string,string> parent=b.bfs(g,"A");
  //for(auto e: parent) cout<<e.first<<", "<<e.second<<endl;
  cout<<"================================"<<endl;
  //parent=b.bfs(g,"E");
  //for(auto e: parent) cout<<e.first<<", "<<e.second<<endl;
  //cout<<"================================"<<endl;
  //string v="B";
  //while (v!="None"){
  //  cout<<v<<endl;
  //  v=parent[v];
  //}
  //b.dfs(g,"A");
  cout<<"================================"<<endl;
  //b.dfs(g,"E");
  cout<<"================================"<<endl;
  return 0;
}
