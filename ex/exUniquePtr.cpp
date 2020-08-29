#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <memory>
using namespace std;
  template<typename T>
void showVector(vector<T> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << *it<<" "; //'\t' ; 
    cout << '\n'; 
} 
class Entity{
  public:
    Entity(){
      cout<<"created entity"<<endl;
    }
    ~Entity(){
      cout<<"deleted entity"<<endl;
    }
    void print(){}
};
class solution0{
  public:
};
int main(){
  solution0 s0;
  unique_ptr<Entity> entity(new Entity());
  entity->print();
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

