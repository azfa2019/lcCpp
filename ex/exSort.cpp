#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

bool isShorter(const string& s1, const string& s2){
  return s1.size()<s2.size();
}
int main(){
  vector<string> v{"fox","red","over","an","turtle"};
  vector<int> v0{5,3,2,9};
  //sort(v.begin(),v.end(),isShorter);
  sort(v.begin(),v.end(),[](const string& s1,const string& s2){return s1.size()<s2.size();});
  for(const auto& e:v){
    cout<<e<<endl;
  }

  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

