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
    vector<vector<int>> pascal(int numRow){
      vector<vector<int>> ans{{1}};
      if(numRow==1) return ans;
      for(int i=1;i<numRow;i++){
        vector<int> cur;
        cur.push_back(1);
        for(int j=1;j<i;j++) cur.push_back(ans.back()[j-1]+ans.back()[j]);
        cur.push_back(1);
        ans.push_back(cur);
      }
      return ans;
    }
};
int main(){
  solution s0;
  auto ans=s0.pascal(5);
  for(auto e:ans) showVector(e);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

