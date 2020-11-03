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
    pair<map<string,int>,map<string,string>> dijkstra(map<string,map<string,int>> g,string s){
      auto compare=[](pair<string,int>a,pair<string,int>b){return a.second>b.second;};
      priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(compare)>q(compare);
      q.push(pair(s,0));
      map<string,int> distance;
      initDist(g,s,distance);
      map<string,bool>seen;
      for(auto e:g) seen[e.first]=false;
      seen[s]=true;
      map<string,string>parent;
      parent[s]="none";
      while(q.size()>0){
        string v=q.top().first;
        int dist=q.top().second;
        q.pop();
        seen[v]=true;
        for(auto e:g[v]){
          string w=e.first;
          if(!seen[w]){
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
  private:
    void initDist(map<string,map<string,int>>g,string s,map<string,int>&distance){
      for(auto e:g) distance[e.first]=INT_MAX;
      distance[s]=0;
    }
};
int main(){
  Solution0 s0;
  map<string,map<string,int>> g{
    {"A",{{"B",5},{"C",1}}},
    {"B",{{"A",5},{"C",2},{"D",1}}},
    {"C",{{"A",1},{"B",2},{"D",4},{"E",8}}},
    {"D",{{"B",1},{"C",4},{"E",3},{"F",6}}},
    {"E",{{"C",8},{"D",3}}},
    {"F",{{"D",6}}}
  };

  auto p=s0.dijkstra(g,"A");
  for(auto e:p.first) cout<<e.first<<":"<<e.second<<endl;
  //cout<<p.first["A"]<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

