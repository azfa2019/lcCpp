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
    int maxAreaIsland(vector<vector<int>>&grid){
      int m=grid.size(),n=grid[0].size(),ans=0;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          ans=max(ans,area(i,j,m,n,grid));
        }
      }
      return ans;
    }
  private:
    int area(int i,int j,int m,int n,vector<vector<int>>&grid){
      if(i<0||j<0||i>=m||j>=n||grid[i][j]==0) return 0;
      grid[i][j]=0;
      return 1+
        area(i-1,j,m,n,grid)+
        area(i+1,j,m,n,grid)+
        area(i,j-1,m,n,grid)+
        area(i,j+1,m,n,grid);
    }
};
int main(){
  Solution0 s0;
  vector<vector<int>>grid{{0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}};
  int ans0=s0.maxAreaIsland(grid);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

