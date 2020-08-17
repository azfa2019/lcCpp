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

class solution{
  public:
    int threeSumClosest(vector<int> num,int target){
      int delta=1000;
      sort(num.begin(),num.end());
      for(int i=0;i<num.size()-2;i++){
        int l=i+1,r=num.size()-1;
        while(l<r){
          int newDelta=target-num[i]-num[l]-num[r];
          if(newDelta==0) return target;
          if(abs(newDelta)<abs(delta)) delta=newDelta;
          if(newDelta>0) l++;
          else r--;
        }
      }
      return target-delta;
    }
};
int main(){
  vector<int> num{-1,2,1,-4};
  int target=1;
  solution s0;
  int ans=s0.threeSumClosest(num,target);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

