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
  auto compare = [](pair<int,string> a,pair<int,string> b) { return a.first > b.first; };
  priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(compare)> pq(compare);
  //{{1,"A"},{7,"B"},{3,"C"},{6,"D"},{2,"E"}};
  pq.push(pair(1,"A"));
  pq.push(pair(7,"B"));
  pq.push(pair(3,"C"));
  pq.push(pair(6,"D"));
  pq.push(pair(2,"E"));
  cout<<pq.top().first<<", "<<pq.top().second<<endl;
  pq.pop();
  cout<<pq.top().first<<", "<<pq.top().second<<endl;

  cout<<"================================"<<endl;
  priority_queue<pair<int,string>> pq1;
  //{{1,"A"},{7,"B"},{3,"C"},{6,"D"},{2,"E"}};
  pq1.push(pair(1,"A"));
  pq1.push(pair(7,"B"));
  pq1.push(pair(3,"C"));
  pq1.push(pair(6,"D"));
  pq1.push(pair(2,"E"));
  cout<<pq1.top().first<<", "<<pq1.top().second<<endl;
  pq1.pop();
  cout<<pq1.top().first<<", "<<pq1.top().second<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

