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
    ListNode *merger2Lists(ListNode *l1,ListNode *l2){
      ListNode dummy(0);
      ListNode *tail=&dummy;
      while(l1&&l2){
        if(l1->val<l2->val){
          tail->next=l1;
          l1=l1->next;
        } else{
          tail->next=l2;
          l2=l2->next;
        }
        tail=tail->next;
      }
      if(l1) tail->next=l1;
      if(l2) tail->next=l2;
      return dummy.next;
    }
    ListNode *mergeLists(ListNode *l1,ListNode *l2){
      if(!l1||!l2) return l1?l1:l2;
      if(l1->val<l2->val) {
        l1->next=mergeLists(l1->next,l2);
        return l1;
      }
      else {
        l2->next=mergeLists(l1,l2->next);
        return l2;
      }
    }
};
void print(ListNode *head){
  ListNode *p;
  for(p=head;p;p=p->next) cout<<p->val<<" ";
  cout<<endl;
}
int main(){
  Solution0 s0;
  ListNode n00(1),n01(3),n02(5),n03(7);
  ListNode n10(2),n11(4);
  n00.next=&n01;n01.next=&n02;n02.next=&n03;
  n10.next=&n11;
  auto ans0=s0.merger2Lists(&n00,&n10);
  print(ans0);
  cout<<"================================"<<endl;
  ListNode p00(1),p01(3),p02(5),p03(7);
  ListNode p10(2),p11(4);
  p00.next=&p01;p01.next=&p02;p02.next=&p03;
  p10.next=&p11;
  auto ans1=s0.mergeLists(&p00,&p10);
  print(ans1);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

