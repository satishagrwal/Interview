#include <iostream>
#include <cstdlib>
using namespace std;
 
// define default capacity of the stack
#define SIZE 10
 
// Class for stack
class stack
{
    int *arr;
    int top;
    int capacity;
 
public:
    stack(int size = SIZE);     // constructor
    ~stack();                   // destructor
 
    void push(int);
    int pop();
    bool isEmpty();
    bool isFull();
};
 
// Constructor to initialize stack
stack::stack(int size)
{
    arr = new int[size];
    capacity = size;
    top = -1;
}
 
// Destructor to free memory allocated to the stack
stack::~stack()
{
    delete[] arr;
}
 
// Utility function to add an element x in the stack
void stack::push(int x)
{
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << x << endl;
    arr[++top] = x;
}
 
// Utility function to pop top element from the stack
int stack::pop()
{
    // check for stack underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}

 
// Utility function to check if the stack is empty or not
bool stack::isEmpty()
{
    return top == -1;    // or return size() == 0;
}
 
// Utility function to check if the stack is full or not
bool stack::isFull()
{
    return top == capacity - 1;    // or return size() == capacity;
}
 
int main()
{
    stack pt(3);
 
    pt.push(1);
    pt.push(2);
 
    pt.pop();
    pt.pop();
 
    pt.push(3);
 
    pt.pop();
 
    if (pt.isEmpty())
        cout << "Stack Is Empty\n";
    else
        cout << "Stack Is Not Empty\n";
 
    return 0;
}

/* Try more Inputs
Case 1:
        stack pt(3);
        pt.push(1);
        pt.push(2);
        int result = pt.pop();
        expected = 2

Case2: 
      stack pt(3);
        pt.push(1);
        pt.push(2);
        pt.push(3);
        int result = pt.pop();
        expected = 3
*/
