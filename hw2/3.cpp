#include <iostream>
using namespace std;
struct node {
int value ;
node* next ;
};
node* Insert(node* p,int d)
{
    node* q;
    q=new(node);
    if (p!=NULL)
        {
            if (d<=(p->value))
            {
                q->value=d;
                q->next=p;
                return q;
            }
            else
            {
                p->next=Insert(p->next,d);
                return p;
            }
        }
    else
        {
            q->value=d;
            q->next=p;
            return q;
        }

}
void Traverse(node* p)
{
    cout<<"Traverse: ";
    node *q = p;
    while(q)
        {

            cout << q->value << " ";
            q = q->next;
        }
    cout<<endl;
}
node* Delete(node* p,int d)
{

    if (p!=NULL)
    {
        if (p->value==d)
        {
            node* q=p;
            p=p->next;
            delete(q);
        }
        else
        p->next=Delete(p->next,d);
    return p;
    }

    else
        cout<<"Node with value "<<d<<" is not found!"<<endl;
    return p;
}
node* Unique(node* p)
{
    if(p->next!=NULL)
    {
        node* r=p->next;
        if(p->value==r->value)
        {
            while (p->value==r->value && p->next!=NULL)
            {
                if (r->next!=NULL)
                {
                    p->next=r->next;
                    delete(r); r=p->next;
                }
                else
                {
                    p->next=NULL;
                    delete(r);
                }
            }
        }
        if(p->next!=NULL)
        Unique(p->next);
    }
    return p;
}
node* Slice(node* p,int a,int b)


{
    if (p!=NULL)
    {
        while (p->value<a)
        {
            node* q=p;
            p=p->next;
            delete(q);
        }
        node *q=p,*r;
        while (q!=NULL)
            if (q->value>b) break;
        else
        {
            r=q;
            q=q->next;
        }
        while (q!=NULL && q!=p)
        {
            r->next=q->next;
            delete(q);
            q=r->next;
        }
    }
    return p;
}


int main()
{
    node* first;
    first = new node;
    first = NULL;
    int a;
    while(1)
    {
        cout<<"(1)Insert (2)Traverse (3)Delete (4)Unique (5)Slice (6)Exit: ";
        cin>>a;
        if(a==1)
        {
            cout<<"Enter the value of the new node: ";
            int b;
            cin>>b;
            cout<<endl;
            first=Insert(first,b);
        }
        if(a==2)
        {
            Traverse(first);
            cout<<endl;
        }
        if(a==3)
        {
            cout<<"Enter the value to be deleted: ";
            int d;
            cin>>d;
            first=Delete(first,d);
            cout<<endl;
        }
        if(a==4)
        {
            Unique(first);
            cout<<endl;
        }
        if(a==5)
        {
            cout<<"Enter the range for slicing: ";
            int b,c;
            cin>>b>>c;
            cout<<endl;
            first=Slice(first,b,c);

        }
        if(a==6)
            return 0;
     }
}
