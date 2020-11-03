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
    bool equality(vector<string>&equation){
      iota(begin(parent),end(parent),0);
      for(const auto& eq:equation)
        if(eq[1]=='=')
          parent[find(eq[0])]=find(eq[3]);
      for(const auto& eq:equation)
        if(eq[1]=='!'&&find(eq[0])==find(eq[3])) return false;
      return true;
    }
  private:
    array<int,128>parent;
    int find(int x){
      if(x!=parent[x]){
        parent[x]=find(parent[x]);
      }
      return parent[x];
    }
};
int main(){
  Solution0 s0;
  vector<string>equation1{"c==c","b==d","x!=z"};
  vector<string>equation{"a==b","b!=c","c==a"};
  auto ans0=s0.equality(equation);
  cout<<ans0<<endl;
  auto ans00=s0.equality(equation1);
  cout<<ans00<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

