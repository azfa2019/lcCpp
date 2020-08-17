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

int main(){
  int w[]{0,1,1,2,2},v[]{0,1,2,4,5};
  int W=4,n=size(w);
  int dp[W+1]{};
  for (int i=1;i<n;i++){
    for (int j=W;j>=w[i];j--){
      dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
    }
  }
  cout<<dp[W]<<endl;
  cout<<"================================"<<endl;
  for(auto e:dp)
    cout<<e<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

