#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
#include<climits>
#include<sstream>
#include<string>
using namespace std;
template<typename T>
void showVector(vector<T> g) 
{ 
    for (auto it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
class solution{
public:
};
int main(){
  solution s0;
  string s1{"012"};
  int i=0;
  while(true){
    if (s1[i++]=='0') break;
  }
  cout<<i<<endl;
  cout<<"================================"<<endl;
  char c=-1;
  auto ans=c?"yes":"no";
  cout<<ans<<endl;
  if(c)cout<<"hello"<<endl;
  cout<<"================================"<<endl;
  string s2;
  s2="hello";
  cout<<s2<<endl;
  cout<<sizeof(s2)<<endl;
  cout<<s2.length()<<endl;
  cout<<s2.size()<<endl;
  cout<<"================================"<<endl;
  vector<int> v1{1,2,3,4};
  cout<<*max_element(v1.begin(),v1.begin()+2)<<endl;;
  cout<<"================================"<<endl;
  string secret{"1807"};
  vector<int> cnt(10,0);
  cout<<secret[3]-'0'<<endl;
  cout<<"================================"<<endl;
  cnt.insert(cnt.begin(),5);
  cout<<cnt[0]<<endl;
  cout<<"================================"<<endl;
  string a="hello";
  int count=2;
  if(a=="hello"&&++count>1) cout<<count<<endl;
  cout<<count<<endl;
  cout<<"================================"<<endl;
  cout<<INT_MIN<<endl;
  cout<<"================================"<<endl;
  string s;
  int i3=10,i4=5;
  int i0;
  ostringstream out;
  out.write(reinterpret_cast<char*>(&i3),sizeof(i3));
  out.write(reinterpret_cast<char*>(&i4),sizeof(i4));
  cout<<out.str()<<endl;
  cout<<(out.str()).size()<<endl;
  istringstream in(out.str());
  int val;
  in.read(reinterpret_cast<char*>(&val),sizeof(val));
  cout<<val<<endl;
  cout<<"================================"<<endl;
  int val1;
  in.read(reinterpret_cast<char*>(&val1),sizeof(val));
  cout<<val1<<endl;
  int val3;
  in.read(reinterpret_cast<char*>(&val3),sizeof(val));
  cout<<val3<<endl;
  cout<<"================================"<<endl;
  return 0;
}

