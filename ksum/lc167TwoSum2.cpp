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
    pair<int,int> twoSum(vector<int> num,int target){
      int l=0,r=num.size()-1;
      while(l<r){
        int sum= num[l]+num[r];
        if(sum==target) return {l,r};
        else if(sum<target) l++;
        else r--;
      }
      return {-1,-1};
    }
};

int main(){
  vector<int> num{2,7,11,15,8};
  int target =9;
  solution s0;
  auto ans=s0.twoSum(num,target);
  cout<<ans.first<<", "<<ans.second<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

