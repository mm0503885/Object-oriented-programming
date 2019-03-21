#include <iostream>
using namespace std;
template <class T>
int compare (T a,T b)
{
    if(a>b)
        return 1;
    else if(a<b)
        return -1;
    else
        return 0;
}
int main(void)
{
    cout<<"Enter the type you want (1)int (2)double (3)char: ";
    int x;
    cin>>x;
    if(x==1)
    {
        int a,b;
        cin>>a>>b;
        return compare(a,b);
    }
    if(x==2)
    {
        double a,b;
        cin>>a>>b;
        return compare(a,b);
    }
    if(x==3)
    {
        char a,b;
        cin>>a>>b;
        return compare(a,b);

    }


}
