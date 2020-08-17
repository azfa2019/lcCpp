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
        cout << *it<<" "; 
    cout << '\n'; 
} 
class solution{
public:
  vector<int> rotateArray(vector<int> num,int k){
    int n=num.size();
    k%=n;
    rotate(num,0,n-1);
    rotate(num,0,k-1);
    rotate(num,k,n-1);
    return num;
  }
  void rotate(vector<int>&num,int l,int r){
    while(l<r){
      int tmp=num[l];
      num[l]=num[r];
      num[r]=tmp;
      l++;r--;
    }
  }
};
int main(){
  solution s0;
  map <vector<int>,int> num{{{1,2,3,4,5,6,7},3},{{-1,-100,3,99},2}};
  for(auto e:num) {
    auto ans= s0.rotateArray(e.first,e.second);
    showVector(ans);
  }
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

