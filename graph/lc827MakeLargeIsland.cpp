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
    int largestIsland(vector<vector<int>>&grid){
      m=grid.size(),n=grid[0].size(),color=1;
      int ans=0;
      unordered_map<int,int>areas;
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j]==1){
            color++;
            areas[color]=getArea(i,j,grid);
            ans=max(ans,areas[color]);
          }
        }
      }
      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j]==0){
            int area=1;
            for(int color:set<int>{getColor(i-1,j,grid),getColor(i+1,j,grid),getColor(i,j-1,grid),getColor(i,j+1,grid)}){
              area+=areas[color];
            }
              ans=max(ans,area);
          }
        }
      }
      return ans;
    }
  private:
    int m,n,color;
    int getColor(int r,int c,vector<vector<int>>&grid){
      return (r<0||r>=m||c<0||c>=n)?0:grid[r][c];
    }
    int getArea(int r,int c,vector<vector<int>>&grid){
      //cout<<"in getArea"<<endl;
      //cout<<"r="<<r<<", m="<<m<<", c="<<c<<", grid[r][c]="<<grid[r][c]<<endl;
      if(r<0||r>=m||c<0||c>=n||grid[r][c]!=1) return 0;
      grid[r][c]=color;
      int p=1 +getArea(r-1,c,grid) +getArea(r+1,c,grid) +getArea(r,c-1,grid) +getArea(r,c+1,grid);
      //cout<<"p="<<p<<endl;
      return p;
    }
};
int main(){
  Solution0 s0;
  vector<vector<int>>grid0{{1,0},{0,1}};
  int ans0=s0.largestIsland(grid0);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  vector<vector<int>>grid1{{1,1},{1,0}};
  int ans1=s0.largestIsland(grid1);
  cout<<ans1<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

