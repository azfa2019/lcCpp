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
      ostringstream out;
      serialHelper(root,out);
      return out.str();
    }
    TreeNode* deserial(string data){
      istringstream in(data);
      return deserialHelper(in);
    }
  private:
    void serialHelper(TreeNode* root,ostringstream& out){
      if(!root) {
        out<<"# ";
        return;
      }
      out<<root->val<<" ";
      serialHelper(root->lChild,out);
      serialHelper(root->rChild,out);
    }
    TreeNode* deserialHelper(istringstream& in){
      string val;
      in>>val;
      if(val=="#") return nullptr;
      TreeNode* root=new TreeNode(stoi(val));
      root->lChild=deserialHelper(in);
      root->rChild=deserialHelper(in);
      return root;
    }
};
class solution2{
  public:
    string serial(TreeNode* root){
      ostringstream out;
      serialHelper(root,out);
      return out.str();
    }
    TreeNode* deserial(string data){
      istringstream in(data);
      return deserialHelper(in);
    }
  private:
    enum STATUS{
      ROOT_NULL=0x0,
      ROOT=0x1,
      LEFT=0x2,
      RIGHT=0x4
    };
    void serialHelper(TreeNode* root,ostringstream& out){
      char status=ROOT_NULL;
      if(root) status|=ROOT;
      if(root&&(root->lChild)) status|=LEFT;
      if(root&&(root->rChild)) status|=RIGHT;
      out.write(&status,sizeof(char));
      if(!root) return;
      out.write(reinterpret_cast<char*>(&(root->val)),sizeof(root->val));
      if(root->lChild) serialHelper(root->lChild,out);
      if(root->rChild) serialHelper(root->rChild,out);
    }
    TreeNode* deserialHelper(istringstream& in){
      char status;
      in.read(&status,sizeof(char));
      if(!status&ROOT) return nullptr;
      TreeNode* root=new TreeNode(0);
      in.read(reinterpret_cast<char*>(&(root->val)),sizeof(root->val));
      root->lChild=(status&LEFT)?deserialHelper(in):nullptr;
      root->rChild=(status&RIGHT)?deserialHelper(in):nullptr;
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
  n1->lChild=n2;
  n1->rChild=n3;
  n3->lChild=n4;
  n3->rChild=n5;
  printTree(n1); cout<<endl;
  //TreeNode* ans=s0.trim0(n3,1,3);
  auto ans01=s0.serial(n1);
  cout<<ans01<<endl;
  auto ans02=s0.deserial(ans01);
  printTree(ans02); cout<<endl;
  cout<<"================================"<<endl;
  solution2 s2;
  auto ans21=s2.serial(n1);
  cout<<ans21<<endl;
  auto ans22=s2.deserial(ans21);
  printTree(ans22); cout<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

