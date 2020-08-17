#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
  bool b=10;
  if(b){
    cout<<"hi"<<endl;
  }
  cout<<"================================"<<endl;
  set<pair<int,int>> s0{{1,2},{3,4}};
  pair<int,int>p{1,2};
  
  auto p2=s0.equal_range(p);
  cout<<p2.first->first<<endl;
  cout<<p2.first->second<<endl;
  s0.erase(p2.first);
  cout<<s0.rbegin()->first<<endl;
  cout<<s0.rbegin()->second<<endl;

  cout<<"================================"<<endl;
  multiset<int> ms0{1,5,3,9,7};
  cout<<*ms0.rbegin()<<endl;
  ms0.erase(9);
  cout<<*ms0.rbegin()<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

