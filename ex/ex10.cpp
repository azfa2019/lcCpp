#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
int main(){
  vector<vector<int>> x{{1,2,3}};
  cout<<x[0][1]<<endl;
  set <int> s{1,2,3,4,5};
  for(int x:s) cout<<x<<endl;

  map <string,int> m{{"tom",1},{"dave",2}};
  for (auto&& a1:m) {
    a1.second=3;
    cout<<a1.first<<endl;
    cout<<a1.second<<endl;
  }  
  vector<pair<int,int>> v{{1,2},{3,4}};
  sort(begin(v),end(v),
       [](const auto& a, const auto& b){
         return a.second<b.second;
       });
  return 0;
}
