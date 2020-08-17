#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
class solution{
 public:
  vector <pair<int,int>> getSkyline(vector<vector<int>>& buildings){
    vector <pair<int,int>> e0;
    for (const auto& b: buildings){
      e0.emplace_back(b[0],b[2]);
      e0.emplace_back(b[1],-b[2]);
    }

    sort(e0.begin(),e0.end(),[](pair<int,int>& p1,pair<int,int>& p2){
      if(p1.first==p2.first) return p1.second>p2.second;
      return p1.first<p2.first;
    });
    //for (auto it=e0.begin();it!=e0.end();++it){
    //  cout<<it->first<<","<<it->second<<endl;
    //}
    multiset<int> heights{0};
    vector<pair<int,int>> ds;
    for (const auto& e: e0){
      bool entering=e.second;
      int h=abs(e.second);
      if(e.second>0){
        if(h>*heights.rbegin()) ds.emplace_back(e.first,h);
        heights.insert(h);
        //cout<<"entering, x= "<<e.first<<", max height= "<<*heights.rbegin()<<endl;
      }else{
        heights.erase(heights.equal_range(h).first);
        if(h>*heights.rbegin()) ds.emplace_back(e.first,*heights.rbegin());
        //cout<<"leaving, x= "<<e.first<<", max height= "<<*heights.rbegin()<<endl;
      }
    }
    return ds;
  }
};

class solution0{
  public:
    multiset <int>hs;
    int maxHeight(){
      if (hs.empty()) return 0;
      return *hs.rbegin();
    }
    vector<pair<int,int>> getSkyline(vector<vector<int>>& buildings){
      typedef pair<int,int> Event;
      vector<Event> es;
      for(const auto& e:buildings){
        es.emplace_back(e[0],e[2]);
        es.emplace_back(e[1],-e[2]);
      }
      sort(es.begin(),es.end(),[](const auto& e1,const auto& e2){
          if(e1.first==e2.first) return e1.second>e2.second;
          else return e1.first<e2.first;
          });
      vector<pair<int,int>> ans;
      for(auto const& e:es){
        int h= abs(e.second);
        int x=e.first;
        bool entering=(e.second>0);
        if(entering){
          if(h>this->maxHeight()) ans.emplace_back(x,h);
          hs.insert(h);
        }else{
          hs.erase(hs.equal_range(h).first);
          if(h>this->maxHeight()) ans.emplace_back(x,this->maxHeight());
        }
      }
      return ans;
    }
};
int main(){
  vector<pair<int,int>> e0;
  vector<vector<int>> buildings{{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
  solution0 s0;
  auto e1=s0.getSkyline(buildings);
  cout<<e1.size()<<endl;
  for (auto it=e1.begin();it!=e1.end();++it){
    cout<<"["<<it->first<<","<<it->second<<"] ";
  };
  cout<<endl;

  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

