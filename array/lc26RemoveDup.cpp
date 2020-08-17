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
    int slow=1;
    for(int i=1;i<num.size();i++){
      while(num[i]==num[i-1]) i++;
      num[slow++]=num[i];
    }
    return slow;
  }
};
int main(){
  solution s0;
  vector<vector<int>> num{{1,1,2},{0,0,1,1,1,2,2,3,3,4}};
  for(auto e:num) cout<<s0.removeDup(e)<<" ";
  cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

