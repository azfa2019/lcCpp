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
  short v=13;
  short mask=1<<1;
  cout<<mask<<endl;
  if((mask & v)!=0) cout<<1<<endl;
  else cout<<0<<endl;
  char c='a';
  if((c & 0b00100000)==0) cout<<"upper case"<<endl;
  else if((c& 0b00100000)==0b00100000) cout<<"lower case"<<endl;
  cout<<"================================"<<endl;
  if((c & 0x20)==0) cout<<"upper case"<<endl;
  else if((c & 0x20)==0x20) cout<<"lower case"<<endl;
  cout<<"================================"<<endl;
  vector<char> v0(3,'a');
  vector<char> v1(1<<3,'a');
  for(auto it=v1.begin();it!=v1.end();++it)
  cout<<*it<<endl;
  cout<<"================================"<<endl;
  vector<char> m(1<<3,0);
  auto a=(m[0]==1);
  auto b=(m[0]=1);
  cout<<a<<endl;
  cout<<b<<endl;
  cout<<m[0]<<endl;
  cout<<"================================"<<endl;
  cout<<(1<<3)<<endl;
  cout<<(100>>2)<<endl;
  cout<<"================================"<<endl;
  cout<<(8|1<<1)<<endl;
  return 0;
}

