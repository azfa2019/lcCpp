#include <iostream>
using namespace std;
int main(){
  int box=5;
  int *ptr=&box;
  int**dPtr=&ptr;
  cout<<"box holds"<<box<<endl;
  cout<<"box lives at "<<&box<<endl;
  cout<<"ptr points to address "<<ptr<<endl;
  
  return 0;
}
