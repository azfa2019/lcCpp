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
};
class MyLinkedList{
  public:
    MyLinkedList():head_(nullptr),tail_(nullptr),size_(0){};
    ~MyLinkedList(){
      Node *node=head_;
      while(node){
        Node *cur=node;
        node=node->next;
        delete cur;
      }
      head_=nullptr;
      tail_=nullptr;
    }
    int get(int index){
      if(index<0||index>=size_) return -1;
      auto node=head_;
      while(index--){
        node=node->next;
      }
      return node->val;
    }
    void addAtHead(int val){
      head_=new Node(val,head_);
      if(size_++==0) tail_=head_;
    }
    void addAtTail(int val){
      auto node=new Node(val);
      if(size_++==0) head_=tail_=node;
      else{
        tail_->next=node;
        tail_=tail_->next;
      }
    }
    void addAtIndex(int index,int val){
      if(index<0||index>=size_) return;
      if(index==0) return addAtHead(val);
      if(index==size_) return addAtTail(val);
      Node dummy(0,head_);
      Node *prev=&dummy;
      while(index--) prev=prev->next;
      prev->next=new Node(val,prev->next);
      size_++;
    }
    void deleteAtIndex(int index){
      if(index<0||index>=size_) return;
      Node dummy(0,head_);
      Node *prev=&dummy;
      for(int i=0;i<index;i++){
        prev=prev->next;
      }
      Node *node2Delete=prev->next;
      prev->next=prev->next->next;
      if(index==0) head_=prev->next;
      if(index==size_-1) tail_=prev;
      delete node2Delete;
      --size_;
    }
  private:
    struct Node{
      int val;
      Node *next;
      Node(int val,Node *next):val(val),next(next){};
      Node(int val):Node(val,nullptr){};
    };
    Node *head_;
    Node *tail_;
    int size_;
};
int main(){
  Solution0 s0;
  MyLinkedList linkedList;
  linkedList.addAtHead(1);
  cout<<linkedList.get(0)<<endl;
  linkedList.addAtTail(3);
  cout<<linkedList.get(1)<<endl;
  linkedList.addAtIndex(1,2);
  cout<<linkedList.get(1)<<endl;
  linkedList.deleteAtIndex(1);
  cout<<linkedList.get(1)<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}
