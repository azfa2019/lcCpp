#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;

int main(){
  int i=42,*p=&i;
  int j=10;
  decltype(*p) c=j;
  cout<<c<<endl;

  return 0;
}

