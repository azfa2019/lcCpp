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
using namespace std;
  template<typename T>
void showVector(vector<T> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << *it<<" "; //'\t' ; 
    cout << '\n'; 
} 
class solution{
  public:
};

class TreeNode{
  public:
    int val;
    TreeNode* lChild;
    TreeNode* rChild;
    TreeNode(int x):val(x),lChild(nullptr),rChild(nullptr){};
};
struct A{
  char a;
  char b;
};
int main(){
  solution s0;
  string data{"1 2 3"};
  istringstream ss(data);
  cout<<ss.str()<<"end"<<endl;
  string text;
  ss>>text;
  cout<<text<<"end"<<endl;
  ss>>text;
  cout<<text<<"end"<<endl;
  cout<<"================================"<<endl;
  cout<<stoi(text)<<endl;
  cout<<"================================"<<endl;
  TreeNode* n1=new TreeNode(1);
  cout<<n1->val<<endl;
  cout<<"================================"<<endl;
  int root=0x1;
  int test=0x1;
  cout<<!(test&root)<<endl;
  cout<<"================================"<<endl;
  short v=25185;
  A a=*reinterpret_cast<A*>(&v);
  cout<<a.a<<" "<<a.b<<endl;
  return 0;
}

