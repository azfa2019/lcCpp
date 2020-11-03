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
    bool bipartite(vector<vector<int>>&g){
      int n=g.size();
      vector<int>colors(n,0);
      for(int i=0;i<n;i++)
        if(colors[i]==0&&!coloring(i,g,colors,1)) return false;
      return true;
    }
  private:
    bool coloring(int cur,vector<vector<int>>&g,vector<int>&colors,int color){
      colors[cur]=color;
      for(int next:g[cur]){
        if(colors[next]==colors[cur]) return false;
        if(colors[next]==0&&!coloring(next,g,colors,-color)) return false;
      }
      return true;
    }
};
int main(){
  Solution0 s0;
  vector<vector<int>>g00{{1,3},{0,2},{1,3},{0,2}};
  auto ans00=s0.bipartite(g00);
  cout<<ans00<<endl;
  cout<<"================================"<<endl;
  vector<vector<int>>g01{{1,2,3},{0,2},{0,1,3},{0,2}};
  auto ans01=s0.bipartite(g01);
  cout<<ans01<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

