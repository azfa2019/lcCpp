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
    int busRoutes(int s,int t,vector<vector<int>>&routes){
      if(s==t) return 0;
      unordered_map<int,vector<int>>stop2bus;
      for(int i=0;i<routes.size();i++)
        for(auto stop:routes[i])
          stop2bus[stop].push_back(i);
      queue<int>q;
      q.push(s);
      int step=-1;
      unordered_set<int>visitedBus;
      unordered_set<int>visitedStop;
      visitedStop.insert(s);
      while(!q.empty()){
        int size=q.size();
        step++;
        while(size--){
          int curStop=q.front();q.pop();
          for(auto bus:stop2bus[curStop]){
            if(visitedBus.count(bus)) continue;
            visitedBus.insert(bus);
            for(auto nextStop:routes[bus]){
              if(visitedStop.count(nextStop)) continue;
              visitedStop.insert(nextStop);
              if(nextStop==t) return step+1;
              q.push(nextStop);
            }
          }
        }
      }
      return -1;
    }
};
int main(){
  Solution0 s0;
  int s=1,t=6;
  vector<vector<int>>routes{{1,2,7},{3,6,7}};
  auto ans0=s0.busRoutes(s,t,routes);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

