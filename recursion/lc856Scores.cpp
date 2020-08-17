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
  int score(const string& s,int l, int r){
    if(l+1==r) return 1;
    int b=0;
    for(int i=l;i<r;i++){
      if(s[i]=='(') b++;
      if(s[i]==')') b--;
      if(b==0) return score(s,l,i)+score(s,i+1,r);
    }
    return 2*score(s,l+1,r-1);
  }
  int score2(const string& s){
    int d=0,ans=0;
    for(int i=0;i<s.length();i++){
      d+=(s[i]=='('?1:-1);
      if(i>0&&s[i]==')'&&s[i-1]=='(') ans+=1<<d;
    }
    return ans;
  }
};
int main(){
  Solution s0;
  vector<string> v{"()","(())","()()","(()(()))"};
  for(auto it=begin(v);it!=end(v);++it){
    int l=0;
    int r=(*it).size();
    cout<<"l="<<l<<",r="<<r<<endl;
    //cout<<*it<<endl;
    //int ans=s0.score(*it,l,r-1);
    int ans=s0.score2(*it);
    cout<<ans<<endl;
  }
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

