#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;

int main(){
  const int i =0;
  const int& ri=i;
  decltype(i) j=1;
  decltype(ri) ri2=j;

  cout<<"================================"<<endl;
  int i2=42;
  int* p=&i2;
  int& r=i2;
  decltype(*p) c=i2;
  cout<<c<<endl;

  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

