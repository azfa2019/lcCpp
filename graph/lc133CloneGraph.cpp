#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<map>
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
struct Node{
  public:
    int val;
    vector<Node*> neighbors;
    Node():val(0),neighbors(vector<Node*>{}){};
    Node(int val):val(val),neighbors(vector<Node*>{}){};
    Node(int val,vector<Node*> neighbors):val(val),neighbors(neighbors){};
};
class Solution0{
  public:
    Node *cloneGraph(Node *node){
      if(!node) return nullptr;
      unordered_map<Node*,Node*> m;
      unordered_set<Node*> collected;
      queue<Node*> q;
      q.push(node);
      while(!q.empty()){
        Node *cur=q.front();q.pop();
        if(collected.count(cur)) continue;
        collected.insert(cur);
        if(!m.count(cur)) m[cur]= new Node(cur->val);
        for(Node *nb:cur->neighbors){
          if(!m.count(nb)) m[nb]=new Node(nb->val);
          m[cur]->neighbors.push_back(m[nb]);
          q.push(nb);
        }
      }
      return m[node];
    }
};
int main(){
  Solution0 s0;
  Node n1(1),n0(0),n2(2);
  n1.neighbors={&n0,&n2};
  n0.neighbors={&n1,&n2};
  n2.neighbors={&n0,&n1};
  auto ans0=s0.cloneGraph(&n0);
  cout<<ans0->val<<endl;
  for (auto e:ans0->neighbors) cout<<e->val<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

