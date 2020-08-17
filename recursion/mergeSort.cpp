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
  void merge1(vector<int>& A, vector<int>& tmpA, int l, int r, int rightEnd){
    int leftEnd=r-1;
    int tmp=l;
    int n=rightEnd-l+1;
    while(l<=leftEnd && r<=rightEnd){
      if(A[l]<=A[r]) tmpA[tmp++]=A[l++];
      else tmpA[tmp++]=A[r++];
    }
    while(l<=leftEnd) tmpA[tmp++]=A[l++];
    while(r<=rightEnd) tmpA[tmp++]=A[r++];
  }
  void mergePass(vector<int>& A,vector<int>& tmpA,int n,int length){
    int i;
    for(i=0;i<=n-2*length;i+=2*length) merge1(A,tmpA,i,i+length,i+2*length-1);
    if(i+length<n) merge1(A,tmpA,i,i+length,n-1);
    else {
      for (int j=i;j<n;j++) tmpA[j]=A[j];
    }
  }
  void merge_sort(vector<int>& A,int n){
    int length=1;
    vector<int> tmpA(A.size());
    while(length<n){
      mergePass(A,tmpA,n,length);
      length*=2;
      mergePass(tmpA,A,n,length);
      length*=2;
    }
  }
  void merge(vector<int>& A, vector<int>& tmpA, int l, int r, int rightEnd){
    int leftEnd=r-1;
    int tmp=l;
    int n=rightEnd-l+1;
    while(l<=leftEnd && r<=rightEnd){
      if(A[l]<=A[r]) tmpA[tmp++]=A[l++];
      else tmpA[tmp++]=A[r++];
    }
    while(l<=leftEnd) tmpA[tmp++]=A[l++];
    while(r<=rightEnd) tmpA[tmp++]=A[r++];
    for(int i=0;i<n;i++,rightEnd--){
      A[rightEnd]=tmpA[rightEnd];
    }
  }
  void mSort(vector<int>& A,vector<int>& tmpA,int l,int rightEnd){
    int center;
    if(l<rightEnd){
      center=(l+rightEnd)/2;
      mSort(A,tmpA,l,center);
      mSort(A,tmpA,center+1,rightEnd);
      merge(A,tmpA,l,center+1,rightEnd);
    }
  }
  void mergeSortRecursion(vector<int>& A,int n){
    vector<int> tmpA(n);
    mSort(A,tmpA,0,n-1);
  }
};

int main(){
  //vector<int> A{0,1,2,3,1,13,24,26,2,15,27,38,3,4,5};
  //vector<int> A{0,1,2,3,1,24,13,2,26,15,27,38,3,4,5};
  vector<int> A{0,10,12,31,1,24,13,2,26,15,27,38,3,4,5};
  cout<<A.size()<<endl;
  vector<int> tmpA(A.size());
  Solution s0;
  int l =4,r=8,rightEnd=11;
  //s0.merge(A,tmpA,l,r,rightEnd);
  //s0.mSort(A,tmpA,l,rightEnd);
  //s0.mergeSort(A,A.size());
  //s0.merge_sort(A,A.size());
  s0.mergeSortRecursion(A,A.size());
  for(auto e:A) cout<<e<<" ";
  cout<<endl;
  cout<<A.size()<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

