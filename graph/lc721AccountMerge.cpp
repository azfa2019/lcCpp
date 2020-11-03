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
    vector<vector<string>> accountMerge(vector<vector<string>>&accounts){
      unordered_map<string,int>ids;
      unordered_map<int,string>names;
      vector<int>p(10000);
      iota(begin(p),end(p),0);
      function<int(int)> Find=[&](int x){
        if(x!=p[x]) p[x]=Find(p[x]);
        return p[x];
      };
      function<int(string)>getIdByEmail=[&](string email){
        auto it=ids.find(email);
        if(it==ids.end()){
          int id=ids.size();
          return ids[email]=id;
        }
        return it->second;
      };
      for(const auto& account:accounts){
        int u=Find(getIdByEmail(account[1]));
        for(int i=2;i<account.size();i++) p[Find(getIdByEmail(account[i]))]=u;
        names[u]=account[0];
      }
      unordered_map<int,set<string>>merged;
      for(auto account:accounts){
        for(int i=1;i<account.size();i++){
          int id=Find(getIdByEmail(account[i]));
          merged[id].insert(account[i]);
        }
      }
      vector<vector<string>>ans;
      for(auto e:merged){
        ans.push_back({names[e.first]});
        ans.back().insert(ans.back().end(),e.second.begin(),e.second.end());
      }
      return ans;
    }
};
int main(){
  Solution0 s0;
  vector<vector<string>> accounts{{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
  auto ans0=s0.accountMerge(accounts);
  for(auto it:ans0){
    showVector(it);
  }
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

