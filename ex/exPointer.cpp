#include <iostream>
using namespace std;
void swap(int *pa,int *pb);
void minMax(int a[],int n,int *min, int *max);
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
  //char a='a';
  //cout<<static_cast<int>(a)<<endl;
  cout<<"**************************************************"<<endl;
  int a=5; int b=6;
  swap(&a,&b);
  cout<<a<<" "<<b<<endl;
  cout<<"**************************************************"<<endl;
  int a1[]={1,2,3,4,21,23,55};
  cout<<"main sizeof(a): "<<sizeof(a1)<<endl;
  cout<<"main address of a: "<<&a1<<endl;
  //cout<<sizeof(a1)/sizeof(a1[0])<<endl;
  int min, max;
  minMax(a1,sizeof(a1)/sizeof(a1[0]),&min,&max);
  cout<<min<<" "<<max<<endl;
  cout<<"**************************************************"<<endl;
  cout<<a1[0]<<endl;
  cout<<"**************************************************"<<endl;
  int i1=10;
  int i2=20;
  int * const p1=&i1;
  //p1=&i2;
  const int * p3=&i2;
  //*p3=6;
  cout<<p1<<endl;
  cout<<p3<<endl;
  cout<<"**************************************************"<<endl;
  cout<<"**************************************************"<<endl;
  cout<<"**************************************************"<<endl;
  return 0;
}
void minMax(int *a,int n,int *min, int *max){
  *min=a[0],*max=a[0];
  cout<<"minmax sizeof(a): "<<sizeof(a)<<endl;
  cout<<"minmax address of a: "<<a<<endl;
  for(int i=1;i<n;++i){
    if(a[i]<*min) *min=a[i];
    if(a[i]>*max) *max=a[i];
  }
  a[0]=1000;
}
void swap(int *pa, int *pb){
  int t=*pa;
  *pa=*pb;
  *pb=t;
}
