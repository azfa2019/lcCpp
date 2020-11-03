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
  ListNode():val(0),next(nullptr){};
  ListNode(int x):val(x),next(nullptr){};
};
class Solution0{
  public:
    ListNode *swapPairs(ListNode *head){
      if(!head||!head->next) return head;
      ListNode dummy(0);
      dummy.next=head;
      head=&dummy;
      while(head&&head->next&&head->next->next){
        ListNode *n1=head->next;
        ListNode *n2=n1->next;
        n1->next=n2->next;
        n2->next=n1;
        head->next=n2;
        head=n1;
      }
      return dummy.next;
    }
};
void print(ListNode *head){
  ListNode *p;
  for(p=head;p;p=p->next) cout<<p->val<<" ";
  cout<<endl;
};
int main(){
  Solution0 s0;
  ListNode n0(1);
  ListNode n1(2);
  ListNode n2(3);
  ListNode n3(4);
  n0.next=&n1;
  n1.next=&n2;
  n2.next=&n3;
  auto ans0=s0.swapPairs(&n0);
  print(ans0);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

