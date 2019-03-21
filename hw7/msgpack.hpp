#ifndef MSGPACK_HPP
#define MSGPACK_HPP

#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <vector>
#include<math.h>

#include "endian.h"
using namespace std;

struct value {
    public:
        typedef bool boolean_type;
        typedef std::int64_t integer_type;
        typedef std::string string_type;
        typedef std::vector<value> array_type;
        typedef std::map<string_type, value> map_type;


        value():tag(tag_t::nil_tag){}
        explicit value(const boolean_type boo)
        {
          tag=tag_t::boolean_tag;
           new(&val.b) boolean_type(boo);
        }
        explicit value(const integer_type inte)
        {
          tag=tag_t::integer_tag;
          new(&val.i) integer_type(inte);
        }
        explicit value(const string_type& str)
        {
          tag=tag_t::string_tag;
          new(&val.s) string_type(str);
        }
         explicit value(const array_type& arr)
        {
          tag=tag_t::array_tag;
          new(&val.a) array_type(arr);
        }
         explicit value(const map_type& ma)
        {
          tag=tag_t::map_tag;
          new(&val.m) map_type(ma);
        }


        value(const value&);
        value& operator=(const value&);
        ~value()
        {
           if(tag==tag_t::string_tag)
            val.s.~string();
        }




         bool is_nil() const
        {
           if(tag==tag_t::nil_tag)
           return true;
           else
           return false;
        }
        bool is_boolean() const
        {
           if(tag==tag_t::boolean_tag)
           return true;
           else
           return false;
        }
        bool is_integer() const
        {
           if(tag==tag_t::integer_tag)
           return true;
           else
           return false;
        }
         bool is_string() const
        {
           if(tag==tag_t::string_tag)
           return true;
           else
           return false;
        }
        bool is_array() const
        {
           if(tag==tag_t::array_tag)
           return true;
           else
           return false;
        }
          bool is_map() const
        {
           if(tag==tag_t::map_tag)
           return true;
           else
           return false;
        }
        boolean_type& get_boolean()
        {
            if(tag==tag_t::boolean_tag)
            return val.b;
            else
            throw(std::bad_cast());
        }
        integer_type& get_integer()
        {
            if(tag==tag_t::integer_tag)
            return val.i;
            else
            throw(std::bad_cast());
        }
        string_type& get_string()
        {
            if(tag==tag_t::string_tag)
            return val.s;
            else
            throw(std::bad_cast());
        }
        array_type& get_array()
        {
            if(tag==tag_t::array_tag)
            return val.a;
            else
            throw(std::bad_cast());
        }
        map_type& get_map()
        {
            if(tag==tag_t::map_tag)
            return val.m;
            else
            throw(std::bad_cast());
        }
        const boolean_type& get_boolean() const
        {
            if(tag==tag_t::boolean_tag)
            return val.b;
            else
            throw(std::bad_cast());
        }
        const integer_type& get_integer() const
        {
            if(tag==tag_t::integer_tag)
            return val.i;
            else
            throw(std::bad_cast());
        }
        const string_type& get_string() const
        {
            if(tag==tag_t::string_tag)
            return val.s;
            else
            throw(std::bad_cast());
        }
        const array_type& get_array() const
        {
            if(tag==tag_t::array_tag)
            return val.a;
            else
            throw(std::bad_cast());
        }
        const map_type& get_map() const
        {
            if(tag==tag_t::map_tag)
            return val.m;
            else
            throw(std::bad_cast());
        }
        friend bool operator==(const value& lhs, const value& rhs)
        {
            if(lhs.tag==rhs.tag)
            {
                   if(lhs.tag==tag_t::nil_tag)
                   return true;
                   if(lhs.tag==tag_t::boolean_tag)
                   return lhs.val.b==rhs.val.b;
                   else if(lhs.tag==tag_t::integer_tag)
                   return lhs.val.i==rhs.val.i;
                   else if(lhs.tag==tag_t::string_tag)
                   return lhs.val.s==rhs.val.s;
                   else if(lhs.tag==tag_t::array_tag)
                   return lhs.val.a==rhs.val.a;
                   else if(lhs.tag==tag_t::map_tag)
                   return lhs.val.m==rhs.val.m;
                   else;
            }
            else return false;
        }
        friend bool operator!=(const value& lhs, const value& rhs)
        {
            return !(lhs==rhs);
        }
        std::ostream& serialize(std::ostream& out) const
        {
            if(tag==tag_t::nil_tag)
            {
                uint8_t a=0xc0;
                out<<a;
            }
            if(tag==tag_t::boolean_tag)
            {
                uint8_t a;
                if(val.b==true)
                a=0xc3;
                else
                a=0xc2;
                out<<a;

            }
            if(tag==tag_t::integer_tag)
            {
                vector<std::uint8_t> a(9);
                a[0]=0xd3;
                int i=8,x=val.i;
                if(x>=0)
                {
                  for(i;i>0;i--)
                   {
                    a[i]=x%256;
                    x/=256;
                   }
                }
                else
                {
                    for(i;i>0;i--)
                    {
                        a[i]=((x%256)+256);
                        x=(x/256)-1;
                    }
                }
                for(i=0;i<9;i++)
                {
                    out<<a[i];
                }
            }
            if(tag==tag_t::string_tag)
            {
                vector<std::uint8_t> a(5);
                a[0]=0xdb;
                int i=4,x=val.s.size();
                for(i;i>0;i--)
                {
                    a[i]=x%256;
                    x/=256;
                }
                for(i=0;i<val.s.size();i++)
                {
                    a.push_back(val.s[i]);
                }
                for(i=0;i<a.size();i++)
                {
                    out<<a[i];
                }
            }
            if(tag==tag_t::array_tag)
            {
                vector<std::uint8_t> vec(5);
                vec[0]=0xdd;
                int i=4,x=val.a.size();
                for(i;i>0;i--)
                {
                    vec[i]=x%256;
                    x/=256;
                }
                 for(i=0;i<vec.size();i++)
                {
                    out<<vec[i];
                }
                for(i=0;i<val.a.size();i++)
                {
                    val.a[i].serialize(out);
                }
             }
             if(tag==tag_t::map_tag)
             {
                vector<std::uint8_t> vec(5);
                vec[0]=0xdf;
                int i=4,x=val.m.size();
                for(i;i>0;i--)
                {
                    vec[i]=x%256;
                    x/=256;
                }
                 for(i=0;i<vec.size();i++)
                {
                    out<<vec[i];
                }
                for(map_type::const_iterator iter=val.m.begin(); iter!=val.m.end(); ++iter)
                {
                    value v(iter->first);
                    v.serialize(out);
                    (iter->second).serialize(out);
                }
             }

        }
        static value deserialize(std::istream& in)
        {
            uint8_t a;
            in>>a;
            if(a==0xc0)
            {
                value v;
                return v;
            }
            else if(a==0xc3)
            {
                value v(true);
                return v;
            }
            else if(a==0xc2)
            {
                value v(false);
                return v;
            }
            else if(a==0xd3)
            {
                vector<std::uint8_t> vec(8);
                int i;
                for(i=0;i<8;i++) in>>vec[i];
                if(in.fail()==true)
                {
                    value v;
                    return v;
                }
                integer_type x=0;
                integer_type j=7;
                if(vec[0]<0x80)
                {
                for(i=0;i<8;i++)
                  {
                    x+=((vec[i])*(pow(256,j)));
                    j--;
                  }
                  value v(x);
                  return v;
                }
                else
                {
                    x=(-1)*(256-vec[0])*(pow(256,j));
                    j--;
                     for(i=1;i<8;i++)
                   {
                    x+=((vec[i])*(pow(256,j)));
                    j--;
                   }
                   value v(x);
                   return v;
                }
            }
            else if(a==0xdb)
            {
                 int i;
                 int32_t x;
                 in.read(reinterpret_cast<char*>(&x), sizeof(x));
                if(in.fail()==true)
                {
                    value v;
                    return v;
                }
                 x = be32toh(move(x));
                vector<char> vec;
                char c;
                for(i=0;i<x;i++)
                {
                    in>>c;
                    vec.push_back(c);
                }
                string ss(vec.begin(),vec.end());
                value v(ss);
                return v;
            }
            else if(a==0xdd)
                {
                       int32_t x;
                       in.read(reinterpret_cast<char*>(&x), sizeof(x));
                         if(in.fail()==true)
                        {
                        value v;
                        return v;
                        }
                       x = be32toh(move(x));
                       vector<value>vec(x);
                        for(int i=0;i<x;i++)
                        {
                            vec[i]=(deserialize(in));
                        }
                        value v(vec);
                        return v;
                    }
            else if(a==0xdf)
                {
                       int32_t x;
                       in.read(reinterpret_cast<char*>(&x), sizeof(x));
                         if(in.fail()==true)
                        {
                         value v;
                         return v;
                        }
                       x = be32toh(move(x));
                       map_type mm;
                        for(int i=0;i<x;i++)
                        {
                            value v(deserialize(in));
                            mm[v.val.s]=(deserialize(in));
                        }
                        value vv(mm);
                        return vv;
                    }
                 else
                 {
                     std::uint8_t u;
                     in>>u;
                     value v;
                     return v;
                 }
             }



    private:
        enum class tag_t { nil_tag, boolean_tag, integer_tag, string_tag,
                           array_tag, map_tag };
        union union_t {
            union_t() {}
            ~union_t() {}
            boolean_type b;
            integer_type i;
            string_type s;
            array_type a;
            map_type m;
        };

        tag_t tag;
        union_t val;
};
value::value(const value& v)
{
    tag=v.tag;
    if(v.tag==tag_t::boolean_tag)
    new(&val.b) boolean_type(v.val.b);
    else if(v.tag==tag_t::integer_tag)
    new(&val.i) integer_type(v.val.i);
    else if(v.tag==tag_t::string_tag)
    new(&val.s) string_type(v.val.s);
    else if(v.tag==tag_t::array_tag)
    new(&val.a) array_type(v.val.a);
    else if(v.tag==tag_t::map_tag)
    new(&val.m) map_type(v.val.m);
    else;

}
value& value::operator=(const value& v)
{
      if( &v!=this)
        {
    tag=v.tag;
    if(v.tag==tag_t::boolean_tag)
    new(&val.b) boolean_type(v.val.b);
    else if(v.tag==tag_t::integer_tag)
    new(&val.i) integer_type(v.val.i);
    else if(v.tag==tag_t::string_tag)
    new(&val.s) string_type(v.val.s);
    else if(v.tag==tag_t::array_tag)
    new(&val.a) array_type(v.val.a);
    else if(v.tag==tag_t::map_tag)
    new(&val.m) map_type(v.val.m);
    else;

        }
        return *this;



}



#endif
