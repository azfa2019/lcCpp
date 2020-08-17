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
    pair<vector<int>,vector<int>> unweighted(map<int,vector<int>> g,int s){
      queue<int> q;
      vector<int> dist(g.size()+1,-1);
      vector<int> parent(g.size()+1,-1);
      q.push(s);
      dist[s]=0;
      while(q.size()>0){
        int v=q.front();
        q.pop();
        for(auto w: g[v]){
          if(dist[w]==-1){
            dist[w]=dist[v]+1;
            parent[w]=v;
            q.push(w);
          }
        }
      }
      return make_pair(dist,parent);
    }
};
int main(){
  map<int,vector<int>> g{{1,{2,4}},
    {2,{4,5}},
    {3,{1,6}},
    {4,{3,6,5,7,5}},
    {5,{7}},
    {6,{}},
    {7,{6}}};
  Solution s0;
  auto p1=s0.unweighted(g,3);
  //cout<<dist.size()<<endl;
  for(auto e:p1.first) cout<<e<<endl;
  cout<<"================================"<<endl;
  for(auto e:p1.second) cout<<e<<endl;
  
  cout<<"================================"<<endl;
  int i = 7;
  vector<int> parent=p1.second;
  while(parent[i]!=-1){
    cout<<parent[i]<<endl;
    i=parent[i];
  }
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

