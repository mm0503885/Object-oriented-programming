#include<iostream>
#include<string>
#include"oop_string.h"
#include<algorithm>
#include<functional>
using namespace std;
namespace oop{
  void reverse( std::string &str)
  {
      int i=0,j=str.length()-1;
      char ex;
      while(i<=j)
      {
          ex=str[i];
          str[i]=str[j];
          str[j]=ex;
          i++;
          j--;
      }
  }
  void toUpperCase( std::string &str)
  {
      for(int i=0;i<str.length();i++)
      {
          if(97<=str[i] && str[i]<=122)
          str[i]-=32;
      }
  }
  void trim( std::string &str)
  {
      int i=0;
      while(str[i]==' ')
      {
       i++;
      }
      if(i!=0) str.erase(0,i-1);
      for (i = str.length()-1; i!=0 && str[i]==' ';i--);
      str.erase(i+1,str.length()-1);
  }
}
int main(int argc , char *argv[]){
  string input_line;
  while( getline( cin, input_line).eof() == false ){
    oop::trim(input_line);
    oop::reverse(input_line);
    oop::toUpperCase(input_line);
    cout << input_line << endl;
  }
  return 0;
}

