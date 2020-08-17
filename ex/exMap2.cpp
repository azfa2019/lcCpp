#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;

int main(){
  map<string, int> m{{"tom",3},{"john",6}};
  map<string, vector<int>> n{{"tom",{3,4}},{"john",{6,7}}};
  cout<<m["tom"]<<endl;
  cout<<n["tom"][1]<<endl;
  cout<<"===================="<<endl;
  if(m.find("tom")!=m.end()) cout<<m["tom"]<<endl;
  cout<<"===================="<<endl;
  for(auto e:m){
    cout<<e.first<<endl;
  }
  return 0;
}

