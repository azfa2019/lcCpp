#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
class MedianFinderMultiSet{
  private:
    multiset<int> m;
    multiset<int>::iterator l;
    multiset<int>::iterator r;
  public:
    void addNum(int num){
      if(m.empty()) {
        l=r=m.insert(num);
        return;
      }
      m.insert(num);
      if(m.size()&1){
        if(num>=*r) ++l;
        else l=--r;
      }else{
        if(num>=*r) ++r;
        else --l;
      }
    }
    double findMedian(){
      return (static_cast<double>(*l)+*r)/2;
    }
};
class MedianFinderPQ{
  private:
    priority_queue<int> l;
    priority_queue<int,vector<int>,greater<int>>r;
  public:
    MedianFinderPQ(){};
    void addNum(int num){
      if(l.empty()||l.top()>=num) l.push(num);
      else r.push(num);
//balance l and r
      if(l.size()<r.size()){
        l.push(r.top());
        r.pop();
      }
      if(l.size()==r.size()+2){
        r.push(l.top());
        l.pop();
      }
    }
    double findMedian(){
      if(l.size()>r.size()) return static_cast<double>(l.top());
      else return (static_cast<double> (l.top())+r.top())/2;
    }

};
class MedianFinder{
 public:
  MedianFinder():l(m.cend()),r(m.cend()){};
  void addNum(int num){
    if (m.empty()){
      l=m.insert(num);
      r=l;
      return;
  }
    const size_t n=m.size();
    m.insert(num);
    if(n&1){
      if(num>=*r){
        ++r;
      } else{
        --l;
      }} else{
        if(num>=*r){
          ++l;
        }else{
          --r;
          l=r;
        }
      }
    return;
  }
  double findMedian(){
    return (static_cast <double> (*l)+(*r))/2;
  }
 private:
  multiset<int> m;
  multiset<int>::const_iterator l;
  multiset<int>::const_iterator r;
};
int main(){

  MedianFinder m1;
  m1.addNum(1);
  m1.addNum(2);
  cout<<m1.findMedian()<<endl;
  m1.addNum(3);
  cout<<m1.findMedian()<<endl;
  cout<<"=================================================="<<endl;
  MedianFinderPQ m2;
  m2.addNum(1);
  m2.addNum(2);
  double median=m2.findMedian();
  //cout<<m2.findMedian()<<endl;
  cout<<median<<endl;
  m2.addNum(3);
  cout<<m2.findMedian()<<endl;
  cout<<"=================================================="<<endl;
  MedianFinderMultiSet m3;
  m3.addNum(1);
  m3.addNum(2);
  cout<<m3.findMedian()<<endl;
  m3.addNum(3);
  cout<<m3.findMedian()<<endl;
  return 0;
}

