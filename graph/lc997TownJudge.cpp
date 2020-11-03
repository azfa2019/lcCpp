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
    int findJudge(int n,vector<vector<int>>&trusts){
      vector<int>degrees(n+1);
      for(const auto& pair:trusts){
        --degrees[pair[0]];
        ++degrees[pair[1]];
      }
      for(int i=1;i<=n;i++)
        if(degrees[i]==n-1) return i;
      return -1;
    }
};
int main(){
  Solution0 s0;
  int n=4;
  vector<vector<int>>trust{{1,3},{1,4},{2,3},{2,4},{4,3}};
  auto ans0=s0.findJudge(n,trust);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

