#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;

int main(){
  set<string> s{"the","bus","school"};
  //set<string>::iterator it=s.find("the");
  //cout<<*it<<endl;
  for (auto it=s.begin();it!=s.end();++it){
    cout<<*it<<endl;
  }
  map<string,int> m{{"the",3},{"bus",5},{"school",7}};
  auto mapIt=m.begin();
  ++(mapIt->second);
  cout<<mapIt->first<<": "<<mapIt->second<<endl;
  return 0;
}

