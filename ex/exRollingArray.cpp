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
  //int a[7]{1,2,4,1,7,8,3};
  int a[5]{4,1,1,9,1};
  int f[3];
  int n=size(a);
  f[0]=a[0];
  f[1]=max(a[0],a[1]);
  for (int i=2;i<n;i++){
    f[i%3]=max(f[(i-2)%3]+a[i],f[(i-1)%3]);
  }
  cout<<f[(n-1)%3]<<endl;
  cout<<"================================"<<endl;
  int fib[3];
  fib[0]=0;
  fib[1]=1;
  fib[2]=1;
  for (int i=2;i<10;i++){
    fib[0]=fib[1];
    fib[1]=fib[2];
    fib[2]=fib[0]+fib[1];
  }
  cout<<fib[2]<<endl;
  cout<<"================================"<<endl;
  int m[2]{};
  //cout<<size(m)<<endl;
  cout<<"================================"<<endl;
  int a1[]{22,3,4};
  cout<<a1[0]<<endl;
  cout<<"================================"<<endl;
  stack<int> s3;
  s3.push(2);
  s3.push(3);
  cout<<s3.top()<<endl;
  cout<<!s3.empty()<<endl;
  //cout<s3.empty()<<endl;
  return 0;
}

