/*

Input array [4, 5, 2, 25], the next greater elements for each element are as follows.

Element       NGE
   4      -->   5
   5      -->   25
   2      -->   25
   25     -->   -1
   
   Input array [13, 7, 6, 12}, the next greater elements for each element are as follows. 
   
   Element        NGE
   13      -->    -1
   7       -->     12
   6       -->     12
   12      -->     -1
*/

#include<iostream>
#include<stack>
//#include<unordered_map>

using namespace std;

void printNGE(int arr[], int n)
{
	std::stack<int> s;
  //unordered_map<int, int> mp;
  
	s.push(arr[0]);

	for (int i = 1; i < n; i++)
	{
		while(s.empty() == false && (s.top() < arr[i])) 
		{
		   cout << s.top() << " ---> "<<arr[i]<<endl;	
       //mp[s.top()] = arr[i];
		   s.pop();
		}
        s.push(arr[i]);

	}
	while (s.empty() == false)
	{
	  cout <<s.top()<< " ---> "<<"-1"<<endl;
    // mp[s.top()] = -1;
	  s.pop();
	}
  /*
  for (int i = 0; i < n; i++)
	{
        cout << arr[i] << " ---> " << mp[arr[i]] << endl;
	}
  */
}


int main()
{
	int arr[] = { 12,8,6,10,7,9,11,1};
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	printNGE(arr, n);
	return 0;
}
