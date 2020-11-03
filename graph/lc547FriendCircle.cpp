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
    int findNumFriendCircle(vector<vector<int>>&M){
      int ans=0,n=M.size();
      for(int i=0;i<n;i++){
        if(!M[i][i]) continue;
        ans++;
        dfs(M,i,n);
      }
      return ans;
    }
  private:
    void dfs(vector<vector<int>>&M,int cur,int n){
      for(int i=0;i<n;i++){
        if(!M[cur][i]) continue;
        M[cur][i]=M[i][cur]=0;
        dfs(M,i,n);
      }
    }
};
class UnionFindSet{
  public:
    UnionFindSet(int n){
      parents=vector<int>(n+1,0);
      ranks=vector<int>(n+1,0);
      for(int i=0;i<parents.size();i++) parents[i]=i;
    }
    bool Union(int u,int v){
      int pu=Find(u),pv=Find(v);
      if(pu==pv) return false;
      if(ranks[pu]<ranks[pv]) parents[pu]=pv;
      else if(ranks[pu]>ranks[pv]) parents[pv]=pu;
      else{
        parents[pv]=pu;
        ranks[pu]++;
      }
      return true;
    }
    int Find(int id){
      if(id!=parents[id]) parents[id]=Find(parents[id]);
      return parents[id];
    }
  private:
    vector<int>parents;
    vector<int>ranks;
};
class Solution1{
  public:
    int findNumFriendCircle(vector<vector<int>>& M){
      int n=M.size();
      UnionFindSet s(n);
      for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
          if(M[i][j]==1) s.Union(i,j);
      unordered_set<int>circles;
      for(int i=0;i<n;i++)
        circles.insert(s.Find(i));
      return(circles.size());
    }
};
int main(){
  Solution0 s0;
  vector<vector<int>> M{{1,1,0},{1,1,0},{0,0,1}};
  int ans0=s0.findNumFriendCircle(M);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  vector<vector<int>> M0{{1,1,0},{1,1,0},{0,0,1}};
  Solution1 s1;
  auto ans1=s1.findNumFriendCircle(M0);
  cout<<ans1<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

