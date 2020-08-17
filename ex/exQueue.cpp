#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int main(){
  //stack<int> ex1;
  priority_queue<int,vector<int>,std::greater<int>> ex1;
  ex1.push(500);
  ex1.push(200);
  ex1.push(300);
  while(!ex1.empty()){
    cout<<ex1.top()<<endl;
    //cout<<ex1.back()<<endl;
    ex1.pop();
  }
  //////////////////////////////////////////////////
  cout<<"//////////////////////////////////////////////////"<<endl;
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  cout<<q.empty()<<endl;
  cout<<q.size()<<endl;
  return 0;
}
