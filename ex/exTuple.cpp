#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
using namespace std;

int main(){
  tuple<string,int> t{"hello",2};
  cout<<get<0>(t)<<endl;
  cout<<get<1>(t)<<endl;
  cout<<"================================"<<endl;

  map<string,map<string,int>> g{
    {"A",{{"B",5},{"C",1}}},
        {"B",{{"A",5},{"C",2},{"D",1}}},
        {"C",{{"A",1},{"B",2},{"D",4},{"E",8}}},
        {"D",{{"B",1},{"C",4},{"E",3},{"F",6}}},
        {"E",{{"C",8},{"D",3}}},
        {"F",{{"D",6}}}
  };
  for (auto e:g["D"]){
    string w=e.first;
    cout<<w<<endl;
  }
    auto compare = [](pair<int,string> a,pair<int,string> b) { return a.first > b.first; };
    priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(compare)> q(compare);
    q.push(pair(0,"A"));
    q.push(pair(1,"B"));
    cout<<q.top().first<<endl;

  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

