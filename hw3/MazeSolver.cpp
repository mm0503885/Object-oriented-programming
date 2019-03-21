#include <iostream>
#include "MyStack.h"
#include "Coordinate.h"
using namespace std;
char a;
    char *cord[10][10];
    MyStack<Coordinate> s;
bool right (void)
    {return (s.top().getX()<9 && *cord[s.top().getX()+1][s.top().getY()]=='.');}
bool down  (void)
    {return (s.top().getY()<9 && *cord[s.top().getX()][s.top().getY()+1]=='.');}
bool left  (void)
    {return (s.top().getX()>0 && *cord[s.top().getX()-1][s.top().getY()]=='.');}
bool up    (void)
    {return (s.top().getY()>0 && *cord[s.top().getX()][s.top().getY()-1]=='.');}


int main(void) {

    for(int y=0; y<10; y++) {
        for(int x=0; x<10; x++){
        cin >> a;
        cord[x][y] = new char(a);
    }
}
    int x=0,y=0;
    s.push(*new Coordinate(x,y));
    *cord[x][y]='+';
    while(true)
    {
     if(s.top().getX()<9 && *cord[s.top().getX()+1][s.top().getY()]=='G')
    { s.push(*new Coordinate(s.top().getX()+1,s.top().getY()));  *cord[s.top().getX()][s.top().getY()]='+'; break; }

    if(s.top().getY()<9 && *cord[s.top().getX()][s.top().getY()+1]=='G')
    { s.push(*new Coordinate(s.top().getX(),s.top().getY()+1));  *cord[s.top().getX()][s.top().getY()]='+'; break; }

    if(s.top().getX()>0 && *cord[s.top().getX()-1][s.top().getY()]=='G')
    { s.push(*new Coordinate(s.top().getX()-1,s.top().getY()));  *cord[s.top().getX()][s.top().getY()]='+'; break; }

    if(s.top().getY()>0 && *cord[s.top().getX()][s.top().getY()-1]=='G')
    { s.push(*new Coordinate(s.top().getX(),s.top().getY()-1));  *cord[s.top().getX()][s.top().getY()]='+'; break; }
    if(right())
    { s.push(*new Coordinate(s.top().getX()+1,s.top().getY()));  *cord[s.top().getX()][s.top().getY()]='+'; continue; }

    if(down() && !right())
    { s.push(*new Coordinate(s.top().getX(),s.top().getY()+1));  *cord[s.top().getX()][s.top().getY()]='+'; continue; }

    if(left() && !down() && !right())
    { s.push(*new Coordinate(s.top().getX()-1,s.top().getY()));  *cord[s.top().getX()][s.top().getY()]='+'; continue; }

    if(up() && !left() && !down() && !right())
    { s.push(*new Coordinate(s.top().getX(),s.top().getY()-1));  *cord[s.top().getX()][s.top().getY()]='+'; continue; }
    if(s.top().getX()==0 && s.top().getY()==0){ cout<<"There is no solution!"; return 0;}
    if(!up() && !left() && !down() && !right()) s.pop();
    }
      for(int y=0; y<10; y++) {
            for(int x=0; x<10; x++){
            cout<<*cord[x][y];
         }
    cout<<endl;
    }

    return 0;
}
