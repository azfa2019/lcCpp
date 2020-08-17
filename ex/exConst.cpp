#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;

int main(){
  const int ci=10;
  const int &r1=20;
  const int &r2=r1*2;
  cout<<r2<<endl;
  const double cdval=6.6;
  double dval=5.5;
  const double *cptr=&dval;
  //*cptr=9.9;
  cout<<*cptr<<endl;

  int err=0;
  int *const cperr=&err;
  *cperr=2;
  cout<<*cperr<<endl;
  int null = 0, *p = &null;
  return 0;
}

