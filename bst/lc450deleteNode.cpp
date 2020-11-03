#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
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
struct TreeNode{
  int val;
  TreeNode *left,*right;
  TreeNode(int val):val(val),left(nullptr),right(nullptr){};
};
class Solution0{
  public:
    TreeNode *deleteNode(TreeNode *root,int key){
      if(!root) return nullptr;
      if(key<root->val) root->left=deleteNode(root->left,key);
      else if(key>root->val) root->right=deleteNode(root->right,key);
      else{
        TreeNode *newRoot=nullptr;
        if(!root->left) newRoot=root->right;
        else if(!root->right) newRoot=root->left;
        else{
          TreeNode *parent=root;
          newRoot=root->right;
          while(newRoot->left){
            parent=newRoot;
            newRoot=newRoot->left;
          }
          if(parent!=root){
            parent->left=newRoot->right;
            newRoot->right=root->right;
          }
          newRoot->left=root->left;
        }
        root=nullptr;
        delete root;
        return newRoot;
      }
      return root;
    }
};
class Solution1{
  public:
    TreeNode *deleteNode(TreeNode *root,int key){
      if(!root) return nullptr;
      if(key<root->val) root->left=deleteNode(root->left,key);
      else if(key>root->val) root->right=deleteNode(root->right,key);
      else {
        if(root->left&&root->right){
          TreeNode *min=root->right;
          while(min->left) min=min->left;
          root->val=min->val;
          root->right=deleteNode(root->right,min->val);
        }
        else{
          TreeNode *newRoot=root->left?root->left:root->right;
          root->left=root->right=nullptr;
          root=nullptr;
          delete root;
          return newRoot;
        }
      }
      return root;
    }
};
void printTree(TreeNode *root){
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()){
    auto node=q.front();q.pop();
    cout<<node->val<<" ";
    if(node->left) q.push(node->left);
    if(node->right) q.push(node->right);
  }
  cout<<endl;
}
int main(){
  Solution0 s0;
  TreeNode n0(8),n1(3),n2(9),n3(2),n4(6),n5(10),n6(4),n7(7),n8(5);
  n0.left=&n1,n0.right=&n2,n1.left=&n3,n1.right=&n4,n2.right=&n5,n4.left=&n6,n4.right=&n7,n6.right=&n8;
  printTree(&n0);
  auto ans0=s0.deleteNode(&n0,3);
  printTree(ans0);
  //TreeNode p0(5),p1(3),p2(6),p3(2),p4(4),p5(7);
  //p0.left=&p1,p0.right=&p2,p1.left=&p3,p1.right=&p4,p2.right=&p5;
  //printTree(&p0);
  //auto ans01=s0.deleteNode(&p0,3);
  //printTree(ans01);
  cout<<"================================"<<endl;
  Solution1 s1;
  TreeNode p0(8),p1(3),p2(9),p3(2),p4(6),p5(10),p6(4),p7(7),p8(5);
  p0.left=&p1,p0.right=&p2,p1.left=&p3,p1.right=&p4,p2.right=&p5,p4.left=&p6,p4.right=&p7,p6.right=&p8;
  printTree(&p0);
  auto ans1=s1.deleteNode(&p0,3);
  printTree(ans1);
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

