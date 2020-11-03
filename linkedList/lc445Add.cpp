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
    ListNode *addTwoNum(ListNode *l1,ListNode *l2){
      stack<int> s1,s2;
      while(l1){
        s1.push(l1->val);
        l1=l1->next;
      }
      while(l2){
        s2.push(l2->val);
        l2=l2->next;
      }
      ListNode *head=nullptr;
      int sum=0;
      while(!s1.empty()||!s2.empty()||sum){
        sum+=s1.empty()?0:s1.top();
        if(!s1.empty()) s1.pop();
        sum+=s2.empty()?0:s2.top();
        if(!s2.empty()) s2.pop();
        ListNode *n=new ListNode(sum%10);
        sum/=10;
        n->next=head;
        head=n;
      }
      return head;
    }
};
void print(ListNode *head){
  ListNode *p;
  for(p=head;p;p=p->next) cout<<p->val<<" ";
  cout<<endl;
}
int main(){
  Solution0 s0;
  ListNode n00(7);
  ListNode n01(2);
  ListNode n02(4);
  ListNode n03(3);
  ListNode n10(5);
  ListNode n11(6);
  ListNode n12(4);
  n00.next=&n01;
  n01.next=&n02;
  n02.next=&n03;
  n10.next=&n11;
  n11.next=&n12;
  auto ans0=s0.addTwoNum(&n00,&n10);
  print(ans0);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

