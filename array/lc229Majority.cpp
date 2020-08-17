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
    vector<int> majority(vector<int> nums){
      int n1=0,c1=0,n2=1,c2=0;
      for(int num:nums){
        if(num==n1) ++c1;
        else if(num==n2) ++c2;
        else if(c1==0) {
          n1=num;
          c1=1;
        }
        else if(c2==0) {
          n2=num;
          c2=1;
        }
        else{
          --c1;
          --c2;
        }
      }
      c1=c2=0;
      for(int num:nums){
        if(num==n1) ++c1;
        else if(num==n2) ++c2;
      }
      int c=nums.size()/3;
      vector<int>ans;
      if(c1>c) ans.push_back(n1);
      if(c2>c) ans.push_back(n2);
      return ans;
    }
};
int main(){
  solution s0;
  vector<vector<int>> nums{{3,2,3},{1,1,1,3,3,2,2,2}};
  for(auto e:nums){
    auto ans=s0.majority(e);
    showVector(ans);
  }
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

