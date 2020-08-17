#include <iostream>
#include <cstdlib>
using namespace std;

int box1=1;
int box2=2;
int * gptr;

void passByPtr(int* ptr);
void passByPtrRef(int * & ptrRef);
int main(int agrc,char* argv[]){
int*p=&box1;
gptr=&box2;

//passByPtr(p);
passByPtrRef(p);
cout<<"*p="<<*p <<endl;
cout<< "box1="<<box1 <<endl;
cout<< "box2="<<box2 <<endl;
}
void passByPtr(int*ptr){
  *ptr=3;
  ptr=gptr;
  //*ptr=4;
}
void passByPtrRef(int * & ptrRef){
  *ptrRef=5;
  ptrRef=gptr;
  //*ptrRef=6;
}
