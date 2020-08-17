#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;

int main(){
  vector<int> v{2,4,6,8};
  vector<int>::const_iterator it=v.cbegin();
  cout<<*it<<endl;
  cout<<"================================"<<endl;
  for(auto it=v.cbegin();it!=v.cend();++it){
    cout<<*it<<endl;
  }
  cout<<"================================"<<endl;
    cout<<*(it+2)<<endl;
  cout<<"================================"<<endl;
  string s="hello";
  auto it2=s.begin()+2;
  cout<<*it2<<endl;
  cout<<"================================"<<endl;
  const unsigned sz=3;
  int sz2=3;
  int a1[sz]={0,1,2};
  cout<<a1[2]<<endl;
  cout<<"================================"<<endl;
  return 0;
}

