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
  int maxProduct(vector<int> num){
    int curMax=num[0],curMin=num[0],ans=num[0];
    for(int i=1;i<num.size();i++){
      int tmp1=curMax*num[i],tmp2=curMin*num[i];
      curMax=max(num[i],max(tmp1,tmp2));
      curMin=min(num[i],max(tmp1,tmp2));
      ans=max(ans,curMax);
    }
    return ans;
  }
};
int main(){
  solution s0;
  vector<int> num{2,3,-2,4};
  auto ans=s0.maxProduct(num);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

