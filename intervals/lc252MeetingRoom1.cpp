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
class solution{
  public:
    bool canBook(vector<Interval> vi){
      sort(vi.begin(),vi.end(),[](const Interval& a,const Interval& b){return a.start<b.start;});
      for(auto it=vi.begin()+1;it!=vi.end();it++){
        if(it->start<(it-1)->end) return false;
      }
      return true;
    }
};
int main(){
  vector<Interval> vi{Interval(0,30),Interval(5,10),Interval(15,20)};
  solution s0;
  bool ans=s0.canBook(vi);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

