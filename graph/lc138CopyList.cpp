#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
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
struct Node{
  int val;
  Node *random;
  Node *next;
  Node(int val):val(val),random(nullptr),next(nullptr){};
};
class Solution0{
  public:
    Node *copyList(Node *head){
      if(!head) return nullptr;
      unordered_map<Node*,Node*>m;
      Node *cur=m[head]=new Node(head->val);
      Node *ans=cur;
      while(head){
        if(head->random){
          auto it=m.find(head->random);
          if(it==m.end()) it=m.emplace(head->random,new Node(head->random->val)).first;
          cur->random=it->second;
        }
        if(head->next){
          auto it=m.find(head->next);
          if(it==m.end()) it=m.emplace(head->next,new Node(head->next->val)).first;
          cur->next=it->second;
        }
        head=head->next;
        cur=cur->next;
      }
      return ans;
    }
};
int main(){
  Solution0 s0;
  Node n7(7),n13(13),n11(11),n10(10),n1(1);
  n7.next=&n13,n13.next=&n11,n11.next=&n10,n10.next=&n1;n1.next=nullptr;
  n7.random=nullptr,n13.random=&n7,n11.random=&n1,n10.random=&n11,n1.random=&n7;
  cout<<"val, "<<"next, "<<"random"<<endl;
  for (Node *n=&n7;n->next!=nullptr;n=n->next) cout<<n->val<<", "<<n->next->val<<", "<<(n->random==nullptr?-1:n->random->val)<<endl;
  cout<<"================================"<<endl;
  Node *ans0=s0.copyList(&n7);
  for (Node *n=ans0;n->next!=nullptr;n=n->next) cout<<n->val<<", "<<n->next->val<<", "<<(n->random==nullptr?-1:n->random->val)<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

