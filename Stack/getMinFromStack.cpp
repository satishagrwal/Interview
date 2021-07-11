/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int getMin() retrieves the minimum element in the stack.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;


class Stack 
{
 private:
	static const int max = 100;
	int arr[max];
	int top;

public:
	Stack() { top = -1; }
	bool isEmpty();
	bool isFull();
	int pop();
	void push(int x);
};

bool Stack::isEmpty()
{
	if (top == -1)
	{
	  return true;
	}
	else
	{
	  return false;
	}
}


bool Stack::isFull()
{
	if (top == max - 1)
	{
		return true;
	}
	else
	{
	  return false;
	}
}

int Stack::pop()
{
	if (isEmpty()) 
	{
	    cout << "Stack Underflow";
		abort();
	}
	int x = arr[top];
	top--;
	
	return x;
}

void Stack::push(int x)
{
	if (isFull())
	{
		cout << "Stack Overflow";
		abort();
	}
	top++;
	arr[top] = x;
}

class MinStack : public Stack
{
	Stack min;

public:
	int pop();
	void push(int x);
	int getMin();
};


/*
void MinStack::push(int x)
{
	if (isEmpty() == true)
	{
		Stack::push(x);
		min.push(x);
	}
	else 
	{
		Stack::push(x);
		int y = min.pop();
		min.push(y);
		
		if (x <= y)
		{
			min.push(x);
		}
	}
}
*/
void MinStack::push(int x)
{
	if (isEmpty() == true)
	{
		Stack::push(x);
		min.push(x);
	}
	else 
	{
		Stack::push(x);
		int y = min.pop();
		min.push(y);
		
		if (x < y)
		{
			min.push(x);
		}
		else
		{
		    min.push(y);
		}
	}
}

/*
int MinStack::pop()
{
	int x = Stack::pop();
	int y = min.pop();
	if(x !=y)
	{
	    min.push(y);
	}
	return x;
}
*/

int MinStack::pop()
{
	int x = Stack::pop();
	min.pop();
	return x;
}

int MinStack::getMin()
{
    int x = min.pop();
	return x;
}

int main()
{
	MinStack s;
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(10);
	s.push(50);
	cout << s.getMin() << endl;
	s.push(5);
	cout << s.getMin() << endl;
	s.pop();
	cout << s.getMin()<< endl;
	s.pop();
	s.pop();
	cout << s.getMin()<< endl;
	return 0;
}

