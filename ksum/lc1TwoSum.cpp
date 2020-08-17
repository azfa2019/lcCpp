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

class solution {
  public:
  pair<int,int> twoSum(vector<int> num,int target){
    unordered_map<int,int> indices;
    for (int i=0;i<num.size();i++){
      indices[num[i]]=i;
    }
    for (int i=0;i<num.size();i++){
      int left=target-num[i];
      if(indices.count(left) && indices[left]!=i){
        return {i,indices[left]};
      }
  }
    return {};
};
};
int main(){
  //vector<int> num{3,2,4};
  vector<int> num{2,7,11,15};
  solution s0;
  int target{9};
  auto ans=s0.twoSum(num,target);
  cout<<ans.first<<", "<<ans.second<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

