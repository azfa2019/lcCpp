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
    Interval(int a,int b):start(a),end(b){};
};
class solution{
  public:
    int howManyRooms(vector<Interval> v){
      sort(v.begin(),v.end(),[](Interval& a, Interval& b){return a.start<b.start;});
      auto compare=[](Interval& a, Interval&b){return a.end>b.end;};
      priority_queue<Interval,vector<Interval>,decltype(compare)> q(compare); 
    //q.push(v[0]);
      //for(auto it=v.begin()+1;it!=v.end();it++){
      //  if (it->start>=q.top().end) q.pop();
      //  q.push(*it);
      //}
      for(auto interval:v){
      if(q.empty()) q.push(interval);
      else {
        if(interval.start>=q.top().end) q.pop();
        q.push(interval);
      }
      }
      return q.size();
    }
};

int main(){
  //vector<Interval> v{Interval(0,30),Interval(5,10),Interval(15,20)};
  vector<Interval> v{Interval(7,10),Interval(2,4)};
  solution s0;
  int ans=s0.howManyRooms(v);
  cout<<ans<<endl;
  vector<Interval> v1{Interval(0,30),Interval(5,10),Interval(15,20)};
  ans=s0.howManyRooms(v1);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
      auto compare=[](Interval& a, Interval&b){return a.end>b.end;};
      priority_queue<Interval,vector<Interval>,decltype(compare)> q(compare); 
      q.push(Interval{0,30});
      q.push(Interval{5,10});
      q.push(Interval{15,20});

      //cout<<q.top().end<<endl;
      //q.push(Interval{0,30});
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

