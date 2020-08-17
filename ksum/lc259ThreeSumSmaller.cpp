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
class solution{
  public:
    int threeSumSmaller(vector<int> num,int target){
      sort(num.begin(),num.end());
      int ans=0;
      for(int i=0;i<num.size()-2;i++){
        int l=i+1,r=num.size()-1;
        while(l<r){
          if (num[i]+num[l]+num[r]<target) {
            ans+=r-l;
            l++;
          } else r--;
        }
      }
      return ans;
    }
};
int main(){
  vector<int> num{-2,0,1,3};
  int target=2;
  solution s0;
  int ans=s0.threeSumSmaller(num,target);
  cout<<ans<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

