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
  Interval(int s,int e):start(s),end(e){};
};
struct compare{
  bool operator() (const Interval& x, const Interval& y) const{
    return x.start<y.start;
  };
};

class solution{
  private:
    set<Interval,compare>mp;
  public:
    void addInterval(int val){
      if(mp.empty()){
        mp.insert(Interval(val,val));
        return;
      }
      auto upper=mp.upper_bound(Interval(val,val));
      auto lower=upper;
      if(upper==mp.end()) upper--;
      if(lower!=mp.begin()) lower--;

      if(lower->start<=val && lower->end>=val) return;
      int st=val,ed=val;
      auto loc=mp.begin();
      if(lower->end==val-1 && upper->start==val+1){
        st=lower->start,ed=upper->end;
        mp.erase(lower);
        loc=mp.erase(upper);
      }
      else if(lower->end==val-1){
        st=lower->start,ed=val;
        loc=mp.erase(lower);
      } else if(upper->start==val+1){
        st=val,ed=upper->end;
        loc=mp.erase(upper);
      }
      mp.insert(loc,Interval(st,ed));
      return;
    }
    void show(){
      for (auto e:mp){
        cout<<"["<<e.start<<","<<e.end<<"]"<<" ";
      }
      cout<<endl;
    }
};
int main(){
  solution s0;
  s0.addInterval(1);
  s0.show();
  s0.addInterval(3);
  s0.show();
  s0.addInterval(7);
  s0.show();
  s0.addInterval(2);
  s0.show();
  s0.addInterval(6);
  s0.show();
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

