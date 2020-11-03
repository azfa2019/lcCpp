#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
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
class DSU{
  public:
    DSU(int n):p(n){
      for(int i=0;i<n;i++) p[i]=i;
    }
    int Find(int x){
      if(x!=p[x]) p[x]=Find(p[x]);
      return p[x];
    }
    void Union(int x,int y){
      p[Find(x)]=Find(y);
    }
  private:
    vector<int>p;
};
class Solution0{
  public:
    int largeCompoSize(vector<int>&A){
      int n=*max_element(begin(A),end(A));
      DSU dsu(n+1);
      for(int a:A){
        int t=sqrt(a);
        for(int k=2;k<=t;k++){
          if(a%k==0){
            dsu.Union(a,k);
            dsu.Union(a,a/k);
          }
        }
      }
      int ans=1;
      unordered_map<int,int>c;
      for(int a:A){
        ans=max(ans,++c[dsu.Find(a)]);
      }
      return ans;
    }
};
int main(){
  Solution0 s0;
  vector<int>A{2,3,6,7,4,12,21,39};
  auto ans0=s0.largeCompoSize(A);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

