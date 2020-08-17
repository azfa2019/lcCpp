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
  vector<int> target{2,8,12};
  priority_queue<int> q(target.begin(),target.end());
  cout<<q.top()<<endl;
  int sum=accumulate(begin(target),end(target),0);
  cout<<sum<<endl;
  cout<<"================================"<<endl;
  bool b1=true;
  bool b2=false;
  bool b3=b1&b2;
  cout<<!b3<<endl;
  cout<<"================================"<<endl;
  string s{"test"};
  char c=s[1];
  cout<<c<<endl;
  cout<<"================================"<<endl;
  int i = 1<<3;
  cout<<i<<endl;
  cout<<"================================"<<endl;
  return 0;
}

