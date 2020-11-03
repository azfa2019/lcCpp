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
    int numIslands(vector<vector<char>>&grid){
      if(grid.empty()) return 0;
      int m=grid.size(),n=grid[0].size(),ans=0;
      for(int x=0;x<m;++x){
        for(int y=0;y<n;++y){
          ans+=grid[x][y]-'0';
          dfs(grid,x,y,m,n);
        }
      }
      return ans;
    }
  private:
    void dfs(vector<vector<char>>&grid,int x,int y,int m,int n){
      if(x<0||y<0||x>=m||y>=n||grid[x][y]=='0') return;
      grid[x][y]='0';
      dfs(grid,x+1,y,m,n);
      dfs(grid,x-1,y,m,n);
      dfs(grid,x,y+1,m,n);
      dfs(grid,x,y-1,m,n);
    }
};
int main(){
  Solution0 s0;
  vector<vector<char>> 
    grid{{'1','1','0','0','0'},
      {'1','1','0','0','0'},
      {'0','0','1','0','0'},
      {'0','0','0','1','1'}
  };
  int ans0=s0.numIslands(grid);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

