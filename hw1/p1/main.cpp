#include<iostream>
using namespace std;

namespace oop {
  namespace scope1 {
    void print( int n ){
      cout << "print int" << endl;
    }

    void print( double n ){
      cout << "print double" << endl;
    }
  };
  namespace scope2 {
    void print( double i ){
      cout << "print2 double" << endl;
    }
    void print( int i , double j ){
      cout << "print int and double" << endl;
    }

    void print( double i , int j ){
      cout << "print double and int" << endl;
    }
  };
  namespace scope3 {
    void print( const int &i ){
      cout << "print const &int" << endl;
    }
    void print( int &i ){
      cout << "print &int" << endl;
    }
  };
};

int main(){
    int x=1;
    oop::scope1::print(1);
    oop::scope1::print(1.1);
    oop::scope2::print(1,1.1);
    oop::scope2::print(1.1,1);
    oop::scope2::print(1.1);
    oop::scope3::print(1);
    oop::scope3::print(x);
    return 0;



}

