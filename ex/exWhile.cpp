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
  int i=0;
  while(i<5) i++;
  cout<<i<<endl;
  cout<<"================================"<<endl;
  vector<int> v0{0,1,2,3};
  cout<<v0[2]<<endl;
  cout<<"================================"<<endl;
  vector<int> tmpA(3);
  tmpA[2]=3;
  cout<<"================================"<<endl;
  swap(v0[0],v0[1]);
  cout<<v0[0]<<endl;
  cout<<v0[1]<<endl;
  cout<<"================================"<<endl;
  cout<<max(v0[0],v0[2])<<endl;
  return 0;
}

