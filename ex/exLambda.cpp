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
  vector<string> words{"phone","mouse","book","toy","tv"};
  auto it=find(words.begin(),words.end(),"toy");
  cout<<*it<<endl;
  cout<<"================================"<<endl;
  sort(words.begin(),words.end(),[](const string& s1,const string& s2){return s1.size()<s2.size();});
  for(const auto& e:words){
    cout<<e<<endl;
  }
  cout<<"================================"<<endl;
  int sz=3;
  auto it1=find_if(words.begin(),words.end(),[sz](const string& s){return s.size()>sz;});
  auto wc=words.end()-it1;
  cout<<wc<<endl;
  cout<<wc<<((wc>1)?" words":" word")<<" longer than "<<sz<<endl;
  cout<<"================================"<<endl;
  for_each(it1,words.end(),[](const string& w){cout<<w<<endl;});
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

