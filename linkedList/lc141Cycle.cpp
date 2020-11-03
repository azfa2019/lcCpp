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
#include <unordered_set>
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
    bool hasCycle0(ListNode *head){
      unordered_set<ListNode*> seen;
      while(head){
        if(seen.count(head)) return true;
        seen.insert(head);
        head=head->next;
      }
      return false;
    }
    bool hasCycle1(ListNode *head){
      ListNode *slow=head;
      ListNode *fast=head;
      while(fast){
        if(!fast->next) return false;
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast) return true;
      }
      return false;
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
  cout<<(s0.hasCycle0(&n0)?"has cycle":"no cycle")<<endl;
  cout<<"================================"<<endl;
  cout<<(s0.hasCycle1(&n0)?"has cycle":"no cycle")<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

