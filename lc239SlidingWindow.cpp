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
class monotonicQueue{
  private:
    deque<int> data;
  public:
    void push(int e){
      while(!data.empty()&&e>data.back()) data.pop_back();
      data.push_back(e);
    }
    void pop(){data.pop_front();};//delete max element
    int max() const {return data.front();};
    void showMQueue(){
      deque<int> tmp=data;
      while(!tmp.empty()){
        cout<<tmp.front()<<" ";
        tmp.pop_front();
      }
      cout<<endl;
    }
};
class solution{
public:
  vector<int> brute(vector<int> num,int k){
    vector<int> ans;
    for(int i=k-1;i<num.size();i++){
      ans.push_back(*max_element(num.begin()+i-k+1,num.begin()+i+1));
    }
    return ans;
  }
  vector<int> usingSet(vector<int> num,int k){
    vector<int> ans;
    multiset<int> window;
    for(int i=0;i<k-1;i++){
      window.insert(num[i]);
      //cout<<num[i]<<endl;
    }
    for(int i=k-1;i<num.size();i++){
      window.insert(num[i]);
      ans.push_back(*window.rbegin());
      window.erase(window.find(num[i-k+1]));
    }
      return ans;
  }
  vector<int> usingMQ(vector<int> num,int k){
    vector<int> ans;
    monotonicQueue q;
    for(int i=0;i<num.size();i++){
      q.push(num[i]);
      if(i-k+1>=0){
        ans.push_back(q.max());
        if(q.max()==num[i-k+1]) q.pop();
      }
    }
    return ans;
  }
};
int main(){
  solution s0;
  vector<int> num{1,3,-1,-3,5,3,6,7};
  int k=3;
  //auto ans=s0.brute(num,k);
  //auto ans=s0.usingSet(num,k);
  auto ans=s0.usingMQ(num,k);
  for(int i:ans) cout<<i<<endl;
  cout<<"================================"<<endl;
  monotonicQueue mq;
  for(int i:num){
    mq.push(i);
    mq.showMQueue();
  }
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

