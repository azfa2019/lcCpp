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
    vector<vector<int>> subsets(vector<int>& num){
      int n=num.size();
      vector<vector<int>> ans;
      for(int s=0;s<1<<n;s++){
        vector<int> cur;
        for (int i=0;i<n;i++)
          if(s&(1<<i)) cur.push_back(num[i]);
        ans.push_back(cur);
      }
      return ans;
    }
};
int main(){
  vector<int> num{1,2,3};
  solution s0;
  auto ans=s0.subsets(num);
  for_each(
      ans.begin(),
      ans.end(),
      [](vector<int> v){
      cout<<"[";
      for_each(
          v.begin(),
          v.end(),
          [](int i) {cout<<i; });
      cout<<"]"<<endl;
      } 
      );
  cout<<"================================"<<endl;
  for(auto e:ans){
    cout<<"[";
    for(auto f:e) cout<<f;
    cout<<"]"<<endl;
  }
//  vector<int> v0{1,3,4};
//  for_each(v0.begin(),v0.end(),[](int i){cout<<i<<endl; cout<<"hello"<<endl;});
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

