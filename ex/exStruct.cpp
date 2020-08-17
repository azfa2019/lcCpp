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
void showVector(vector <int> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << '\t' << *it; 
  cout << '\n'; 
}; 
struct Interval{
  int start;
  int end;
  bool operator <(const Interval& rhs) const{
    return start<rhs.start;
  }
};
struct Interval0{
  int start;
  int end;
};
struct compare{
  bool operator()(const Interval0& lhs,const Interval0& rhs) const{
    return lhs.start<rhs.start;
  }
};
template<typename T>
void showSet(set<T> s){
  for(auto e:s) cout<<e.start<<" ";
  cout<<endl;
}
template<typename T>
void showSet0(set<T,compare> s){
  for(auto e:s) cout<<e.start<<" ";
  cout<<endl;
}
int main(){
  set<Interval> s1;
  s1.insert(Interval{6,7});
  Interval i1{1,2};
  s1.insert(i1);
  s1.insert(Interval{3,4});
  showSet(s1);
  cout<<"================================"<<endl;
  set<Interval0,compare> s2;
  s2.insert(Interval0{6,7});
  s2.insert(Interval0{2,7});
  s2.insert(Interval0{4,7});
  showSet0(s2);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

