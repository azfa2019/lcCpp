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
      vector<vector<int>> ans;
      if(num.size()==0) return ans;
      sort(num.begin(),num.end());
      vector<int> cur;
      helper(num,0,true,ans,cur);
      return ans;
    }
    void helper(vector<int>& num,int curIndex,bool taken,vector<vector<int>>& ans,vector<int>& cur){
      if (curIndex==num.size()) ans.push_back(cur);
      else {
        helper(num,curIndex+1,false,ans,cur);
        if(taken||num[curIndex]!=num[curIndex-1]){
          cur.push_back(num[curIndex]);
          helper(num,curIndex+1,true,ans,cur);
          cur.pop_back();
        }
      }
    }
};
int main(){
  vector<int> num{1,2,2};
  solution s0;
  auto ans=s0.subsets(num);
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

