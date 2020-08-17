#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
using namespace std;
template<typename T>
void showVector(vector<T> g) 
{ 
    for (auto it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
class solution{
public:
};
int main(){
  solution s0;
  vector<int> v1{1,2,3};
  vector<string> v2{"a","b","c"};
  showVector(v1);
  showVector(v2);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

