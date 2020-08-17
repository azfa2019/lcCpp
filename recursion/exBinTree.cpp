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

struct BiTNode{
  int data;
  struct BiTNode *lchild,*rchild;
};
typedef struct BiTNode BiTNode;
//BiTree is a pointer type
typedef struct BiTNode* BiTree;

int main(){
  BiTNode *p1,*p2,*p3,*p4,*p5;
  p1=(BiTNode*)malloc(sizeof(BiTNode));
  p2=(BiTNode*)malloc(sizeof(BiTNode));
  p3=(BiTNode*)malloc(sizeof(BiTNode));
  p4=(BiTNode*)malloc(sizeof(BiTNode));
  p5=(BiTNode*)malloc(sizeof(BiTNode));

  p1->data=1;
  p2->data=2;
  p3->data=3;
  p4->data=4;
  p5->data=5;
  //build relationship
  p1->lchild=p2;
  p1->rchild=p3;
  p2->lchild=p4;
  p3->lchild=p5;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}
int main01(){
  BiTNode t1,t2,t3,t4,t5;
  t1.data=1;
  t2.data=2;
  t3.data=3;
  t4.data=4;
  t5.data=5;
  //build relationship
  t1.lchild=&t2;
  t1.rchild=&t3;
  t2.lchild=&t4;
  t3.lchild=&t5;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

