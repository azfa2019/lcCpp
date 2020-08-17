#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>

using namespace std;

int main(){
  stack<int> s;
  s.push(100);
  s.push(200);
  s.push(300);
  cout<<s.top()<<endl;
  s.pop();
  cout<<s.top()<<endl;

  return 0;
}

