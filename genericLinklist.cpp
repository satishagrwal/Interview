
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    Node<T>* next = NULL;
    T data;
};


template<typename T>
class LinkList
{
  public:
    Node<T>* head;
     
   LinkList<T>()
   {
      head = NULL;
   }
  
   void insert(T data)
   {
        if(!head)
        {
          head = new Node<T>;
          head->data = data;
        }
        else
        {
           Node<T>* temp = new Node<T>;
           temp->data = data;
           temp->next= head;
           head=temp;
        }
   }
  
   void display()
   {
      Node<T>* temp = this->head;
       
      while(temp != NULL)
      {
         cout<<temp->data<<endl;
         temp = temp->next;
      }
   }
};


// To execute C++, please define "int main()"
int main() 
{
  LinkList<int> i;
  i.insert(10);
  i.insert(20);
  i.insert(30);
  i.display();
  return 0;
}
