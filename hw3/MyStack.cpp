#include <iostream>
#include "MyStack.h"
#include "Coordinate.h"
using namespace std;
template <class T>
MyStack<T>::Node::Node(T& a, Node* b):value(a),next(b){}
template <class T>
MyStack<T>::MyStack():head(NULL)
{

   size=0;
}
template <class T>
MyStack<T>::~MyStack()
{
}
template <class T>
void MyStack<T>::push(T& a)
{
    Node* q;
    q=new Node(a,head);
    head=q;
    size++;
}
template <class T>
void MyStack<T>::pop()
{
       Node* q=head;
       head=head->next;
       delete q;
       size--;
}
template <class T>
T& MyStack<T>::top()
{
    return head->value;
}
template <class T>
size_t MyStack<T>::getSize() const
{
  return size;
}
template <class T>
bool MyStack<T>::empty() const
{
    return head==NULL;
}
template class MyStack < char >;
template class MyStack < Coordinate >;

