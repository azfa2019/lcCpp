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

void postOTravRecur(BNode* bt){
  //cout<<bt.value<<endl;
  //cout<<bt.lChild->value<<endl;
  if(bt==NULL) return;
  postOTravRecur(bt->lChild);
  postOTravRecur(bt->rChild);
  cout<<bt->value<<endl;
  return;
}
void recursion(BNode* root){
  if(root==NULL){
    return;
  }
  recursion(root->lChild);
  recursion(root->rChild);
  cout<<root->value<<endl;
  return;
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
  recursion(&node1);
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
  postOTravRecur(&a);
}
int main(){
  createBTree1();
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

