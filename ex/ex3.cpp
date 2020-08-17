#include <iostream>
using namespace std;
class Book{
 public:
  string title;
  string author;
  int pages;
  Book(){
    title="default name";
    author="no author";
    pages=100;
  };
  Book(string aTitle,string aAuthor,int numPages){
    title=aTitle;
    author=aAuthor;
    pages=numPages;
    cout<<"a book"<<endl;
  };
};
int main(){

  Book book1("test","me",10);
  book1.title="harry potter";
  book1.author="jk";
  book1.pages=500;
  cout<<book1.title<<endl;
  Book book2;
  cout<<book2.title<<endl;
  return 0;
}
