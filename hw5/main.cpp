#include<iostream>
#include <string>
#include <vector>
using namespace std;

class CLASS{
public:

    vector<vector<string> > pub;
    vector<vector<string> > pro;
    vector<vector<string> > pri;
};



int main(){

int n;
cin>>n;
vector<CLASS> everyclass(n);
vector<string> classname(n);
for(int i=0;i<n;i++)
{
string x;
cin>>x;
    string b,c,y;
    cin>>classname[i]>>b>>y;
    if(y!="none"){
        if(y=="public")
        {
            cin>>c;
            for(int j=0;j<i;j++)
            {
                if(c==classname[j])
                    everyclass[i]=everyclass[j];
            }
        }
        else if(y=="protected")
        {
            cin>>c;
            for(int j=0;j<i;j++)
            {
                if(c==classname[j])
                    everyclass[i].pro=everyclass[j].pub;
                    everyclass[i].pro.insert(everyclass[i].pro.end(), everyclass[j].pro.begin(),everyclass[j].pro.end());
            }
        }
        else if(y=="private")
        {
            cin>>c;
            for(int j=0;j<i;j++)
            {
                if(c==classname[j])
                    everyclass[i].pri=everyclass[j].pub;
                    everyclass[i].pri.insert(everyclass[i].pri.end(), everyclass[j].pro.begin(),everyclass[j].pro.end());
                    everyclass[i].pri.insert(everyclass[i].pri.end(), everyclass[j].pri.begin(),everyclass[j].pri.end());
            }
        }
        else
        {
            if(x=="class")
            {
               for(int j=0;j<i;j++)
               {
                   if(y==classname[j])
                    everyclass[i].pri=everyclass[j].pub;
                    everyclass[i].pri.insert(everyclass[i].pri.end(), everyclass[j].pro.begin(),everyclass[j].pro.end());
                    everyclass[i].pri.insert(everyclass[i].pri.end(), everyclass[j].pri.begin(),everyclass[j].pri.end());
               }
            }
            else if (x=="struct")
            {
                 for(int j=0;j<i;j++)
                {
                    if(y==classname[j])
                    everyclass[i]=everyclass[j];
                }
            }
            else;

        }

    }
    while(1)
    {

        string z,d;
        cin>>z;
        if(z=="end") break;
        cin>>d;
        vector<string> y(2);
        y[0]=classname[i];
        y[1]=d;
        if(z=="public")

          everyclass[i].pub.push_back(y);
          else if(z=="protected")
          everyclass[i].pro.push_back(y);
          else if(z=="private")
          everyclass[i].pri.push_back(y);
          else;




    }

}
    while(!cin.eof()){
    string x,y;
    cin>>x>>y;
    int s=y.find('.');
    string z=y.substr(0,s);
    string w=y.substr(s+1,y.size());
        int i;
        for(i=0;x!=classname[i];i++);
        int k;
        for(k=0;k<classname.size() && z!=classname[k];k++);
        if(k==classname.size())
        {
            cout<<"Class not found"<<endl;
            continue;
        }
        int t=k;
        for(k;k>=0;k--)
        {
        for(int j=0; j<everyclass[t].pub.size();j++)
        {
            if(everyclass[t].pub[j][0]==classname[k])
            {
                if(everyclass[t].pub[j][1]==w)
                   { cout<<everyclass[t].pub[j][0]<<"."<<everyclass[t].pub[j][1]<<endl; k=-2; break;}
            }
        }
        if(k!=-2)
        {
            for(int j=0; j<everyclass[t].pro.size();j++)
        {
            if(everyclass[t].pro[j][0]==classname[k])
            {
                if(everyclass[t].pro[j][1]==w)
                    {
                        if(k<=i)
                        cout<<everyclass[t].pro[j][0]<<"."<<everyclass[t].pro[j][1]<<endl;
                        else cout<<"Invalid access"<<endl;
                          k=-2; break;
                    }
        }
        }
        if(k!=-2)
        {
            for(int j=0; j<everyclass[t].pri.size();j++)
        {
            if(everyclass[t].pri[j][0]==classname[k])
            {
                if(everyclass[t].pri[j][1]==w)
                    {
                        if(i==k) cout<<everyclass[t].pri[j][0]<<"."<<everyclass[t].pri[j][1]<<endl;
                        else cout<<"Invalid access"<<endl;
                        k=-1; break;
                    }
            }

        }
        }




        }





















    }
      if(k==-1)
            cout<<"Member not found "<<endl;
    }

return 0;



}

