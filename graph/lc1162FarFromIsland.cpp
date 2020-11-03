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
    int farFromIsland(vector<vector<int>>&grid){
      int m=grid.size(),n=grid[0].size();
      queue<int>q;
      for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
          if(grid[i][j]==1) q.push(i*100+j);
      int ans=-1,step=0;
      vector<int>dir{-1,0,1,0,-1};
      while(!q.empty()){
        int size=q.size();
        while(size--){
          int n0=q.front();q.pop();
          int r=n0/100,c=n0%100;
          if(grid[r][c]==2) ans=max(ans,step);
          for(int i=0;i<4;i++){
            int rn=r+dir[i],cn=c+dir[i+1];
            if(rn<0||rn>=m||cn<0||cn>=n||grid[rn][cn]!=0) continue;
            grid[rn][cn]=2;
            q.push(rn*100+cn);
          }
        }
        step++;
      }
      return ans;
    }
};
int main(){
  Solution0 s0;
  vector<vector<int>>grid{{1,0,1},{0,0,0},{1,0,1}};
  int ans0=s0.farFromIsland(grid);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

