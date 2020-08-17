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
  int minFuelStops(int target,int startFuel,vector<vector<int>>& stations){
    priority_queue<int> q;
    int cur=startFuel;
    int stops=0;
    int i=0;
    while (true){
      if(cur>=target) return stops;
      while(cur>=stations[i][0]&&i<stations.size()-1){
        q.push(stations[i][1]);
        i++;
        //cout<<"cur="<<cur<<", q.top="<<q.top()<<endl;
      }

      if (q.empty()) break;
      cur+=q.top();
      q.pop();
      ++stops;
    }
    return -1;
  }
};
int main(){
  Solution s;
  vector<vector<int>> stations{{10,60},{20,30},{30,30},{60,40}};
  int res=s.minFuelStops(100,10,stations);
  cout<<res<<endl;

  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

