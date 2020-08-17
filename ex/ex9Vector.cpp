#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
int main(){
  vector<int> myVector;
  myVector.push_back(3);
  myVector.push_back(5);
  vector<int> myVector1{1,2,3};
  cout<<"vector:"<<endl;
  for(int i=0;i<myVector1.size();i++){
    cout<<myVector1[i]<<endl;
  }
  vector<pair<int,float>> v{{1,.5f},{2,1.5f}};
  cout<<v[0].second<<endl;
  map<string,int> m{{"hello",0},{"hi",1}};
  for(auto entry:m){
    cout<<entry.first<<", "<<entry.second<<endl;
  }

  pair<int,int> x(3,4);//using ()
  pair<int,int> y{5,6};//using intializer list
  cout<<x.first<<","<<y.first<<endl;
  set<int> set1{3,1,9};
  set<int>::iterator itr;
  for(itr=set1.begin();itr!=set1.end();++itr){
    cout<<*itr<<endl;
  }

  for(auto it=set1.begin();it!=set1.end();++it){
    cout<<*it<<endl;
  }
  pair<int,float> p{1,3.14};
  const auto& [x1,y1]=p;
  auto [x2,y2]=p;
  cout<<x1<<endl;
  cout<<x2<<endl;
  int a=3;
  int& x3=a;
  int y3=a;
  x3=4;
  cout<<a<<endl;
  return 0;
}
