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
class Solution {
 public:
  int score(const string& s){
    int k=0;
    int n=s.size();
    int ans=0;
    for (int i=0;i<n-1;++i){
      k+=s[i]=='('?1:-1;
      if (s[i]=='(' & s[i+1]==')') ans+=1<<k;
    }
    return ans;
  }
};
int main(){
  Solution s0;
  vector<string> v{"()","((()))","()(()())"};
  for(auto it=begin(v);it!=end(v);++it){
    int ans=s0.score(*it);
    cout<<ans<<endl;
  }
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

