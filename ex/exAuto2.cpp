#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;

int main(){
  map<string,int> wordCount{{"hello",4},{"world",6}};
  for(pair<const string,int>& p:wordCount){
    cout<<p.first<<" "<<p.second<<endl;
  }
  for(const auto& p:wordCount){
    cout<<p.first<<" "<<p.second<<endl;
  }
  for(auto it=wordCount.begin();it!=wordCount.end();++it){
    cout<<(*it).first<<" "<<(*it).second<<endl;
  }
  return 0;
}

