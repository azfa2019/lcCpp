#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
  vector<int> dp(5,3);
  cout<<dp[2]<<endl;
  cout<<"================================"<<endl;
  vector<vector<int>> v2{{1,2},{3,4}};
  cout<<v2[1][0]<<endl;
  cout<<"================================"<<endl;
  vector<int> v3{1,9,2,6,3};
  sort(v3.begin(),v3.end());
  set<int> s3(v3.begin(),v3.end());
  for(auto e:s3) cout<<e<<" "; cout<<endl;
  for(auto it=s3.begin();it!=s3.end();++it) cout<<*it<<" ";
  cout<<endl;
  cout<<*s3.begin()<<endl;
  cout<<*s3.end()-1<<endl;
  auto it=find(v3.begin(),v3.end(),1);
  cout<<(it-v3.begin())<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

