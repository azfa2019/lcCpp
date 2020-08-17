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
  bool canWin(int M,int T){
    m=vector<char>(1<<M,0);
    int sum=(M+1)*M/2;
    if(sum<=T) return false;
    if(T<0) return true;
    return canWin(M,T,0);
  }
 private:
  vector<char> m;
  bool canWin(int M,int T,int state){
    if(T<=0) return false;
    if(m[state]) return m[state]==1?true:false;
    for(int i=0;i<M;i++){
      if(state&(1<<i)) continue;
      if(!canWin(M,T-(i+1),state|(1<<i))){
        m[state]=1;
        return true;
      }
    }
    m[state]=-1;
    return false;
  }
};
int main(){
  Solution s0;
  cout<<(s0.canWin(10,13)?"Won":"Lost")<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

