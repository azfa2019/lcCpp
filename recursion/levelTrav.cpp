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

struct bNode{
  char value;
  bNode* lChild;
  bNode* rChild;
};
typedef bNode bNode;
void levelTraversal(bNode* root){
  queue<bNode*> q;
  bNode* node;
  q.push(root);
  while(!q.empty()){
    node=q.front();
    q.pop();
    cout<<node->value<<endl;
    if(node->lChild!=NULL) q.push(node->lChild);
    if(node->rChild!=NULL) q.push(node->rChild);
  }
}
int postOrderGetHeight(bNode* root){
  int hl,hr,maxH;
  if(root!=NULL){
    hl=postOrderGetHeight(root->lChild);
    hr=postOrderGetHeight(root->rChild);
    maxH=(hl>hr)?hl:hr;
    return (maxH+1);
  } else return 0;
}
void createBTree(){
  bNode a{'A',NULL,NULL};
  bNode b{'B',NULL,NULL};
  bNode c{'C',NULL,NULL};
  bNode d{'D',NULL,NULL};
  bNode e{'E',NULL,NULL};
  bNode f{'F',NULL,NULL};
  bNode g{'G',NULL,NULL};
  bNode h{'H',NULL,NULL};
  bNode i{'I',NULL,NULL};
  a.lChild=&b;
  a.rChild=&c;
  b.lChild=&d;
  b.rChild=&f;
  c.lChild=&g;
  c.rChild=&i;
  f.lChild=&e;
  g.rChild=&h;
  levelTraversal(&a);
  cout<<postOrderGetHeight(&a)<<endl;
}
int main(){
  createBTree();
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

