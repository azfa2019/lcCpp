#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;

int main(){
  set<int> s{5,3,16,10,10};
  for(auto it=s.begin();it!=s.end();++it){
    cout<<*it<<endl;
  }
  cout<<"================================"<<endl;
  auto it2=s.find(3);
  cout<<*(it2)<<endl;
  cout<<"================================"<<endl;
  typedef double wages;
  wages w1=2.2;
  cout<<w1<<endl;
  cout<<"================================"<<endl;
  using dl=double;
  dl w2=3.3;
  cout<<w2<<endl;
  cout<<"================================"<<endl;
  set<int,greater<int>> s2{7,2,18,11};
  cout<<*s2.begin()<<endl;
  cout<<*s2.end()<<endl;
  cout<<"================================"<<endl;
  for(auto it=s2.begin();it!=s2.end();++it){
    cout<<*it<<endl;
  }
  cout<<"================================"<<endl;
  int n = 10;
  cout<<(n&1==0?"even":"odd")<<endl;
  cout<<"================================"<<endl;
  set<pair<int,int>> s3{{9,5},{3,6},{4,7}};
  s3.emplace(1,20);
  cout<<s3.begin()->first<<endl;
  cout<<s3.rbegin()->first<<endl;
  for (auto it=s3.begin();it!=s3.end();++it){
    cout<<it->first<<endl;
  }
  //set.emplace_back()

  return 0;
}

