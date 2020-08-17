#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

class Person{
 public:
  float age;
  string name;
  bool operator < (const Person &rhs) const{return age<rhs.age;};
  bool operator > (const Person &rhs) const{return age>rhs.age;};
};
int main(){
  multiset<Person> myset;
  Person p1{23,"Tom"};
  Person p2{26,"Jon"};
  myset.insert(p1);
  myset.insert(p2);

  for (const auto &e:myset){
    cout<<e.age<<" "<<e.name<<endl;
  }
  return 0;
}

