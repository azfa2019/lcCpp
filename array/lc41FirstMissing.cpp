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
  template<typename T>
void showVector(vector<T> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << *it<<" "; //'\t' ; 
    cout << '\n'; 
} 
class solution{
  public:
    int firstMissing(vector<int>nums){
      if(nums.empty()) return 1;
      int n=nums.size();
      for(int i=0;i<n;i++){
        if(nums[i]<=0) nums[i]=1000;
      }
      for(int i=0;i<n;i++){
        int num=abs(nums[i]);
        if(num<=n) nums[num-1]=-abs(nums[num-1]);
      }
      for(int i=0;i<n;i++){
        if(nums[i]>0) return i+1;
      }
      return n+1;
    }
};
int main(){
  solution s0;
  vector<vector<int>> nums{{1,2,3},{3,4,-1,1},{7,8,9,11,12}};
  for(auto e:nums) cout<<s0.firstMissing(e)<<" ";
  cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

