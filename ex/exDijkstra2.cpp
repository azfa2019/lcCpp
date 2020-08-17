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
    map<string,int> init_distance(map<string,map<string,int>>& g,string s){
      map<string,int> distance;
      for (auto e:g) distance.insert(pair(e.first,1000));
      distance[s]=0;
      return distance;
    }
    pair<map<string,int>,map<string,string>> dijkstra( map<string,map<string,int>>& g, string s){
      auto compare=[](pair<string,int> a, pair<string,int> b) {return a.second>b.second;};
      priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(compare)> q(compare);
      q.push(pair(s,0));
      map<string,bool> seen;
      for(auto e:g) seen[e.first]=false;
      map<string,string> parent{{s,"none"}};
      map<string,int> distance=init_distance(g,s);

      while(q.size()>0){
        string v=q.top().first;
        int dist=q.top().second;
        q.pop();
        seen[v]=true;

        for(auto e:g[v]){
          string w=e.first;
          if (!seen[w]){
            if(dist+g[v][w]<distance[w]){
              distance[w]=dist+g[v][w];
              q.push(pair(w,distance[w]));
              parent[w]=v;
            }
          }
        }
      }
      return pair(distance,parent);
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
  Solution s0;
  auto p0=s0.dijkstra(g,"A");
  cout<<"distance:"<<endl;
  for(auto e:p0.first) cout<<e.first<<", "<<e.second<<endl;
  cout<<"parent:"<<endl;
  for(auto e:p0.second) cout<<e.first<<", "<<e.second<<endl;
  //auto distance=s0.init_distance(g,"A");
  //for(auto e:distance) 
  //cout<<"vertex: "<<e.first<<", "<<e.second<<"; ";
  //cout<<endl;
  //for(auto e:g) {
  //cout<<"vertex: "<<e.first<<", ";
  //for(auto e1:e.second){cout<<e1.first<<":"<<e1.second<<", ";}
  //cout<<endl;
  //}
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

