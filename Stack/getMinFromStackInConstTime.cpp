#include <bits/stdc++.h> 
using namespace std; 
  
struct MyStack 
{ 
    stack<int> stack; 
    int minValue; 
  
    void getMin() 
    { 
        if (stack.empty()) 
            cout << "Stack is empty\n"; 
        else
            cout <<"Minimum Element in the stack is: "
                 << minValue << "\n"; 
    } 
  
    void peek() 
    { 
        if (stack.empty()) 
        { 
            cout << "Stack is empty "; 
            return; 
        } 
  
        int t = stack.top(); // Top element. 
  
        cout << "Top Most Element is: "; 
  
        // If t < minValue means minValue stores 
        // value of t. 
        (t < minValue)? cout << minValue: cout << t; 
    } 
  
    // Remove the top element from Stack 
    void pop() 
    { 
        if (stack.empty()) 
        { 
            cout << "Stack is empty\n"; 
            return; 
        } 
  
        cout << "Top Most Element Removed: "; 
        int t = stack.top(); 
        stack.pop(); 
  
        // Minimum will change as the minimum element 
        // of the stack is being removed. 
        if (t < minValue) 
        { 
            cout << minValue << "\n"; 
            minValue = 2*minValue - t; 
        } 
  
        else
            cout << t << "\n"; 
    } 
  
    // Removes top element from MyStack 
    void push(int x) 
    { 
        // Insert new number into the stack 
        if (stack.empty()) 
        { 
            minValue = x; 
            stack.push(x); 
            cout <<  "Number Inserted: " << x << "\n"; 
            return; 
        } 
  
        // If new number is less than minValue 
        if (x < minValue) 
        { 
            stack.push(2*x - minValue); 
            minValue = x; 
        } 
  
        else
           stack.push(x); 
  
        cout <<  "Number Inserted: " << x << "\n"; 
    } 
}; 

int main() 
{ 
    MyStack stack; 
    stack.push(3); 
    stack.push(5); 
    stack.getMin(); 
    stack.push(2); 
    stack.push(1); 
    stack.getMin(); 
    stack.pop(); 
    stack.getMin(); 
    stack.pop(); 
    stack.peek(); 
  
    return 0; 
} 


/* Try more Inputs
Case 1:
MyStack stack; 
stack.push(13); 
stack.push(5);
int result = s.getMin();
expected = 5
Case 2: 
MyStack stack; 
stack.push(-1); 
stack.push(2);
int result = s.getMin();
expected = -1
*/
