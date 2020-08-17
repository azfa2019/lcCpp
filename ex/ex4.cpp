#include <iostream>
using namespace std;
class Student{
 private:
  string name;
  double gpa;
 public:
  Student(string aName,double aGpa){
    name=aName;
    gpa=aGpa;
  }
  bool hasHonors(){
    if(gpa>3.5){
      return true;
    }else{
      return false;
    }
  }
  void setGpa(double aGpa){
    gpa=aGpa;
  }
};
int main(){
  Student student1("Jim",3.9);
  cout<<student1.hasHonors()<<endl;
  student1.setGpa(2.0);
  cout<<student1.hasHonors()<<endl;
  return 0;
}
