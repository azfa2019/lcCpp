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
class Solution{
 public:
   vector<string> letterCasePermu(string s){
     vector<string> ans;
     dfs(s,0,ans);
     return ans;
   }
   void dfs(string& s,int i,vector<string>& ans){
     if(i==s.length()){
       ans.push_back(s);
       return;
     }
     dfs(s,i+1,ans);
     if (isdigit(s[i])) return;
     s[i]^=(1<<5);
     dfs(s,i+1,ans);
     s[i]^=(1<<5);
   }
};
int main(){
  vector<string> S{"a1b2","3z4","12345"};
  Solution s0;
  for(auto e:S){
    vector<string> ans=s0.letterCasePermu(e);
    for(auto e0:ans) {
    cout<<e0<<" ";
    }
    cout<<endl;
  }
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

