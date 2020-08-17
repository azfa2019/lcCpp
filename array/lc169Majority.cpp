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
  template<typename T>
void showVector(vector<T> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << *it<<" "; //'\t' ; 
    cout << '\n'; 
} 
class solution{
  public:
    int hashTable(vector<int>& nums){
      unordered_map<int,int> count;
      for(auto num:nums)
        if (++count[num]>nums.size()/2) return num;
      return -1;
    }
    int bst(vector<int>& nums){
      map<int,int> count;
      for(auto num:nums) if(++count[num]>nums.size()/2) return num;
      return -1;
    }
    int random(vector<int> nums){
      srand(time(NULL));
      int n=nums.size();
      while(true){
        int index=rand()%n;
        int count=0;
        for(int num:nums) if (nums[index]==num&&++count>n/2) return num;
      }
      return -1;
    }
    int bitVoting(vector<int> nums){
      int n=nums.size();
      int majority=0;
      for(int i=0;i<32;i++){
        int mask=1<<i;
        int count=0;
        for(int num:nums)
          if(num&mask&&++count>n/2){
            majority|=mask;
            break;
          }
      }
      return majority;
    }
    int mooreVoting(vector<int> nums){
      int majority=nums.front();
      int count=0;
      for(int num:nums){
        if(num==majority) ++count;
        else if(--count==0){
          count=1;
          majority=num;
        }
      }
      return majority;
    }
    int fullSort(vector<int> nums){
      sort(nums.begin(),nums.end());
      return nums[nums.size()/2];
    }
    int partialSort(vector<int> nums){
      nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end());
      return nums[nums.size()/2];
    }
    int divideConquer1(vector<int>& nums,int l,int r){
      if(l==r) return nums[l];
      int m=(l+r)/2;
      int ml=divideConquer1(nums,l,m);
      int mr=divideConquer1(nums,m+1,r);
      if(ml==mr) return ml;
      return count(nums.begin()+l,nums.begin()+r+1,ml)>
        count(nums.begin()+l,nums.begin()+r+1,mr)?
        ml:mr;
    }
    int divideConquer1(vector<int> nums){
      return divideConquer1(nums,0,nums.size()-1);
    }
    pair<int,int> divideConquer2(vector<int>& nums,int l,int r){
      if(l==r) return {nums[l],1};
      int m=(l+r)/2;
      auto ml=divideConquer2(nums,l,m);
      auto mr=divideConquer2(nums,m+1,r);
      if(ml.first==mr.first) return {ml.first,ml.second+mr.second};
      if(ml.second>mr.second) return {ml.first,ml.second+count(nums.begin()+m+1,nums.begin()+r+1,ml.first)};
      else return {mr.first,mr.second+count(nums.begin()+l,nums.begin()+m+1,mr.first)};
    }
    int divideConquer2(vector<int> nums){
      return divideConquer2(nums,0,nums.size()-1).first;
    }
};
int main(){
  solution s0;
  vector<vector<int>> nums{{3,2,3},{2,2,1,1,1,2,2}};
  for(auto e:nums) cout<<s0.hashTable(e)<<" "; cout<<endl;
  cout<<"================================"<<endl;
  for(auto e:nums) cout<<s0.bst(e)<<" "; cout<<endl;
  cout<<"================================"<<endl;
  for(auto e:nums) cout<<s0.random(e)<<" "; cout<<endl;
  cout<<"================================"<<endl;
  for(auto e:nums) cout<<s0.bitVoting(e)<<" "; cout<<endl;
  cout<<"================================"<<endl;
  for(auto e:nums) cout<<s0.mooreVoting(e)<<" "; cout<<endl;
  cout<<"================================"<<endl;
  for(auto e:nums) cout<<s0.fullSort(e)<<" "; cout<<endl;
  cout<<"================================"<<endl;
  for(auto e:nums) cout<<s0.partialSort(e)<<" "; cout<<endl;
  cout<<"================================"<<endl;
  for(auto e:nums) cout<<s0.divideConquer1(e)<<" "; cout<<endl;
  cout<<"================================"<<endl;
  for(auto e:nums) cout<<s0.divideConquer2(e)<<" "; cout<<endl;
  cout<<"================================"<<endl;
  return 0;
}

