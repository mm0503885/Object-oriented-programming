#include <iostream>
using namespace std;
int main()
{
    cout << "Please enter a number: ";
    int number;
    while(cin >> number,!cin.eof())
    {
        if(cin.good()==false)
        {
            cout<<"Not a number."<<endl;
            cin.clear();
            cin.ignore();
        }
        else
            cout<<"A number."<<endl;
        cout << "Please enter a number: ";
    }
    return 0;
}
