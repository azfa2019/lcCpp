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

class Solution{
  public:
    bool parse(const string& ex,int& s){
      char ch=ex[s++];
      if(ch=='t') return true;
      if(ch=='f') return false;
      if(ch=='!'){
        bool ans= !parse(ex,++s);
        ++s;
        return ans;
      }
      bool isAnd=ch=='&';
      bool ans=isAnd;
      s++;
      while(true){
        if(ch=='&') ans&=parse(ex,s);
        else ans|=parse(ex,s);
        if(ex[s++]==')') break;
      }
      return ans;
    }
    bool parse2(const string& ex,int& s){
      bool ans; 
      char ch=ex[s];
      s++;
      if (ch=='t'){return true;}
      if (ch=='f'){return false;}
      if(ch=='!'){s++;ans=!parse2(ex,s);s++; return ans;}
      s++;
      if(ch=='&'){
        ans=true;
        while(true){
          ans=ans & parse2(ex,s);
          if(ex[s++]==')') break;
        }
      }
      if(ch=='|'){
        ans=false;
        while(true){
          ans=ans | parse2(ex,s);
          if(ex[s++]==')') break;
        }
      }
      return ans;
    }
};
int main(){
  //vector<string> s{"!(f)","|(f,t)","&(t,f)","&(t,f)"};
  //vector<string> s{"|(f,t)"};
  vector<string> s{"|(&(t,f,t),!(t))"};
  Solution s0;
  for (auto it=s.begin();it!=s.end();++it){
    int s=0;
    bool ans=s0.parse2(*it,s);
    cout<<ans<<endl;
  }
  //int s=0;
  //bool ans=s0.parse(ex,s);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

