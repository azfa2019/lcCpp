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
#include<string>
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
      ostringstream s;
      serialHelper(root,s);
      return s.str();
    }
    TreeNode* deserial(string data){
      istringstream s(data);
      return deserialHelper(s,INT_MIN,INT_MAX);
    }
  private:
    void serialHelper(TreeNode* root,ostringstream& s){
      if(!root) return;
      s.write(reinterpret_cast<char*>(&(root->val)),sizeof(root->val));
      if(root->lChild) serialHelper(root->lChild,s);
      if(root->rChild) serialHelper(root->rChild,s);
    }
    //void serialHelper0(TreeNode* root,ostringstream& out){
    //  char status=ROOT_NULL;
    //  if(root) status|=ROOT;
    //  if(root&&(root->lChild)) status|=LEFT;
    //  if(root&&(root->rChild)) status|=RIGHT;
    //  out.write(&status,sizeof(char));
    //  if(!root) return;
    //  out.write(reinterpret_cast<char*>(&(root->val)),sizeof(root->val));
    //  if(root->lChild) serialHelper(root->lChild,out);
    //  if(root->rChild) serialHelper(root->rChild,out);
    //}
    TreeNode* deserialHelper( istringstream& s,int curMin,int curMax){
      int val;
      s.read(reinterpret_cast<char*>(&val),sizeof(val));
      cout<<"read"<<endl;
      cout<<"val="<<val<<endl;
      if(val<curMin||val>curMax) return nullptr;
      //cout<<"sizeof="<<sizeof(val)<<endl;
      TreeNode* root=new TreeNode(val);
      root->lChild=deserialHelper(s,curMin,val);
      root->rChild=deserialHelper(s,val,curMax);
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
  //n1->rChild=n3;
  //n3->lChild=n4;
  //n3->rChild=n5;
  printTree(n1); cout<<endl;
  string ans01=s0.serial(n1);
  cout<<ans01<<endl;
  cout<<"string size():"<<ans01.size()<<endl;
  int i0=*reinterpret_cast<int*>(ans01.data());
  cout<<"first number="<<i0<<endl;
  int i1=*reinterpret_cast<int*>(ans01.data()+4);
  cout<<"second number="<<i1<<endl;
  auto ans02=s0.deserial(ans01);
  printTree(ans02); cout<<endl;
  cout<<"================================"<<endl;
  //if(ans02->lChild==nullptr) cout<<"empty"<<endl;
  //else cout<<"not empty"<<endl;
  //if(ans02->rChild==nullptr) cout<<"empty"<<endl;
  //else cout<<"not empty"<<endl;
  //cout<<ans02->val<<endl;
  //cout<<(ans02->lChild->val)<<endl;
  //cout<<ans02->rChild->val<<endl;
  cout<<"================================"<<endl;
  //char s='a';
  //cout<<sizeof(s)<<endl;
  //int i0=1;
  //cout<<sizeof(i0)<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

