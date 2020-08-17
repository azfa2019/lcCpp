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
  int n=4,m=5;
  vector<int> v{1,2,3,4},w{2,4,4,5};
  int f[10]={};
  for (int i=1;i<n+1;i++){
    for (int j=m;j>=v[i];j--){
      //cout<<"i="<<i<<",j="<<j<<",f[j]="<<f[j]<<",j-v[i]="<<j-v[i]<<",f[j-v[i]]="<<f[j-v[i]]<<",w[i]="<<w[i]<<endl;
      f[j]=max(f[j],f[j-v[i]]+w[i]);
      //cout<<"f[j]="<<f[j]<<endl;
    }
  }
  int res=0;
  cout<<f[m]<<endl;

  cout<<"================================"<<endl;
  //for (int i=0;i<m+1;i++) cout<<f[n][i]<<endl;
  int d[2][5];
  d[0][0]=5;
  d[0][1]=10;
  d[0][2]=15;
  d[0][3]=20;

  cout<<d[1][-1]<<endl;
  for (int i=1;i<5;i++){
    for (int j=0;j<5;j++){
      if (j>=1) d[i%2][j]=d[(i-1)%2][j]+d[i%2][j-1];
      else d[i%2][j]=d[(i-1)%2][j];
      //cout<<d[i][j]<<endl;
    }
  }
  cout<<d[1][3]<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

