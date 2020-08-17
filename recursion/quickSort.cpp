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
  int median3(vector<int>& A,int l, int r){
    int c=(l+r)/2;
    cout<<"c="<<c<<endl;
    if(A[l]>A[c]) swap(A[l],A[c]);
    if(A[l]>A[r]) swap(A[l],A[r]);
    if(A[c]>A[r]) swap(A[c],A[r]);
    swap(A[c],A[r-1]);
    return A[r-1];
  }
  void quickSort(vector<int>& A,int l, int r){
    if(r==l) return;
    if(r==l+1){
      if(A[l]>A[r]) swap(A[l],A[r]);
      return;
    }
    int p=median3(A,l,r);
    int i=l,j=r-1;
    cout<<"i="<<i<<endl;
    cout<<"r-1="<<r-1<<endl;
    for(;;){
      while (A[++i]<p) {};
      while (A[--j]>p) {};
      if(i<j) swap(A[i],A[j]);
      else break;
    }
    swap(A[i],A[r-1]);
    quickSort(A,l,i-1);
    quickSort(A,i+1,r);
  }
  void quick_sort(vector<int>& A,int n){
    quickSort(A,0,n-1);
  }
};
int main(){
  //vector<int> A{13,81,92,43,65,31,57,26,75,0};
  vector<int> A{5,2,3,1};
  Solution s0;
  //s0.quick_sort(A,A.size());
  s0.quickSort(A,0,A.size()-1);
  //int i=s0.median3(A,0,9);
  //cout<<i<<endl;
  for(auto e:A) cout<<e<<" ";
  cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

