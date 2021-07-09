#include<iostream>

using namespace std;
class Singleton
{
 public:
   static Singleton* GetInstance();
   static void releaseInstance();
   static void releasRef();
   static void addRef();
  
private:
	Singleton()
  {
		cout<<"constructor...\n";
	} 
	~Singleton()
  {
		cout<<"destructor...\n";
	} 
  Singleton(const Singleton& rhs );
  Singleton& operator=(const Singleton& rhs);

  static Singleton* s_instance;
	static int counter;   
};

Singleton* Singleton::s_instance = NULL;
int Singleton::counter = 0;

void Singleton::addRef()
{
		++counter;
}

void Singleton::releasRef()
{
		--counter;
}

Singleton* Singleton::GetInstance()
{
	if(NULL == s_instance)
	{
		s_instance=new Singleton();
	}		
	addRef();// track users
	return s_instance;      
}  

void Singleton::releaseInstance()
{
		releasRef();	
		if((0 == counter)&& (NULL != s_instance))
		{
			delete s_instance;
			s_instance = NULL;						
		}
}

int main()
{
    Singleton *singleton;
    singleton = singleton->GetInstance();
    cout << singleton << endl;

    // Another object gets the reference of the first object!
    Singleton *anotherSingleton;
    anotherSingleton = anotherSingleton->GetInstance();
    cout << anotherSingleton << endl;

    return 0;
}
