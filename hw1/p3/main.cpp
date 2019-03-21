#include <iostream>
#include <vector>

using namespace std;
int main(void)
{
    int a,b,c,i,j,k;
    cin>>a>>b>>c;
    vector<vector<int> > x;
    x.resize(a);
    for(i=0; i<a; ++i) x[i].resize(b);
    for(i=0; i<a; ++i)
    {
        for(j=0; j<b; ++j)
        {
            cin>>x[i][j];
        }
    }
    cout<<"\n";
    vector<vector<int> > y;
    y.resize(b);
    for(i=0; i<b; ++i) y[i].resize(c);
    for(i=0; i<b; ++i)
    {
        for(j=0; j<c; ++j)
        {
            cin>>y[i][j];
        }
    }
    cout<<"\n";
    vector<vector<int> > z;
    z.resize(a);
    for(i=0; i<a; ++i) y[i].resize(c);
    for(i=0; i<a; ++i)
    {
        for(k=0; k<c; ++k)
        {
           int s=0;
           for(j=0; j<b; ++j)
           {
               s+=(x[i][j]*y[j][k]);
           }
           cout<<s<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
