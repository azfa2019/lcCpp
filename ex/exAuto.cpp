#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;

int main(){
  vector<pair<const string,int>> wordCount{{"hi",4},{"hello",5}};
  pair <string,int> p1{"nice",5};
  cout<<p1.first<<endl;
  for (pair<const string,int>& p:wordCount){
    cout<<p.first<<" "<<p.second<<endl;
  }
  for (const auto& p:wordCount){
    cout<<p.first<<" "<<p.second<<endl;
  }

  for(auto it=wordCount.begin();it!=wordCount.end();++it){
    cout<<(*it).first<<" "<<(*it).second<<endl;
  }
  map<int,string> m0{{1,"John"}};
  cout<<m0[1]<<endl;


  return 0;
}

