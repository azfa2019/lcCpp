#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;

int main(){
  int i;
  int &r1=i;
  int& r2=i;
  int* p1=&i;
  int *&r3=p1;
  r1=5;
  cout<<i<<endl;
  cout<<r2<<endl;
  cout<<p1<<endl;
  cout<<*p1<<endl;
  *p1=10;
  cout<<i<<endl;
  cout<<"p1="<<p1<<endl;
  cout<<"r3="<<r3<<endl;
  cout<<"--------------------------------------------------------"<<endl;

  p1=0;
  int*p2=0;
  cout<<(p1==p2?"true":"false")<<endl;
  cout<<"--------------------------------------------------------"<<endl;
  const int size=512;
  //size=555;
  return 0;

}

