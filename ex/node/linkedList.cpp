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
#include "node.h"
//typedef struct _node{
//  int value;
//  struct _node *next;
//}Node;
typedef struct _list{
  Node *head;
  //Node *tail;
}List;
using namespace std;
  template<typename T>
void showVector(vector<T> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << *it<<" "; //'\t' ; 
  cout << '\n'; 
} 
class Solution0{
  public:
};
void add(List *pList,int number){
  Node *p=(Node*)malloc(sizeof(Node));
  p->value=number;
  p->next=nullptr;
  //find the last node
  Node *last=pList->head;
  if(last){
    while(last->next){
      last=last->next;
    }
    last->next=p;
  }else{
    pList->head=p;
  }
};
void print(List *pList){
  Node *p;
  for(p=pList->head;p;p=p->next){
    cout<<p->value<<" ";
  }
  cout<<endl;
}
int main(){
  List list;
  list.head=nullptr;
  int number;
  do{
    cout<<"type a number: ";
    cin>>number;
    if(number!=-1) {
      add(&list,number);
    }
  } while(number!=-1);
  cout<<list.head->value<<endl;
  Node *last=list.head;
  while(last->next) last=last->next;
  cout<<last->value<<endl;
  cout<<"================================"<<endl;
  print(&list);
  cout<<"================================"<<endl;
  cout<<"type a number: ";
  cin>>number;
  Node *p, *q;
  int isFound=0;
  for(p=list.head;p;p=p->next){
    if(p->value==number){
      cout<<"found"<<endl;
      isFound=1;
      break;
    }
  }
  if(!isFound) cout<<"not found"<<endl;
  for(q=nullptr,p=list.head;p;q=p,p=p->next){
    if(p->value==number){
      if(q) q->next=p->next;
      else list.head=p->next;
      free(p);
      isFound=1;
      break;
    }
  }
  cout<<"================================"<<endl;
  for(p=list.head;p;p=q){
    q=p->next;
    free(p);
  }
  cout<<"================================"<<endl;
  return 0;
}

