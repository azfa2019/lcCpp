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
    string smallString(string&s,vector<vector<int>>&pairs){
      string tmp;
      unordered_set<int>seen;
      vector<vector<int>>g(s.length());
      vector<int>idx;
      for(const auto& e:pairs){
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
      }
      function<void(int)>dfs=[&](int cur){
        if(seen.count(cur)) return;
        seen.insert(cur);
        idx.push_back(cur);
        tmp+=s[cur];
        for(int i:g[cur]) dfs(i);
      };
      for(int i=0;i<s.length();i++){
        if(seen.count(i)) continue;
        idx.clear(),tmp.clear();
        dfs(i);
        sort(begin(idx),end(idx));
        sort(begin(tmp),end(tmp));
        for(int k=0;k<idx.size();k++) s[idx[k]]=tmp[k];
      }
      return s;
    }
};
class Solution1{
  public:
    string smallString(string&s,vector<vector<int>>&pairs){
      int n=s.length();
      vector<int>p(n);
      iota(begin(p),end(p),0);
      function<int(int)>find=[&](int x){return x==p[x]?x:find(p[x]);};
      for(const auto& e:pairs) p[find(e[0])]=find(e[1]);
      vector<string>ss(n);
      vector<vector<int>>idx(n);
      for(int i=0;i<n;i++){
        int id=find(i);
        ss[id].push_back(s[i]);
        idx[id].push_back(i);
      }
      for(int i=0;i<n;i++){
        sort(begin(ss[i]),end(ss[i]));
        for(int k=0;k<ss[i].size();k++)
          s[idx[i][k]]=ss[i][k];
      }
      return s;
    }
};
int main(){
  Solution0 s0;
  string s="dcab";
  vector<vector<int>>pairs={{0,3},{1,2}};
  string ans0=s0.smallString(s,pairs);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  string s01="dcab";
  vector<vector<int>>pairs1={{0,3},{1,2}};
  Solution1 s1;
  string ans1=s1.smallString(s01,pairs1);
  cout<<ans1<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

