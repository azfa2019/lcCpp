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

class Solution{
  public:
    bool possible(vector<int> target){
      if (target.size()==1) return true;
      priority_queue<int> q(begin(target),end(target));
      int sum=accumulate(begin(target),end(target),0);
      int i=0;
      while (true){
        int max=q.top(); q.pop();
        if(max==1) return true;
        int rest=sum-max;
        if (rest==1) return true;
        if(rest>=max||rest==0) return false;
        int r=max%rest;
        if(r==0) return false;
        q.push(r); sum=rest+r;
        //cout<<i++<<endl;
      }
      //return true;
    }
};
class Solution0{
  public:
    bool possible(vector<int> target){
      priority_queue <int> q(target.begin(),target.end());
      long sum=accumulate(target.begin(),target.end(),0LL);
      while(true){
        int m=q.top();q.pop();
        sum-=m;
        if(m==1) return true;
        if(sum==1) return true;
        if(sum==0||sum>=m) return false;
        int r=m%sum;
        if(r==0) return false;
        q.push(r);
        sum+=r;
      }
      return true;
    } 
};
int main(){
  //vector<int> target{9,3,5};
  //vector<int> target{1,1,1,2};
  //vector<int> target{8,5};
  //vector<int> target{8,1,6};
  Solution0 s;
  vector<vector<int>> target{{9,3,5},{1,1,1,2},{8,5}};
  for(auto e:target)
    cout<<s.possible(e)<<" ";
  cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

