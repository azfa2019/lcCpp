#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <memory>
using namespace std;
  template<typename T>
void showVector(vector<T> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << *it<<" "; //'\t' ; 
  cout << '\n'; 
} 
class Solution0{
  public:
    vector<vector<int>> floodFill(vector<vector<int>>&image,int sr,int sc,int newColor){
      if(image[sr][sc]==newColor) return image;
      int m=image.size(),n=image[0].size();
      floodFill(image,sr,sc,m,n,image[sr][sc],newColor);
      return image;
    }
    void floodFill(vector<vector<int>>&image,int sr,int sc,int m,int n,int oldColor,int newColor){
      if(sr<0||sr>=m||sc<0||sc>=n) return;
      if(image[sr][sc]!=oldColor) return;
      image[sr][sc]=newColor;
      floodFill(image,sr-1,sc,m,n,oldColor,newColor);
      floodFill(image,sr+1,sc,m,n,oldColor,newColor);
      floodFill(image,sr,sc-1,m,n,oldColor,newColor);
      floodFill(image,sr,sc+1,m,n,oldColor,newColor);
    }
};
int main(){
  Solution0 s0;
  vector<vector<int>>image{{1,1,1},{1,1,0},{1,0,1}};
  int sr=1,sc=1,newColor=2;
  auto ans0=s0.floodFill(image,sr,sc,newColor);
  for(auto e:image) showVector(e);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

