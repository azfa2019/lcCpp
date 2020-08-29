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
class FenwickTree{
  public:
    FenwickTree(int n):sums(n+1,0){};
    void update(int i,int delta){
      while(i<sums.size()){
        sums[i]+=delta;
        i+=lowbit(i);
      }
    }
    int query(int i){
      int sum=0;
      while(i>0){
        sum+=sums[i];
        i-=lowbit(i);
      }
      return sum;
    }
  private:
    vector<int> sums;
    int lowbit(int x){
      return x&(-x);
    }
};
class NumArray{
  public:
    NumArray(vector<int> nums):nums_(move(nums)),tree_(nums_.size()){
      for (int i=0;i<nums_.size();++i){
        tree_.update(i+1,nums_[i]);
      }
    }
    void update(int i,int val){
      tree_.update(i+1,val-nums_[i]);
      nums_[i]=val;
    }
    int rangeSum(int i,int j){
      return tree_.query(j+1)-tree_.query(i);
    }
  private:
    vector<int> nums_;
    FenwickTree tree_;

};
class solution0{
  public:
};
int main(){
  solution0 s0;
  vector<int> nums{1,3,5};
  NumArray num1= NumArray(nums);
  int sum=num1.rangeSum(0,2);
  cout<<sum<<endl;
  num1.update(1,2);
  cout<<num1.rangeSum(0,2)<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

