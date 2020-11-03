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
    ListNode* sortList(ListNode *head){
      if(!head||!head->next) return head;
      ListNode *slow=head,*fast=head->next;
      while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
      }
      ListNode *mid=slow->next;
      slow->next=nullptr;
      return merge(sortList(head),sortList(mid));
    }
  private:
    ListNode *merge(ListNode *l1,ListNode *l2){
      ListNode dummy(0),*tail=&dummy;
      while(l1&&l2){
        if(l1->val>l2->val) swap(l1,l2);
        tail->next=l1;
        l1=l1->next;
        tail=tail->next;
      }
      if(l1) tail->next=l1;
      if(l2) tail->next=l2;
      return dummy.next;
    }
};
void print(ListNode *head){
  for(ListNode *p=head;p;p=p->next) cout<<p->val<<" ";
  cout<<endl;
}
class Solution1{
  public:
    ListNode* sortList(ListNode *head){
      if(!head||!head->next) return head;
      int len=1;
      ListNode dummy(0),*cur=head;
      dummy.next=head;
      while(cur->next) {
        cur=cur->next;
        len++;
      }
      ListNode *l,*r,*tail;
      for(int n=1;n<len;n<<=1){
        cur=dummy.next;
        tail=&dummy;
        while(cur){
          l=cur;
          r=split(l,n);
          cur=split(r,n);
          auto merged=merge(l,r);
          tail->next=merged.first;
          tail=merged.second;
        }
      }
      return dummy.next;
    }
  private:
    ListNode* split(ListNode *head,int n){
      while(--n && head) head=head->next;
      ListNode *rest=head?head->next:nullptr;
      if(head) head->next=nullptr;
      return rest;
    }
    pair<ListNode*,ListNode*> merge(ListNode *l1,ListNode *l2){
      ListNode dummy(0),*tail=&dummy;
      while(l1&&l2){
        if(l1->val>l2->val) swap(l1,l2);
        tail->next=l1;
        l1=l1->next;
        tail=tail->next;
      }
      tail->next=l1?l1:l2;
      while(tail->next) tail=tail->next;
      return {dummy.next,tail};
    }
};
int main(){
  Solution0 s0;
  ListNode n0(-1),n1(5),n2(3),n3(4),n4(0);
  n0.next=&n1;
  n1.next=&n2;
  n2.next=&n3;
  n3.next=&n4;
  auto ans0=s0.sortList(&n0);
  print(ans0);
  cout<<"================================"<<endl;
  ListNode p0(-1),p1(5),p2(3),p3(4),p4(0);
  p0.next=&p1;
  p1.next=&p2;
  p2.next=&p3;
  p3.next=&p4;
  Solution1 s1;
  auto ans1=s1.sortList(&p0);
  print(ans1);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

