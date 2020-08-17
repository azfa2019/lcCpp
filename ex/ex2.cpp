#include <iostream>
using namespace std;
void sayHi(string name);
int main(){
  int luckyNums[20];
  cout<<luckyNums[2]<<endl;
  string name="Mike";
  sayHi(name);
  return 0;
}
void sayHi(string name){
  cout<<name<<endl;
  bool isMale=false;
  if(isMale){
    cout<<"you are male";
  }else{
    cout<<"you are not male"<<endl;
  }
  int dayNum=0;
  switch(dayNum){
    case 0:
      cout<<"Sunday"<<endl;
      break;
    case 1:
      cout<<"Monday"<<endl;
      break;
  }
  int i=0;
  while( i<5){
    cout<<i<<endl;
    i++;
  }
  for(int i=0;i<5;i++){
    cout<<"2nd count"<<endl;
  }
  int numGrid[2][2]={
    {1,2},
    {3,4}
  };
  cout<<numGrid[1][1]<<endl;
  int a=19;
  int* ptr=&a;
  cout<<*ptr<<endl;
}
