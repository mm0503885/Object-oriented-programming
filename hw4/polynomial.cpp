#include"polynomial.h"
#include<iostream>
polynomial::polynomial(const int x0)
{
    poly.push_back(x0);
}
polynomial::polynomial(const std::vector<int>& v)
{
    if(v.size()==0)
        poly.push_back(0);
    else
    {
       int i=0;
       while(i<v.size())
      {
        poly.push_back(v[i]);
        i++;
      }
      i--;
    while(poly[i]==0 && i!=0)
      {
        poly.pop_back();
        i--;
      }
    }
}
polynomial::polynomial(const polynomial &b)
{
    poly=b.poly;
}
polynomial&  polynomial::operator=(const polynomial& a)
{
        if( &a!=this)
        {
           poly=a.poly;
        }
        return *this;
}
polynomial::~polynomial(){}
polynomial operator-(polynomial a)
{
    for(int i=0;i<a.poly.size();i++)
    {
        a.poly[i]=(-1)*a.poly[i];
    }
    return a;
}
polynomial operator+(polynomial a, const polynomial& b)
{
      polynomial sum;
      sum.poly.pop_back();
      int i=0;
    if(a.poly.size()<=b.poly.size())
    {
        while(i<a.poly.size())
        {
            sum.poly.push_back(a.poly[i]+b.poly[i]);
            i++;
        }
        while(i<b.poly.size())
        {
            sum.poly.push_back(b.poly[i]);
            i++;
        }
    }
    else
    {
        while(i<b.poly.size())
        {
            sum.poly.push_back(a.poly[i]+b.poly[i]);
            i++;
        }
        while(i<a.poly.size())
        {
            sum.poly.push_back(a.poly[i]);
            i++;
        }
    }
        i--;
        while (sum.poly[i]==0 && i!=0)
        {
            sum.poly.pop_back();
            i--;
        }

    return sum;
}
polynomial operator-(polynomial a, const polynomial& b)
{
    polynomial sub;
    sub.poly.pop_back();
    int i=0;
    if(a.poly.size()<=b.poly.size())
    {
        while(i<a.poly.size())
        {
            sub.poly.push_back(a.poly[i]-b.poly[i]);
            i++;
        }
        while(i<b.poly.size())
        {
            sub.poly.push_back((-1)*b.poly[i]);
            i++;
        }
    }
    else
    {
        while(i<b.poly.size())
        {
            sub.poly.push_back(a.poly[i]-b.poly[i]);
            i++;
        }
        while(i<a.poly.size())
        {
            sub.poly.push_back(a.poly[i]);
            i++;
        }
    }
        i--;
        while (sub.poly[i]==0 && i!=0)
        {
            sub.poly.pop_back();
            i--;
        }
    return sub;
}

 polynomial operator*(polynomial a, const polynomial& b)
 {
    polynomial mul;
    mul.poly.pop_back();
    int i=0,j=0,c=0;
     if(a.poly.size()>=b.poly.size())
    {
    while(c<(a.poly.size()+b.poly.size()-1))
    {
        if(c<a.poly.size())
        {i=c; j=0;}
        else
        {i=a.poly.size()-1;j=c-i;}
        int s=0;
        while(j<b.poly.size() && i>=0)
        {
         s+=(a.poly[i]*b.poly[j]);
         i--;
         j++;
        }
        mul.poly.push_back(s);
        c++;
    }
    }
    else
    {
    while(c<(a.poly.size()+b.poly.size()-1))
    {
        if(c<b.poly.size())
        {j=c; i=0;}
        else
        {j=b.poly.size()-1;i=c-j;}
        int s=0;
        while(i<a.poly.size() && j>=0)
        {
         s+=(a.poly[i]*b.poly[j]);
         j--;
         i++;
        }
        mul.poly.push_back(s);
        c++;
    }
    }

    c--;
        while (mul.poly[c]==0 &&c!=0)
        {
            mul.poly.pop_back();
            c--;
        }

    return mul;
 }
polynomial& operator+=(polynomial& a, const polynomial& b)
{
   a=a+b;
   return a;
}
polynomial& operator-=(polynomial& a, const polynomial&  b)
{
   a=a-b;
   return a;
}
polynomial& operator*=(polynomial& a, const polynomial& b)
{
   a=a*b;
   return a;
}
double polynomial::operator()(const double x) const
{
    double s=poly[0],a=x;
    for(int i=1;i<poly.size();i++)
    {
        s+=(poly[i]*a);
        a*=x;
    }
    return s;
}
bool operator==(const polynomial& a, const polynomial& b)
{
    if(a.poly==b.poly)
        return true;
    else
        return false;
}
bool operator!=(const polynomial& a, const polynomial& b)
{
    if(a.poly!=b.poly)
        return true;
    else
        return false;
}
polynomial::operator bool() const
{
      for(int i=0;i<poly.size();i++)
    {
        if(poly[i]!=0)
        return true;
    }
    return false;
}
size_t polynomial:: degree() const
{
    return poly.size()-1;
}
polynomial polynomial::derivate() const
{
    polynomial a;
    if(poly.size()>1)
    {
    a.poly.pop_back();
    int i;
    for(i=1;i<poly.size();i++)
    {
        a.poly.push_back(i*poly[i]);
    }
        i-=2;
        while (a.poly[i]==0 && i!=0)
        {
            a.poly.pop_back();
            i--;
        }
    }
    return a;
}
std::istream& operator>>(std::istream& input , polynomial& a)
{
   if(input.peek()=='\n')
   {
       input.ignore();
       return input;
   }
   else{
   int i;
   a.poly.pop_back();
   while(true)   {
       if(input.peek()=='\n')
        {
            input.ignore();
            int j=a.poly.size()-1;
            while(a.poly[j]==0 && j!=0)
            {
                a.poly.pop_back();
                j--;
            }
            return input;
        }
       else if(input.peek()==' ')input.ignore();
       else
       {
            input>>i;
            a.poly.push_back(i);
       }
   }
   }
}
std::ostream& operator<<(std::ostream& output, const polynomial& a)
{
    for(int i=0;i<a.poly.size();i++)
    {
        output<<a.poly[i];
        if(i!=a.poly.size())output<<"  " ;
    }
    return output;
}
