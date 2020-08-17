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
  template<typename T>
void showVector(vector<T> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << *it<<" "; //'\t' ; 
    cout << '\n'; 
} 
class solution{
  public:
    string bullsCows(string secret,string guess){
      int bulls=0,cows=0;
      vector<int> number(10,0);
      for(int i=0;i<secret.size();i++){
        if(secret[i]==guess[i]) bulls++;
        else{
          if(number[secret[i]]++<0) cows++;
          if(number[guess[i]]-->0) cows++;
        }
      }
      return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
int main(){
  solution s0;
  vector<pair<string,string>> s{{"1807","7810"},{"1123","0111"}};
  for(auto e:s) {
    string ans=s0.bullsCows(e.first,e.second);
    cout<<ans<<endl;
  }
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

