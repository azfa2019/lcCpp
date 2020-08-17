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
  int weight=4; int n=size(w);
  int tmp[weight+1]{}; int dp[weight+1]{};
  for (int i=1;i<n;i++){
    for (int j=1;j<weight+1;j++)
      if(j>=w[i]) 
        dp[j]=max(tmp[j-w[i]]+v[i],tmp[j]);
      else
        dp[j]=tmp[j];

    for (int k=0;k<weight+1;k++) tmp[k]=dp[k];
  }
  cout<<dp[weight]<<endl;
  cout<<"================================"<<endl;
    for (int j=0;j<weight+1;j++)
      cout<<dp[j]<<" ";
    cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

