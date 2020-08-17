#include <iostream>
using namespace std;
int main(){
  int i=1, &r1=i;
  cout<<r1<<endl;
  double d=6.6,&r2=d;
  r2=3.14;
  r2=5.5;
  i=r2;
  r1=d;
  cout<<"r1="<<r1<<endl;
  cout<<"r2="<<r2<<endl;
  cout<<"d="<<d<<endl;
  return 0;
}
