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
typedef struct node{
  int val;
  node *next;
} Node;

class Solution0{
  public:
};
int main(){
  Solution0 s0;
  Node *head=nullptr;
  Node *p=new Node;
  vector<int> v0{1,2,3};
  for(auto e:v0){
    p->val=e;
    p->next=nullptr;
  }
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

