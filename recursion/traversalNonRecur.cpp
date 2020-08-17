#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
using namespace std;
struct BNode{
  char value;
  BNode *lChild,*rChild;
};
typedef struct BNode BNode;
typedef struct BNode* BTree;

void postOrderTraversal(BNode* root){
  BNode* node=root;
  BNode* lastVisit=root;
  stack<BNode*> s;
  while(node!=NULL || !s.empty()){
    while(node!=NULL){
      s.push(node);
      node=node->lChild;
    }
    node=s.top();
    if(node->rChild==NULL||node->rChild==lastVisit){
      cout<<node->value<<endl;
      s.pop();
      lastVisit=node;
      node=NULL;
    }else{
      node=node->rChild;
    }
  }
}
void preOrderTraversal(BNode* root){
  BNode* T=root;
  stack<BNode*> s;
  while(T!=NULL || !s.empty()){
    while(T!=NULL){
      cout<<T->value<<endl;
      s.push(T);
      T=T->lChild;
    }
    if(!s.empty()){
      T=s.top();
      s.pop();
      //cout<<T->value<<endl;
      T=T->rChild;
    }
  }
}
void inOrderTraversal(BNode* root){
  BNode* T=root;
  stack<BNode*> s;
  while(T!=NULL || !s.empty()){
    while(T!=NULL){
      //cout<<root->value<<endl;
      s.push(T);
      T=T->lChild;
    }
    if(!s.empty()){
      T=s.top();
      s.pop();
      cout<<T->value<<endl;
      T=T->rChild;
    }
  }
}

void createBTree1(){
  BNode node1{'A',NULL,NULL};
  BNode node2{'B',NULL,NULL};
  BNode node3{'C',NULL,NULL};
  BNode node4{'D',NULL,NULL};
  BNode node5{'E',NULL,NULL};
  BNode node6{'F',NULL,NULL};
  BNode node7{'G',NULL,NULL};
  BNode node8{'H',NULL,NULL};
  node1.lChild=&node2;
  node1.rChild=&node6;
  node2.rChild=&node3;
  node3.lChild=&node4;
  node3.rChild=&node5;
  node6.rChild=&node7;
  node7.lChild=&node8;
  postOrderTraversal(&node1);
}
void createBTree2(){
  BNode a{'A',NULL,NULL};
  BNode b{'B',NULL,NULL};
  BNode c{'C',NULL,NULL};
  BNode d{'D',NULL,NULL};
  BNode e{'E',NULL,NULL};
  BNode f{'F',NULL,NULL};
  BNode g{'G',NULL,NULL};
  BNode h{'H',NULL,NULL};
  BNode i{'I',NULL,NULL};
  a.lChild=&b;
  a.rChild=&c;
  b.lChild=&d;
  b.rChild=&f;
  c.lChild=&g;
  c.rChild=&i;
  f.lChild=&e;
  g.rChild=&h;
  postOrderTraversal(&a);
}
int main(){
  createBTree1();
  cout<<"================================"<<endl;
  createBTree2();
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

