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
    bool bipartition(int n,vector<vector<int>>&dislike){
      colors=vector<int>(n,0);
      g=vector<vector<int>>(n);
      for(const auto&p:dislike){
        g[p[0]-1].push_back(p[1]-1);
        g[p[1]-1].push_back(p[0]-1);
      }
      for(int i=0;i<n;i++)
        if(colors[i]==0&&!dfs(i,1)) return false;
      return true;
    }
  private:
    vector<int>colors;
    vector<vector<int>>g;
    bool dfs(int cur,int color){
      colors[cur]=color;
      for(int next:g[cur]){
        if(colors[next]==color) return false;
        if(colors[next]==0&&!dfs(next,-color)) return false;
      }
      return true;
    }
};
class Solution1{
  public:
    bool bipartition(int n,vector<vector<int>>&dislike){
      vector<vector<int>>g(n);
      vector<int>colors(n);
      for(const auto&p:dislike){
        g[p[0]-1].push_back(p[1]-1);
        g[p[1]-1].push_back(p[0]-1);
      }
      queue<int>q;
      for(int i=0;i<n;i++){
        if(colors[i]!=0) continue;
        q.push(i);
        colors[i]=1;
        while(!q.empty()){
          int cur=q.front();q.pop();
          for(int next:g[cur]){
            if(colors[next]==colors[cur]) return false;
            if(colors[next]==-colors[cur]) continue;
            colors[next]=-colors[cur];
            q.push(next);
          }
        }
      }
      return true;
    }
};
int main(){
  Solution0 s0;
  int n00=4;
  vector<vector<int>> dislike00{{1,2},{1,3},{2,4}};
  auto ans00=s0.bipartition(n00,dislike00);
  cout<<ans00<<endl;
  cout<<"================================"<<endl;
  int n01=5;
  vector<vector<int>> dislike01{{1,2},{2,3},{3,4},{4,5},{1,5}};
  auto ans01=s0.bipartition(n01,dislike01);
  cout<<ans01<<endl;
  cout<<"================================"<<endl;
  Solution1 s1;
  auto ans10=s1.bipartition(n00,dislike00);
  cout<<ans10<<endl;
  cout<<"================================"<<endl;
  auto ans11=s1.bipartition(n01,dislike01);
  cout<<ans11<<endl;
  cout<<"================================"<<endl;
  return 0;
}

