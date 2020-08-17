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

int main(){
  string exp0="(let x 2 (mult x 5))";
  string exp="(let x 2 (add (let x 3 (let x 4 x)) x))";
  stack<int> s;
  for (int i=0;i<exp.size();i++) {
    if (exp[i]=='(') s.push(i);
    else if (exp[i]==')') {
      cout<<"( at: "<<s.top()<<", ) at:"<<i<<endl;
      s.pop();
    }
  }
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

