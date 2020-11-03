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
class Solution0{
  public:
    void quickSort(vector<int>&A,int l,int r){
      if(l==r) return;
      if(l+1==r) {
        if(A[l]>A[r]) swap(A[l],A[r]);
        return;
      }
      int p=median3(A,l,r);
      int i=l,j=r-1;
      while(true){
        while(A[++i]<p){};
        while(A[--j]>p){};
        if(i<j) swap(A[i],A[j]);
        else break;
      }
      swap(A[i],A[r-1]);
      quickSort(A,l,i-1);
      quickSort(A,i+1,r);
    }
  private:
    int median3(vector<int>&A,int l,int r){
      int c=(l+r)/2;
      if(A[l]>A[r]) swap(A[l],A[r]);
      if(A[l]>A[c]) swap(A[l],A[c]);
      if(A[c]>A[r]) swap(A[c],A[r]);
      swap(A[c],A[r-1]);
      return A[r-1];
    }
};
int main(){
  Solution0 s0;
  vector<int> A{14,17,13,15,19,10,3,16,9,12};
  s0.quickSort(A,0,A.size()-1);
  showVector(A);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

