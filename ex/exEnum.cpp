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

struct bnode{
  char value;
  bnode* lChild;
  bnode* rChild;
  enum{L,R,M}tag;
};
typedef bnode bnode;
int main(){
  bnode a{'A',NULL,NULL,bnode::L};
  bnode b{'B',NULL,NULL,bnode::R};
  bnode c{'C',NULL,NULL,bnode::M};
  a.lChild=&b;
  a.rChild=&b;
  cout<<a.tag<<endl;
  cout<<c.tag<<endl;
  cout<<b.tag<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

