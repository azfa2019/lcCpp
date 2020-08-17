#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
  int w[]{1,1,2,2},v[]{1,2,4,5};
  //int w[]{3,5,1,9,7},v[]{11,28,6,49,35};
  int W=4;

  int N=size(w);
  int dp[W+1];
  int tmp[W+1];
  for (int i=1;i<N+1;i++){
    for (int j=0;j<W+1;j++){
      if (j>=w[i-1]) dp[j]=max(tmp[j-w[i-1]]+v[i-1],tmp[j]);
      else dp[j]=tmp[j];
      //dp[i][j]=max(dp[i-1][j-w[i-1]]+v[i-1],dp[i-1][j]);
    }
    //tmp=dp;
    for (int k=0;k<W+1;k++) tmp[k]=dp[k];
  }
  cout<<dp[W]<<endl;
  cout<<"================================"<<endl;
    for (int j=0;j<W+1;j++)
      cout<<dp[j]<<" ";
    cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

