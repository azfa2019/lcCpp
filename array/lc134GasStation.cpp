#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
using namespace std;
  template<typename T>
void showVector(vector<T> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << *it<<" "; //'\t' ; 
    cout << '\n'; 
} 
class solution{
  public:
    int gasStation(vector<int> gas,vector<int> cost){
      int start=0,cur=0,total=0;
      for(int i=0;i<cost.size();i++){
        cur+=gas[i]-cost[i];
        if (cur<0){
          start=i+1;
          cur=0;
        }
        total+=gas[i]-cost[i];
      } 
      return total>=0?start:-1;
    }
};
int main(){
  solution s0;
  vector<pair<vector<int>,vector<int>>> gasCost{{{1,2,3,4,5},{3,4,5,1,2}},{{2,3,4},{3,4,3}}}; 
  for(auto e:gasCost) cout<<s0.gasStation(e.first,e.second)<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

