#include<iostream>
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
    DSU(int x):size(x),parent(x),rank(x){
      iota(begin(parent),end(parent),0);
    }
    int Find(int x){
      if(x!=parent[x]) parent[x]=Find(parent[x]);
      return parent[x];
    }
    void Union(int x,int y){
      int px=Find(x);
      int py=Find(y);
      if(px==py) return;
      if(rank[px]<rank[py]) swap(px,py);
      else if(rank[px]==rank[py]) ++rank[px];
      parent[py]=px;
      --size;
    }
    int Size(){
      return size;
    }
  private:
    int size;
    vector<int>parent;
    vector<int>rank;
};
class Solution0{
  public:
    int numSimilarString(vector<string>&A){
      DSU dsu(A.size());
      for (int i=0;i<A.size();i++)
        for(int j=i+1;j<A.size();j++)
          if(similar(A[i],A[j])) dsu.Union(i,j);
      return dsu.Size();
    }
  private:
    bool similar(string a,string b){
      int diff=0;
      for(int i=0;i<a.length();i++)
        if(a[i]!=b[i]&&++diff>2) return false;
      return true;
    }
};
int main(){
  Solution0 s0;
  vector<string> A{"tars","rats","arts","star"};
  auto ans0=s0.numSimilarString(A);
  cout<<ans0<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

