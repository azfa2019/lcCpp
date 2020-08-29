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

struct Interval{
  int start;
  int end;
  Interval():start(0),end(0){};
  Interval(int s, int e):start(s),end(e){};
};
class Solution{
  public:
    vector<Interval> merge(vector<Interval>& intervals){
      if(intervals.empty()) return {};
      sort(intervals.begin(),intervals.end(),[](Interval& a,Interval& b){return a.start<b.start;});
      vector<Interval> ans;
      for (auto interval:intervals){
        if(ans.empty()||ans.back().end<interval.start){
          ans.push_back(interval);
        } else{
          ans.back().end=max(interval.end,ans.back().end);
        }
      }
      return ans;
    }

};
int main(){
  vector<Interval> intervals{ Interval(15,18), Interval(2,6), Interval(8,10),Interval(1,3)};
  Solution s0;
  auto itv=s0.merge(intervals);
  for(auto e:itv) cout<<e.start<<", "<<e.end<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

