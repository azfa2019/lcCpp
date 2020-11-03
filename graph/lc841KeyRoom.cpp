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
    bool visitRooms(vector<vector<int>>&rooms){
      unordered_set<int>visited;
      dfs(rooms,0,visited);
      return visited.size()==rooms.size();
    }
  private:
    void dfs(const vector<vector<int>>&rooms,int cur,unordered_set<int>&visited){
      if(visited.count(cur)) return;
      visited.insert(cur);
      for(int i:rooms[cur]) dfs(rooms,i,visited);
    }
};
int main(){
  Solution0 s0;
  vector<vector<int>>rooms{{1,3},{3,0,1},{2},{0}};
  bool ans0=s0.visitRooms(rooms);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

