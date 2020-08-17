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

class Interval{
  public:
    int start;
    int end;
    Interval(int s,int e):start(s),end(e){};
};
class solution {
  public:
    vector<Interval> insert(vector<Interval> intervals,Interval newInterval){
      int s=newInterval.start;
      int e=newInterval.end;
      vector<Interval> r,l;
      for(auto interval:intervals){
        if(interval.start>e) r.push_back(interval);
        else if (interval.end<s) l.push_back(interval);
        else {
          s=min(s,interval.start);
          e=max(e,interval.end);
        }
      }
      vector<Interval> ans(move(l));
      ans.emplace_back(Interval(s,e));
      ans.insert(ans.end(),r.begin(),r.end());
      return ans;
    };
};

int main(){
  vector<Interval> intervals{Interval(1,3),Interval(6,9)};
  Interval newInterval=Interval(2,5);
  solution s0;
  auto int0=s0.insert(intervals,newInterval);
  for(auto e:int0) cout<<e.start<<", "<<e.end<<endl;

  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

