#include"array.h"
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
const int BLOCK_SIZE=2;
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
};
//typedef struct{
//  int *array;
//  int size;
//} Array;

Array array_create(int init_size){
  Array a;
  a.size=init_size;
  a.array=(int*)malloc(sizeof(int)*a.size);
  return a;
};

void array_free(Array *a){
  free(a->array);
  a->array=nullptr;
  a->size=0;
};
int array_size(const Array *a){
  return a->size;
};
int* array_at(Array *a, int index){
  if(index>=a->size) array_inflate(a,(index/BLOCK_SIZE+1)*BLOCK_SIZE-a->size);
  return &(a->array[index]);
};
int array_get(const Array *a, int index){
  return a->array[index];
}
void array_set(Array *a, int index,int val){
  a->array[index]=val;
}
void array_inflate(Array *a, int more_size){
  int *p=(int*)malloc(sizeof(int)*(a->size+more_size));
  for (int i=0;i<a->size;++i){
    p[i]=a->array[i];
  }
  free(a->array);
  a->array=p;
  a->size+=more_size;
};
int main(){
  Solution0 s0;
  Array a=array_create(3);
  cout<<array_size(&a)<<endl;
  *array_at(&a,0)=15;
  cout<<*array_at(&a,0)<<endl;
  //array_free(&a);
  int number;
  int cnt=0;
  while(number!=-1){
    cout<<"type a number: ";
    cin>>number;
    if(number!=-1) *array_at(&a,cnt++)=number;
  }
  cout<<array_size(&a)<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  cout<<"================================"<<endl;
  return 0;
}

