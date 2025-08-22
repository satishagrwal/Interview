#include <iostream>
#include <new>

using namespace std;

class MyClass{
    public:
        int value;

    // Constructor
    MyClass(int v = 0) : value(v) {
        std::cout << "[MyClass] Constructor called with value = " << value << "\n";
    }

    // Destructor
    ~MyClass() {
        std::cout << "[MyClass] Destructor called\n";
    }
void * operator new(std::size_t size){
    std::cout << "[MyClass] Allocating " << size << " bytes...\n";
    void *ptr = std::malloc(size);
    if(!ptr)
    {
        std::cout << "Failed to allocate memory" << std::endl;
        throw std::bad_alloc();
    }
    return ptr;
}

void operator delete(void *ptr){
    std::cout << "[MyClass] De-allocating \n";
    std::free(ptr);
}

};

int main()
{
     MyClass* obj = new MyClass(20);
     delete obj;

    return 0;
}
