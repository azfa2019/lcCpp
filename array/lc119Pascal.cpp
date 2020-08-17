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
    vector<int> pascal(int rowIndex){
      vector<int> res(rowIndex+1,0);
      res[0]=1;
      for(int i=1;i<rowIndex+1;i++)
        for(int j=i;j>0;j--)
          res[j]+=res[j-1];
      return res;
    }
};
int main(){
  solution s0;
  auto ans=s0.pascal(3);
  showVector(ans);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

