#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
using namespace std;

int main(){
  queue <int> q;
  q.push(100);
  q.push(200);
  q.push(300);
  q.push(400);
  cout<<q.front()<<endl;
  cout<<q.back()<<endl;
  cout<<"===================="<<endl;
  q.pop();
  cout<<q.front()<<endl;
  cout<<q.back()<<endl;
  cout<<"===================="<<endl;
  cout<<q.front()<<endl;
  cout<<"===================="<<endl;
  
  return 0;
}

