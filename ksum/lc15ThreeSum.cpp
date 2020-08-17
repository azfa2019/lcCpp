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
    vector<vector<int>> threeSum(vector<int> num){
      sort(num.begin(),num.end());
      //for(int i:num) cout<<i<<endl;
      int i=0;
      vector<vector<int>> ans;
      while(i<num.size()-2){
        int l=i+1,r=num.size()-1;
        while(l<r){
          int sum=num[i]+num[l]+num[r];
          if (sum==0){
            vector<int> a{num[i],num[l],num[r]};
            ans.push_back(a);
            l=moveRight(num,l);
            r=moveLeft(num,r);
          } else if (sum<0) l=moveRight(num,l);
          else r=moveLeft(num,r);
        }
        i=moveRight(num,i);
      }
      return ans;
    }
    int moveRight(vector<int> num,int l){
      while(num[l]==num[l+1]&&l<num.size()-2) l++;
      return l+1;
    }
    int moveLeft(vector<int> num,int r){
      while(num[r]==num[r-1]&&r>1) r--;
      return r-1;
    }

};

int main(){
  vector<int> num{-1,-1,0,1,2,-4,-4};
  solution s0;
  //int l=s0.moveRight(num,0);
  //int r=s0.moveLeft(num,6);
  //cout<<r<<endl;

  auto ans=s0.threeSum(num);
  for(auto e:ans) cout<<e[0]<<","<<e[1]<<","<<e[2]<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

