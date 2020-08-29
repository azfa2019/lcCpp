#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include <numeric>
#include<climits>
#include<sstream>
using namespace std;
  template<typename T>
void showVector(vector<T> g) 
{ 
  for (auto it = g.begin(); it != g.end(); ++it) 
    cout << *it<<" "; //'\t' ; 
  cout << '\n'; 
} 
class TreeNode{
  public:
    int val;
    TreeNode* lChild;
    TreeNode* rChild;
    TreeNode(int x):val(x),lChild(nullptr),rChild(nullptr){};
};
void printTree(TreeNode* root){
  if(!root) {
    cout<<"null ";
    return;
  }
  if(!root->lChild && !root->rChild) cout<<root->val<<" ";
  else{
    cout<<root->val<<" ";
    printTree(root->lChild);
    printTree(root->rChild);
  }
}
class solution{
  public:
    string serial(TreeNode* root){
      string s;
      serialHelper(root,s);
      return s;
    }
    TreeNode* deserial(string data){
      int pos=0;
      return deserialHelper(data,pos,INT_MIN,INT_MAX);
    }
  private:
    void serialHelper(TreeNode* root,string& s){
      if(!root) return;
      s.append(reinterpret_cast<char*>(&(root->val)),sizeof(root->val));
      serialHelper(root->lChild,s);
      serialHelper(root->rChild,s);
    }
    TreeNode* deserialHelper(string& s,int& pos,int curMin,int curMax){
      if(pos>=s.size()) return nullptr;
      int val=*reinterpret_cast<const int*>(s.data()+pos);
      if(val<curMin||val>curMax) return nullptr;
      pos+=sizeof(val);
      TreeNode* root=new TreeNode(val);
      root->lChild=deserialHelper(s,pos,curMin,val);
      root->rChild=deserialHelper(s,pos,val,curMax);
      return root;
    }
};
int main(){
  solution s0;
  TreeNode* n1=new TreeNode(1);
  TreeNode* n2=new TreeNode(2);
  TreeNode* n4=new TreeNode(4);
  TreeNode* n3=new TreeNode(3);
  TreeNode* n5=new TreeNode(5);
  TreeNode* n6=new TreeNode(6);
  TreeNode* n8=new TreeNode(8);
  n5->lChild=n2;
  n5->rChild=n6;
  n2->lChild=n1;
  n2->rChild=n4;
  n6->rChild=n8;
  printTree(n5); cout<<endl;
  string ans01=s0.serial(n5);
  cout<<ans01<<endl;
  cout<<"================================"<<endl;
  auto ans02=s0.deserial(ans01);
  printTree(ans02); cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

