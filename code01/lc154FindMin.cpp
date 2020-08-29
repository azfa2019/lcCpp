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
using namespace std;
  template<typename T>
void showVector(vector<T> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << *it<<" "; //'\t' ; 
    cout << '\n'; 
} 
class solution{
  public:
    int findMin(vector<int> num){
      return findMin(num,0,num.size()-1);
    }
  private:
    int findMin(const vector<int>& num,int l,int r){
      if(l+1>=r) return min(num[l],num[r]);
      int m=l+(r-l)/2;
      return min(findMin(num,l,m-1),findMin(num,m,r));
    }
};
int main(){
  solution s0;
  //vector<int> num{4,5,6,7,0,1,2};
  vector<int> num{2,2,2,1,2,3,2};
  auto ans0=s0.findMin(num);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

