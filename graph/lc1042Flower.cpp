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
    vector<int>gardenFlower(int n,vector<vector<int>>&path){
      vector<vector<int>>g(n);
      for(auto p:path) {
        g[p[0]-1].push_back(p[1]-1);
        g[p[1]-1].push_back(p[0]-1);
      }
      vector<int>ans(n,0);
      for(int i=0;i<n;i++){
        int mask=0;
        for(auto j:g[i]) mask|=(1<<ans[j]);
        for(int c=1;c<=4&&ans[i]==0;c++)
          if(!(mask&(1<<c))) ans[i]=c;
      }
      return ans;
    }
};
class Solution1{
  public:
    vector<int>gardenFlower(int n,vector<vector<int>>&path){
      vector<vector<int>>g(n);
      for(auto p:path){
        g[p[0]-1].push_back(p[1]-1);
        g[p[1]-1].push_back(p[0]-1);
      }
      vector<int>ans(n,0);
      for(int i=0;i<n;i++){
        vector<int>colors(5,0);
        for(int j:g[i]) colors[ans[j]]=1;
        for(int c=1;c<=4;c++)
          if(colors[c]==0){
            ans[i]=c;
            break;
          }
      }
      return ans;
    }
};
int main(){
  Solution0 s0;
  vector<vector<int>>path{{1,2},{2,3},{3,4},{4,1},{1,3},{2,4}};
  //vector<vector<int>>path{{1,2},{3,4}};
  int n=4;
  auto ans0=s0.gardenFlower(n,path);
  showVector(ans0);
  cout<<"================================"<<endl;
  Solution1 s1;
  auto ans1=s1.gardenFlower(n,path);
  showVector(ans1);
  //int mask=0;
  //int i1=1<<1;
  //int i2=1<<2;
  //mask|=i1;
  //mask|=i2;
  //cout<<mask<<endl;
  //for(int i=0;i<=4;i++)
  //cout<<(mask&(1<<i))<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

