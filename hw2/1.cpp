#include <iostream>
using namespace std;
int main (void)
{
    cout<<"Please enter a decimal number: ";
    int a;
    while(cin>>a,!cin.eof())
    {
        cout<<"Its hexadecimal format is: "<<hex<<a<<endl;
        cout<<"Its octal format is: "<<oct<<a<<endl;
        cout<<"Please enter a decimal number: ";
    }
    return 0;
}
