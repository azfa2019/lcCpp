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
class solution0{
  public:
    int median3(vector<int>& num,int l,int r){
      int c=(r+l)/2;
      if(num[l]>num[c]) swap(num[l],num[c]);
      if(num[l]>num[r]) swap(num[l],num[r]);
      if(num[c]>num[r]) swap(num[c],num[r]);
      swap(num[c],num[r-1]);
      return num[r-1];
    }
    void quickSort(vector<int>& num,int l,int r){
      if(l==r) return;
      if(l+1==r) {
        if(num[l]>num[r]) swap(num[l],num[r]);
        return;
      }
      int p=median3(num,l,r);
      int i=l;int j=r-1;
      for(;;){
        while(num[++i]<p) {};
        while(num[--j]>p) {};
        if(i<j) swap(num[i],num[j]);
        else break;
      }
      swap(num[i],num[r-1]);
      quickSort(num,l,i-1);
      quickSort(num,i+1,r);
      return;
    }
};
class Solution1{
  public:
    vector<int> countingSort(vector<int>& num){
      auto[minIt,maxIt]=minmax_element(num.begin(),num.end());
      int minNum=*minIt,maxNum=*maxIt,n=num.size();
      int range=maxNum-minNum+1;
      vector<int> count(range),output(n);
      for(int i=0;i<n;i++) count[num[i]-minNum]++;
      for(int i=1;i<range;i++) count[i]+=count[i-1];
      for(int i=n-1;i>=0;i--){
        output[count[num[i]-minNum]-1]=num[i];
        count[num[i]-minNum]--;
      } 
      return output;
    }
};
class Solution2{
  public:
    vector<int> pq(vector<int> num){
      priority_queue<int> q(num.begin(),num.end());
      for(int i=num.size()-1;i>=0;i--){
        num[i]=q.top();
        q.pop();
      }
      return num;
    }
};
class Solution3{
  public:
    void heapify(vector<int>& tree,int n, int i){
      if(i>=n) return;
      int c1=2*i+1;
      int c2=2*i+2;
      int max=i;
      if(c1<n&&tree[c1]>tree[max]) max=c1;
      if(c2<n&&tree[c2]>tree[max]) max=c2;
      if(max!=i) {
        swap(tree[max],tree[i]);
        heapify(tree,n,max);
      }
    }
    void buildHeap(vector<int>& tree,int n){
      int parent=(n-2)/2;
      for(int i=parent;i>=0;i--){
        heapify(tree,n,i);
      }
    }
    vector<int> heapSort(vector<int>& tree,int n){
      buildHeap(tree,n);
      for (int i=n-1;i>=0;i--){
        swap(tree[i],tree[0]);
        heapify(tree,i,0);
      }
      return tree;
    }
};
class Solution4{
  public:
    void mergeSort(vector<int>& A){
      vector<int> tmpA(A.size());
      mergeSortHelper(A,tmpA,0,A.size()-1);
    }
    void mergeSortHelper(vector<int>& A,vector<int>& tmpA,int l,int r){
      if(l<r){
        int m=(r+l)/2;
        mergeSortHelper(A,tmpA,l,m);
        mergeSortHelper(A,tmpA,m+1,r);
        merge(A,tmpA,l,m+1,r);
      }
    }
    void merge(vector<int>& A,vector<int>& tmpA,int l,int r,int rightEnd){
      int leftEnd=r-1;
      int tmp=l;
      int n=rightEnd-l+1;
      while(l<=leftEnd&&r<=rightEnd){
        if(A[l]<=A[r]) tmpA[tmp++]=A[l++];
        else tmpA[tmp++]=A[r++];
      }
      while(l<=leftEnd) tmpA[tmp++]=A[l++];
      while(r<=rightEnd) tmpA[tmp++]=A[r++];
      for (int j=0;j<n;j++,rightEnd--) A[rightEnd]=tmpA[rightEnd];
    }
};
class Solution5{
  public:
    vector<int> bstSort(vector<int> num){
      multiset<int> s(num.begin(),num.end());
      return {s.begin(),s.end()};
    }
};
int main(){
  solution0 s0;
  //vector<int> num{4,5,6,7,0,1,2};
  //vector<int> num{5,2,3,1};
  vector<int> num{5,1,1,2,0,0};
  //vector<int> num{4,3};
  s0.quickSort(num,0,num.size()-1);
  showVector(num);
  cout<<"================================"<<endl;
  Solution1 s1;
  auto ans1=s1.countingSort(num);
  showVector(ans1);
  cout<<"================================"<<endl;
  Solution2 s2;
  auto ans2=s2.pq(num);
  showVector(ans2);
  cout<<"================================"<<endl;
  Solution3 s3;
  //vector<int> num3{2,5,3,1,10,4};
  //vector<int> num3{4,10,3,5,1,2};
  auto ans3=s3.heapSort(num,num.size());
  showVector(ans3);
  cout<<"================================"<<endl;
  Solution4 s4;
  vector<int> num4{4,10,3,5,1,2};
  s4.mergeSort(num4);
  showVector(num4);
  cout<<"================================"<<endl;
  Solution5 s5;
  auto ans5=s5.bstSort(num);
  showVector(ans5);
  cout<<"================================"<<endl;
  vector<int> test{num4.begin(),num4.end()};
  showVector(test);
  cout<<"================================"<<endl;
  return 0;
}

