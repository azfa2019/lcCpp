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
struct ListNode{
  int val;
  ListNode *next;
  ListNode(int x):val(x),next(nullptr){};
};
class Solution0{
  public:
    ListNode *mergeLists(vector<ListNode*> lists){
      auto comp=[](ListNode *a,ListNode *b){return a->val>b->val;};
      priority_queue<ListNode *,vector<ListNode*>,decltype(comp)>q(comp);
      for(auto list:lists) if(list) q.push(list);
      ListNode dummy(0);
      ListNode *tail=&dummy;
      while(!q.empty()){
        tail->next=q.top();q.pop();
        tail=tail->next;
        if(tail->next) q.push(tail->next);
      }
      return dummy.next;
    }
    ListNode * merge2Lists(ListNode *l1, ListNode *l2){
      ListNode dummy(0);
      ListNode *tail=&dummy;
      while(l1&&l2){
        if(l1->val>l2->val) swap(l1,l2);
        tail->next=l1;
        l1=l1->next;
        tail=tail->next;
      }
      tail->next=l1?l1:l2;
      return dummy.next;
    }
    ListNode * mergeLists01(vector<ListNode*> lists,int l, int r){
      if(l>r) return nullptr;
      if(l==r) return lists[l];
      if(l==r-1) return merge2Lists(lists[l],lists[r]);
      int m=l+(r-l)/2;
      auto l1=mergeLists01(lists,l,m);
      auto l2=mergeLists01(lists,m+1,r);
      return merge2Lists(l1,l2);
    }
};
void print(ListNode* head){
  ListNode *p;
  for(p=head;p;p=p->next) cout<<p->val<<" ";
  cout<<endl;
}
int main(){
  Solution0 s0;
  ListNode n00(1);ListNode n10(1);ListNode n20(2);
  ListNode n01(4);ListNode n11(3);ListNode n21(6);
  ListNode n02(5);ListNode n12(4);
  n00.next=&n01; n10.next=&n11; n20.next=&n21;
  n01.next=&n02; n11.next=&n12;
  vector<ListNode*> lists{&n00,&n10,&n20};
  auto ans0=s0.mergeLists(lists);
  print(ans0);
  cout<<"================================"<<endl;
  ListNode p00(1);ListNode p10(1);ListNode p20(2);
  ListNode p01(4);ListNode p11(3);ListNode p21(6);
  ListNode p02(5);ListNode p12(4);
  p00.next=&p01; p10.next=&p11; p20.next=&p21;
  p01.next=&p02; p11.next=&p12;
  vector<ListNode*> lists01{&p00,&p10,&p20};
  auto ans01=s0.mergeLists01(lists01,0,lists01.size()-1);
  print(ans01);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

