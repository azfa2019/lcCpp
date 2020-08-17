#include <iostream>
using namespace std;
int main(){
  int ival=42;
  int *p = &ival;
  cout<<p<<endl;
  *p=7.5;
  cout<<"ival="<<ival<<endl;

  double dval;
  double *pd1=&dval;
  double *pd2=pd1;
  cout<<pd2<<endl;
  cout<<pd1<<endl;
  cout<<"**************************************************"<<endl;
  int p2=30;
  int*r2=&p2;
  cout<<*r2<<endl;
  *r2=40;
  cout<<*r2<<endl;
  cout<<p2<<endl;
  cout<<"**************************************************"<<endl;
  int i0=3;
  while(i0--) cout<<"hello"<<endl;
  cout<<"**************************************************"<<endl;
  char a='a';
  cout<<static_cast<int>(a)<<endl;
  cout<<"**************************************************"<<endl;
  return 0;
}
