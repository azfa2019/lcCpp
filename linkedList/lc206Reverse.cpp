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
    ListNode *reverseList(ListNode *head){
      ListNode *prev=nullptr;
      ListNode *cur=head;
      ListNode *next;
      while(cur){
        next=cur->next;
        cur->next = prev;
        prev=cur;
        cur=next;
      }
      return prev;
    }
};
void print(ListNode *head){
  ListNode *p;
  for(p=head;p;p=p->next) cout<<p->val<<" ";
  cout<<endl;
}
int main(){
  Solution0 s0;
  ListNode n0(1);
  ListNode n1(2);
  ListNode n2(3);
  ListNode n3(4);
  ListNode n4(5);
  n0.next=&n1;
  n1.next=&n2;
  n2.next=&n3;
  n3.next=&n4;
  auto ans0=s0.reverseList(&n0);
  print(ans0);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

