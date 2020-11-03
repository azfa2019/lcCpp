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
    vector<double> calcEquation(vector<pair<string,string>>equation,vector<double>value,vector<pair<string,string>>query){
      unordered_map<string,unordered_map<string,double>>g;
      for(int i=0;i<equation.size();i++){
        string A=equation[i].first;
        string B=equation[i].second;
        double k=value[i];
        g[A][B]=k;
        g[B][A]=1./k;
      }
      vector<double>ans;
      for(const auto& pair:query){
        string X=pair.first,Y=pair.second;
        if(!g.count(X)||!g.count(Y)) {
          ans.push_back(-1.);
          continue;
        }
        unordered_set<string>visited;
        ans.push_back(divide(X,Y,g,visited));
      }
      return ans;
    }
  private:
    double divide(string A,string B,unordered_map<string,unordered_map<string,double>>g,unordered_set<string>&visited){
      if(A==B) return 1.;
      visited.insert(A);
      for(const auto&pair:g[A]){
        string C=pair.first;
        if(visited.count(C)) continue;
        double d=divide(C,B,g,visited);
        if(d>0) return d*g[A][C];
      }
      return -1.;
    }
};
class Solution1{
  public:
    vector<double>calcEquation(vector<pair<string,string>>equation,vector<double>value,vector<pair<string,string>>query){
      unordered_map<string,pair<string,double>>parent;
      for(int i=0;i<equation.size();i++){
        string A=equation[i].first;
        string B=equation[i].second;
        double k=value[i];
        if(!parent.count(A)&&!parent.count(B)){
          parent[A]={B,k};
          parent[B]={B,1.};
        }else if(!parent.count(A)){
          parent[A]={B,k};
        }else if(!parent.count(B)){
          parent[B]={A,1./k};
        }else{
          auto rA=find(A,parent);
          auto rB=find(B,parent);
        }
      }
      vector<double>ans;
      for(const auto&p:query){
        string x=p.first,y=p.second;
        if(!parent.count(x)||!parent.count(y)) {
          ans.push_back(-1.);
          continue;
        }
        auto rx=find(x,parent);
        auto ry=find(y,parent);
        if(rx.first!=ry.first) ans.push_back(-1.);
        else ans.push_back(rx.second/ry.second);
      }
      return ans;
    }
  private:
    pair<string,double>find(string C,unordered_map<string,pair<string,double>>parent){
      if(C!=parent[C].first){
        auto p=find(parent[C].first,parent);
        parent[C].first=p.first;
        parent[C].second*=p.second;
      }
      return parent[C];
    }
};
int main(){
  Solution0 s0;
  vector<pair<string,string>>equation{{"a","b"},{"b","c"}};
  vector<double>value{2.0,3.0};
  vector<pair<string,string>>query{{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
  vector<double> ans0=s0.calcEquation(equation,value,query);
  showVector(ans0);
  cout<<"================================"<<endl;
  Solution1 s1;
  auto ans1=s1.calcEquation(equation,value,query);
  showVector(ans1);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

