#include <iostream>
using namespace std;
int main(){
  string name="Mike";
  char grade='A';
  string phrase = "Giraffe Academy";
  bool isMale=false;
  double gpa=2.3;
  cout<<name<<endl;
  cout<< grade<<endl;
  cout<<phrase.length()<<endl;
  cout<<phrase.find("Academy")<<endl;
  cout<<phrase.substr(8,11)<<endl;
  string phraseSub=phrase.substr(8,3);
  cout<<phraseSub<<endl;
  int age;
  //cout<<"enter age";
  //cin>>age;
  //cout<<"you are "<<age<<" years old";
  //cout<<"enter name";
  //getline(cin,name);
  //cout<<"you are "<<name;
  int luckyNums[]={4,8,15};
  cout<<luckyNums[2];
  return 0;

}
