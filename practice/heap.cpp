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
    void heapify(int tree[],int n,int i){
      if(i>=n) return;
      int c1=2*i+1,c2=2*i+2,max=i;
      if(c1<n&&tree[c1]>tree[max]) max=c1;
      if(c2<n&&tree[c2]>tree[max]) max=c2;
      if(max!=i){
        swap(tree[max],tree[i]);
        heapify(tree,n,max);
      }
    }
    void buildHeap(int tree[],int n){
      int last=n-1,parent=(last-1)/2;
      for(int i=parent;i>=0;i--) heapify(tree,n,i);
    }
    void heapSort(int tree[],int n){
      buildHeap(tree,n);
      for(int i=n-1;i>=0;i--){
        swap(tree[i],tree[0]);
        heapify(tree,i,0);
      }
    }
};
int main(){
  Solution0 s0;
  //int tree[]={4,10,3,5,1,2};
  int tree[]={2,5,3,1,10,4};
  //s0.heapify(tree,sizeof(tree)/sizeof(*tree),0);
  //s0.buildHeap(tree,sizeof(tree)/sizeof(*tree));
  s0.heapSort(tree,sizeof(tree)/sizeof(*tree));
  for(int i=0;i<sizeof(tree)/sizeof(*tree);++i) cout<<tree[i]<<" ";
  cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

