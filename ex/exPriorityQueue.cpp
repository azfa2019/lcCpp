#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;

int main(){
  priority_queue<int> q;
  //priority_queue<int,vector<int>,greater<int>> q;
  q.push(500);
  q.push(200);
  q.push(900);
  q.push(100);
  cout<<q.top()<<endl;
  q.pop();
  cout<<q.top()<<endl;
  cout<<"========================================"<<endl;
  priority_queue<int,vector<int>,greater<int>> q1;
  q1.push(500);
  q1.push(200);
  q1.push(900);
  q1.push(100);
  cout<<q1.top()<<endl;
  cout<<"========================================"<<endl;
  while(!q1.empty()){
    cout<<q1.top()<<endl;
    q1.pop();
  }
  cout<<"========================================"<<endl;
  priority_queue<string,vector<string>,less<string>> q2;
  //priority_queue<string> q2;
  q2.push("i");
  q2.push("love");
  q2.push("a");
  while(!q2.empty()){
    cout<<q2.top()<<endl;
    q2.pop();
  }
  cout<<"========================================"<<endl;
  priority_queue<string> s2;
  s2.push("a");
  s2.push("b");
  s2.push("c");
  while(!s2.empty()){
    cout<<s2.top()<<endl;
    s2.pop();
  }


  return 0;
}

