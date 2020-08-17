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
  int removeElement(vector<int> num, int val){
    int slow=0;
    for(int i=0;i<num.size();i++){
      if(num[i]!=val) num[slow++]=num[i];
    }
    return slow;
  }
};
int main(){
  solution s0;
  vector<pair<vector<int>,int>> num{{{3,2,2,3},3},{{0,1,2,2,3,0,4,2},2}};
  for(auto e:num)
  cout<<s0.removeElement(e.first,e.second)<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

