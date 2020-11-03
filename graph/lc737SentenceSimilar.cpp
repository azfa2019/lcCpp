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
class UnionFindSet{
  public:
    UnionFindSet(int n){
      parent=vector<int>(n,0);
      rank=vector<int>(n,0);
      iota(begin(parent),end(parent),0);
    }
    bool Union(int x,int y){
      int px=Find(x),py=Find(y);
      if(px==py) return false;//union failed, no need to union
      if(rank[px]>rank[py]) parent[py]=px;
      else if(rank[px]<rank[py]) parent[px]=py;
      else{
        parent[px]=py;
        rank[py]++;
      }
      return true;
    }
    int Find(int x){
      if(x!=parent[x]) parent[x]=Find(parent[x]);
      return parent[x];
    }
  private:
    vector<int>parent;
    vector<int>rank;
};
class Solution0{
  public:
  bool findSentenceSimilar(vector<string>&word1,vector<string>&word2,vector<pair<string,string>>&pairs){
    if(word1.size()!=word2.size()) return false;
    UnionFindSet s(pairs.size()*2);
    unordered_map<string,int>ids;
    for(auto p:pairs){
      int x=s.Find(findId(p.first,ids,true));
      int y=s.Find(findId(p.second,ids,true));
      s.Union(x,y);
    }
    for(int i=0;i<word1.size();i++){
      if(word1[i]==word2[i]) continue;
      int x=findId(word1[i],ids,false);
      int y=findId(word2[i],ids,false);
      if(x<0||y<0) return false;
      if(s.Find(x)!=s.Find(y)) return false;
    }
    return true;
  }
  private:
  int findId(const string& word,unordered_map<string,int>&ids,bool create=false){
    auto it=ids.find(word);
    if(it==ids.end()){
      if(!create) return INT_MIN;
      int id=ids.size();
      return ids[word]=id;
    }
    return it->second;
  }
};
class Solution1{
  public:
    bool findSentenceSimilar(vector<string>&word1,vector<string>&word2,vector<pair<string,string>>&pairs){
      if(word1.size()!=word2.size()) return false;
      g.clear();
      for(auto pair:pairs){
        g[pair.first].insert(pair.second);
        g[pair.second].insert(pair.first);
      }
      unordered_set<string>visited;
      for(int i=0;i<word1.size();i++){
        visited.clear();
        if(!dfs(word1[i],word2[i],visited)) return false;
      }
      return true;
    }
  private:
    unordered_map<string,unordered_set<string>>g;
    bool dfs(const string&src,const string& dst,unordered_set<string>&visited){
      if(src==dst) return true;
      visited.insert(src);
      for(const string&next:g[src]){
        if(visited.count(next)) continue;
        if(dfs(next,dst,visited)) return true;
      }
      return false;
    }
};
class Solution2{
  public:
    bool findSentenceSimilar(vector<string>&word1,vector<string>&word2,vector<pair<string,string>>&pairs){
      if(word1.size()!=word2.size()) return false;
      g.clear();ids.clear();
      for(const auto& pair:pairs){
        g[pair.first].insert(pair.second);
        g[pair.second].insert(pair.first);
      }
      int id=0;
      for(const auto&pair:pairs){
        if(!ids.count(pair.first)) dfs(pair.first,++id);
        if(!ids.count(pair.second)) dfs(pair.second,++id);
      }
      for(int i=0;i<word1.size();i++){
        if(word1[i]==word2[i]) continue;
        if(!(ids.count(word1[i]))||!(ids.count(word2[i]))) return false;
        if(ids[word1[i]]!=ids[word2[i]]) return false;
      }
      return true;
    }
  private:
    unordered_map<string,unordered_set<string>>g;
    unordered_map<string,int>ids;
    bool dfs(const string&cur,int id){
      ids[cur]=id;
      for(const string& next:g[cur]){
        if(ids.count(next)) continue;
        if(dfs(next,id)) return true;
      }
      return false;
    }
};
int main(){
  Solution0 s0;
  vector<string>word1{"great","acting","skills"};
  vector<string>word2{"fine","drama","talent"};
  vector<pair<string,string>>pairs{{"great","good"},{"fine","good"},{"acting","drama"},{"skills","talent"}};
  auto ans0=s0.findSentenceSimilar(word1,word2,pairs);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  Solution1 s1;
  auto ans1=s1.findSentenceSimilar(word1,word2,pairs);
  cout<<ans1<<endl;
  cout<<"================================"<<endl;
  Solution2 s2;
  auto ans2=s2.findSentenceSimilar(word1,word2,pairs);
  cout<<ans2<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

