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
    int mutation(const string& start,const string& end,vector<string>&bank){
      unordered_set<string>visited;
      queue<string>q;
      q.push(start);
      visited.insert(start);
      int mutation=0;
      while(!q.empty()){
        int size=q.size();
        while(size--){
          string cur=q.front();q.pop();
          if(cur==end) return mutation;
          for(const string& gene:bank){
            if(visited.count(gene)||!validMutation(cur,gene)) continue;
            visited.insert(gene);
            q.push(gene);
          }
        }
        mutation++;
      }
      return -1;
    }
  private:
    bool validMutation(const string& s1,const string& s2){
      int count=0;
      for(int i=0;i<s1.length();i++)
        if(s1[i]!=s2[i]&&count++) return false;
      return true;
    }
};
int main(){
  Solution0 s0;
  string start= "AAAAACCC";
  string end=   "AACCCCCC";
  vector<string> bank {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
  auto ans0=s0.mutation(start,end,bank);
  cout<<ans0<<endl;

  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

