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
        cout << '\t' << *it; 
    cout << '\n'; 
} 
class solution{
public:
  int findCelebrity(vector<vector<int>> knows,int n) {
    int x=0,y=n-1;
    while(x<y){
      if(knows[x][y]) x++;
      else y--;
    }
    for(int i=0;i<n;i++){
      if(x!=i&&(knows[x][i]||!knows[i][x])) return -1;
    }
    return 1;
  }
};
int main(){
  solution s0;
  vector<vector<vector<int>>> knows{{{1,1,0},{0,1,0},{1,1,1}},{{1,0,1},{1,1,0},{0,1,1}}};
  for (auto e:knows) cout<<s0.findCelebrity(e,3)<<" ";
  cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

