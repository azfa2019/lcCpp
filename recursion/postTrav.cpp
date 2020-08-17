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
  enum {L,R}tag;
};
typedef bNode bNode;
void postOrderTraversal(bNode* root){
  stack<bNode*> s;
  bNode* node=root;
  while(node!=NULL||!s.empty()){
    while(node!=NULL){
      s.push(node);
      node=node->lChild;
    }
    if(!s.empty()){
      node=s.top();
      s.pop();
      if(node->tag==bNode::L){
        node->tag=bNode::R;
        s.push(node);
        node=node->rChild;
      } else if(node->tag==bNode::R){
        cout<<node->value<<endl;
        node=NULL;//so we can avoid pushing it to stack, and can pop another element from stack
      }
    }
  }
}
void createBTree(){
  bNode a{'A',NULL,NULL,bNode::L};
  bNode b{'B',NULL,NULL,bNode::L};
  bNode c{'C',NULL,NULL,bNode::L};
  bNode d{'D',NULL,NULL,bNode::L};
  bNode e{'E',NULL,NULL,bNode::L};
  bNode f{'F',NULL,NULL,bNode::L};
  bNode g{'G',NULL,NULL,bNode::L};
  bNode h{'H',NULL,NULL,bNode::L};
  bNode i{'I',NULL,NULL,bNode::L};
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
  createBTree();
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

