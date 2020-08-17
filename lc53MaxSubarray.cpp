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
  int maxSubarray(vector<int> num){
    int ans=num[0],sum=num[0];
    for (int i=1;i<num.size();i++){
      sum=max(sum+num[i],num[i]);
      if(ans<sum) ans=sum;
    }
    return ans;
  }
};
class solution0{
public:
  int maxSubarray(vector<int> num){
    int ans=num[0],sum=num[0];
    for (int i=1;i<num.size();i++){
      sum+=num[i];
      int tmp=max(sum,num[i]);
      if(ans<tmp) ans=tmp;
      sum=tmp;
      //cout<<ans<<endl;
    }
    return ans;
  }
};
int main(){
  solution s0;
  vector<int> num{-2,1,-3,4,-1,2,1,-5,4};
  auto ans=s0.maxSubarray(num);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  solution0 s1;
  ans=s1.maxSubarray(num);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

