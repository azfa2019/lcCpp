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
  ListNode():val(),next(nullptr){};
  ListNode(int x):val(x),next(nullptr){};
};
void print(ListNode *head){
  ListNode *p;
  for(p=head;p;p=p->next) cout<<p->val<<" ";
  cout<<endl;
}
class Solution0{
  public:
    ListNode* insertionSort(ListNode *head){
      if(!head||!head->next) return head;
      ListNode dummy(0);
      dummy.next=head;
      ListNode *pre,*tmp,*cur=head;
      while(cur&&cur->next){
        if(cur->val<=cur->next->val) cur=cur->next;
        else{
          tmp=cur->next;
          cur->next=cur->next->next;
          pre=&dummy;
          while(pre->next->val<=tmp->val){
            pre=pre->next;
          }
          tmp->next=pre->next;
          pre->next=tmp;
        }
      }
      return dummy.next;
    }
    ListNode *insertionSort01(ListNode *head){
      ListNode dummy(0);
      ListNode *cur=&dummy;
      while(head){
        ListNode *t=head->next;
        cout<<t->val<<endl;
        cur=&dummy;
        while(cur->next&&cur->next->val<=head->val) cur=cur->next;
        //cout<<cur->next->val<<endl;
        head->next=cur->next;
        cur->next=head;
        head=t;
        cout<<dummy.next->val<<endl;
        cout<<head->val<<endl;
      }
      return dummy.next;
    }
};
int main(){
  Solution0 s0;
  ListNode n0(4),n1(2),n2(1),n3(3);
  n0.next=&n1,n1.next=&n2,n2.next=&n3;
  auto ans0=s0.insertionSort(&n0);
  print(ans0);
  cout<<"================================"<<endl;
  int i0=5;
  int *p0=&i0;
  *p0=10;
  cout<<i0<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

