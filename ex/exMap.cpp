#include <iostream>
#include <map>
using namespace std;
int main(){

  map <int,string> m1;
  m1[1]="Tom";
  m1[2]="Max";
  m1[3]="John";
  cout<<m1[3]<<endl;
  cout<<m1[3]<<endl;
  auto it=m1.begin();
  cout<<"===================="<<endl;
  cout<<it->first<<endl;
  cout<<"===================="<<endl;
  auto res=m1.insert({4,"Dave"});
  cout<<m1[4]<<endl;
  cout<<"===================="<<endl;
  cout<<res.first->second<<endl;
  cout<<res.second<<endl;
  cout<<"===================="<<endl;
  cout<<m1.find(2)->second<<endl;
  cout<<m1.count(2)<<endl;
  cout<<"===================="<<endl;
  cout<<m1.lower_bound(2)->second<<endl;
  cout<<m1.upper_bound(2)->second<<endl;
  return 0;
}
