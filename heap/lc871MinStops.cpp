#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

class Solution{
  public:
    int minRefuelStops(int startFuel,int target,vector<vector<int>> stations){
      int n=stations.size();
      vector<int> dp(n+1,startFuel);
      for (int i=0;i<n;i++){
        for (int j=i+1;j>=1;j--)
          if(dp[j-1]>=stations[i][0]){
            dp[j]=max(dp[j],dp[j-1]+stations[i][1]);
          }
      }
      for (int i=0;i<dp.size();i++){
        if (dp[i]>=target) return i;
      }
      return -1;
    }
};
class Solution0{
  public: 
    int minRefuelStops(int startFuel,int target,vector<vector<int>> stations){
      int n=stations.size();
      vector<int> dp(n+1,startFuel);
      for(int i=0;i<n;i++){
        for(int j=i+1;j>=1;j--){
          if(dp[j-1]>=stations[i][0]) dp[j]=max(dp[j],dp[j-1]+stations[i][1]);
        }
      }
      for(int i=0;i<dp.size();i++){
        if (dp[i]>=target) return i;
      }
      return -1;
    }
    int minRefuelStops2(int startFuel,int target,vector<vector<int>> stations){
      int cur=startFuel;int i=0;int stops=0;
      priority_queue <int> q;
      while(true){
        if(cur>=target) return stops;
        while(i<stations.size() && cur>=stations[i][0]) q.push(stations[i++][1]);
        if(q.empty()) break;
        cur+=q.top();q.pop();stops++;
      }
      return -1;
    }
};
int main(){
  Solution0 s0;
  vector<vector<int>> stations{{10,60},{20,30},{30,30},{60,40}};
  int ans=s0.minRefuelStops2(10,100,stations);
  //int ans=s0.minRefuelStops2(1,100,{{10,100}});
  cout<<ans<<endl;

  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

