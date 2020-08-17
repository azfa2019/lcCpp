#include <iostream>
using namespace std;
class Entity{
 public:
  float x,y;
  Entity(){
    cout<<"entity created!"<<endl;
  }
  ~Entity(){
    cout<<"entity destroyed"<<endl;
  }
void printEntity(){
  cout<<x<<", "<<y<<endl;
}
};
void function1(){
  Entity e;
  e.printEntity();
}
int main(){
  function1();
}

