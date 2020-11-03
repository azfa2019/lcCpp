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
    void mergeSort(vector<int>&A,int n){
      int length=1;
      vector<int> tmpA(A.size());
      while(length<n){
        mergePass(A,tmpA,n,length);
        length*=2;
        mergePass(tmpA,A,n,length);
        length*=2;
      }
    }
  private:
    void mergePass(vector<int>&A,vector<int>&tmpA,int n,int length){
      int i;
      for(i=0;i<n-2*length;i+=2*length){
        merge1(A,tmpA,i,i+length,i+2*length-1);
      }
      if(i+length<n) merge1(A,tmpA,i,i+length,n-1);
      else for(int j=i;j<n;j++) tmpA[j]=A[j];
    }
    void merge1(vector<int>& A,vector<int>& tmpA,int l,int r,int rightEnd){
      int leftEnd=r-1,tmp=l;
      while(l<=leftEnd&&r<=rightEnd){
        if(A[l]<=A[r]) tmpA[tmp++]=A[l++];
        else tmpA[tmp++]=A[r++];
      }
      while(l<=leftEnd) tmpA[tmp++]=A[l++];
      while(r<=rightEnd) tmpA[tmp++]=A[r++];
    }
};
class Solution1{
  public:
    void mergeSort(vector<int>& A,int n){
      vector<int>tmpA(n);
      mSort(A,tmpA,0,n-1);
    }
  private:
    void merge(vector<int>&A,vector<int>& tmpA,int l,int r,int rightEnd){
      int leftEnd=r-1,tmp=l,n=rightEnd-l+1;
      while(l<=leftEnd&&r<=rightEnd){
        if(A[l]<=A[r])tmpA[tmp++]=A[l++];
        else tmpA[tmp++]=A[r++];
      }
      while(l<=leftEnd) tmpA[tmp++]=A[l++];
      while(r<=rightEnd) tmpA[tmp++]=A[r++];
      for(int j=0;j<n;j++,rightEnd--) A[rightEnd]=tmpA[rightEnd];
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
};
int main(){
  Solution0 s0;
  //vector<int> A{1,6,3,7},tmpA(A.size());
  vector<int> A{38,27,43,3,9,82,10};
  showVector(A);
  s0.mergeSort(A,A.size());
  showVector(A);
  cout<<"================================"<<endl;
  Solution1 s1;
  vector<int> A0{38,27,43,3,9,82,10};
  s1.mergeSort(A0,A0.size());
  showVector(A0);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

