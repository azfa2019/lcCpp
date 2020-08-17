#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

class solution{
  public:
    typedef pair<string,int> node;
    vector<string> topKFrequent(vector<string>& words,int k){
      unordered_map <string,int> count;
      vector<string> res;
      for(auto e:words){
        ++count[e];
      }
      auto comp=[](const node& w1,const node& w2){
        if(w1.second==w2.second) return w1.first>w2.first;
        return w1.second > w2.second;
      };
      priority_queue<node,vector<node>,decltype(comp)> pq0(comp);
      for (auto e:count){
        pq0.push(make_pair(e.first,e.second));
        if(pq0.size()>k) pq0.pop();
      }
      //cout<<"bool="<<("i"<"love")<<endl;
      while(!pq0.empty()){
        res.push_back(pq0.top().first);
        //cout<<"pq0.top()="<<pq0.top().first<<endl;
        pq0.pop();
      }
      return res;
    }
};
class solution0{
  public:
    vector<string> topKFrequent(vector<string> words,int k){
      typedef pair<string,int> Node;
      typedef function<bool(const Node&,const Node&)> Compare;

      unordered_map<string,int> count;
      for(const auto& word:words) ++count[word];
      Compare comparator=[](const Node& a,const Node& b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
      };
      priority_queue <Node,vector<Node>,Compare> q(comparator);
      for(auto kv:count){
        q.push(kv);
        if(q.size()>k) q.pop();
      }
      vector<string> ans;
      while(q.size()>0){
        ans.push_back(q.top().first);
        q.pop();
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};
int main(){
  vector<string> words{"a","i","love","leetcode","i","love","coding","a"};
  solution0 s0;
  auto res=s0.topKFrequent(words,3);
  for (auto e:res){
    cout<<e<<" ";
  }
  cout<<endl;

  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

