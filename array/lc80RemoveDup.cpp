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
  int removeDup(vector<int> num){
    int p=2;
    for(int i=2;i<num.size();i++){
      if(num[i-2]!=num[i]) num[p++]=num[i];
    }
    return p;
  }
};
int main(){
  solution s0;
  vector<vector<int>> num={{1,1,2,2,3},{0,0,1,1,1,1,2,3,3}};
  for(auto e:num) cout<<s0.removeDup(e)<<" ";
  cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

