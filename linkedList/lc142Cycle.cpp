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
  ListNode* next;
  ListNode(int x):val(x),next(nullptr){};
};
class Solution0{
  public:
    ListNode *findCycleStart(ListNode *head){
      ListNode *slow=head;
      ListNode *fast=head;
      while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
      }
      if(!fast||!fast->next) return nullptr;
      slow=head;
      while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
      }
      return slow;
    }
};
int main(){
  Solution0 s0;
  ListNode n0(3);
  ListNode n1(2);
  ListNode n2(0);
  ListNode n3(4);
  n0.next=&n1;
  n1.next=&n2;
  n2.next=&n3;
  n3.next=&n1;
  auto ans0=s0.findCycleStart(&n0);
  cout<<ans0->val<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

