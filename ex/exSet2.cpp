#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<map>
#include<stack>
#include<queue>
using namespace std;

int main(){
  multiset<pair<int,int>> ms{{2,3},{4,5}};
  cout<<"================================"<<endl;
  unordered_map<int,int>m;
  auto p1=m.emplace(1,10).first;
  cout<<p1->first<<endl;
  cout<<p1->second<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

