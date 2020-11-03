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
class UnionFindSet{
  public:
    UnionFindSet(int n){
      ranks=vector<int>(n+1,0);
      parents=vector<int>(n+1,0);
      for(int i=0;i<parents.size();i++) parents[i]=i;
    }
    bool Union(int u,int v){
      int pu=Find(u),pv=Find(v);
      if(pu==pv) return false;
      if(ranks[pu]<ranks[pv]) parents[pu]=pv;
      else if (ranks[pu]>ranks[pv]) parents[pv]=pu;
      else{
        parents[pu]=pv;
        ranks[pv]++;
      }
      return true;
    }
    int Find(int id){
      if(parents[id]!=id) parents[id]=Find(parents[id]);
      return parents[id];
    }
  private:
    vector<int>ranks;
    vector<int>parents;
};
class Solution0{
  public:
    vector<int>findRedunConn(vector<vector<int>>&edges){
      UnionFindSet s(edges.size());
      for(auto edge:edges) if(!s.Union(edge[0],edge[1])) return edge;
      return {};
    }
};
int main(){
  Solution0 s0;
  vector<vector<int>> edges{{1,2},{2,3},{3,4},{1,4},{1,5}};
  auto ans0=s0.findRedunConn(edges);
  showVector(ans0);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

