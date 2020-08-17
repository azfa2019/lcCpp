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
    vector<vector<int>> fourSum(vector<int> num,int target){
      vector<vector<int>> ans;
      sort(num.begin(),num.end());
      for(int i=0;i<num.size()-3;i++){
        //if(i!=0&&num[i]==num[i-1]) continue;
        while(i>0&&num[i]==num[i-1]) i++;
        for(int j=i+1;j<num.size()-2;j++){
          //if(j!=i+1&&num[j]==num[j-1]) continue;
          while(j>i+1&&num[j]==num[j-1]) j++;
          int l=j+1,r=num.size()-1;
          while(l<r){
            int sum=num[i]+num[j]+num[l]+num[r];
            if(sum==target){
              ans.push_back(initializer_list<int>{num[i],num[j],num[l],num[r]});
              l++; r--;
              while(l+1<r&&num[l]==num[l-1]) l++;
              while(r-1>l&&num[r]==num[r+1]) r--;
              //l++; r--;
            }else if(sum<target) l++;
            else r--;
          }
        }
      }
      return ans;
    }
};
int main(){
  vector<int> num{1,0,-1,0,-2,2};
  int target =0;
  solution s0;
  auto ans=s0.fourSum(num,target);
  for(auto e:ans) cout<<e[0]<<", "<<e[1]<<", "<<e[2]<<", "<<e[3]<<", "<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

