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
  vector<int> v{1,3,7};
  v.push_back(15);
  cout<<v.at(0)<<endl;
  cout<<v[0]<<endl;
  cout<<"================================"<<endl;
  v.insert(v.begin()+2,100);
  cout<<v[2]<<endl;
  v.erase(v.begin());
  cout<<v[0]<<endl;
  cout<<"================================"<<endl;
  v.clear();
  cout<<v.empty()<<endl;
  cout<<"================================"<<endl;
  int i2=20;
  auto d=static_cast<double>(i2);
  cout<<d<<endl;
  cout<<"================================"<<endl;
  int w[5]{};
  cout<<w[0]<<endl;
  cout<<"================================"<<endl;
  vector<int> v0{1,2,3};
  cout<<*v0.begin()<<endl;
  cout<<*(v0.begin()+1)<<endl;
  cout<<*max_element(v0.begin(),v0.begin()+2)<<endl;
  cout<<"================================"<<endl;
  vector<int> v3=move(v0);
  cout<<v3[1]<<endl;
  cout<<"================================"<<endl;
  cout<<(2>9||3>6||(5>1?"yes":"no"))<<endl;
  cout<<"================================"<<endl;
  cout<<((5>1?"yes":"no"))<<endl;
  cout<<"================================"<<endl;
  string s="hello";
  s+=(1>0?"->":"");
  cout<<s<<endl;
  while(s.size()!=1) s.pop_back();
  cout<<s<<endl;
  cout<<"================================"<<endl;
  int i=123;
  cout<<(i>to_string(i).size())<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

