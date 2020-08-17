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

class Solution{
 public:
  int binarySearch(vector<int>& t,int k){
    int l,r,m,notFound=-1;
    l=1;r=t.size();
    while(l<=r){
      m=(l+r)/2;
      if(k<t[m]) r=m-1;
      else if(k>t[m]) l=m+1;
      else return m;
    }
    return notFound;
  }
};
int main(){
  vector<int> t{0,5,16,39,45,51,98,100,202,226,321,368,444,501};
  Solution s0;
  int ans=s0.binarySearch(t,444);
  //int ans=s0.binarySearch(t,43);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

