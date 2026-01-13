#include <iostream>
using namespace std;

#include <iostream>

template <typename T>
class SmartPtr
{
    T* ptr;

public:
    explicit SmartPtr(T* p = nullptr) : ptr(p) {}

    ~SmartPtr()
    {
        delete ptr;
    }

    // Disable copy
    SmartPtr(const SmartPtr&) = delete;
    SmartPtr& operator=(const SmartPtr&) = delete;

    // Move constructor
    SmartPtr(SmartPtr&& other) noexcept : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }

    // Move assignment
    SmartPtr& operator=(SmartPtr&& other) noexcept
    {
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // Dereference
    T& operator*() const
    {
        return *ptr;
    }

    // Arrow
    T* operator->() const
    {
        return ptr;
    }

    // Utility
    T* get() const { return ptr; }
};

int main()
{
    SmartPtr<int> p(new int(10));
    std::cout << *p << std::endl;
    //SmartPtr<int> b = p;   // shallow copy → double delete
    SmartPtr<int> q = std::move(p); // ownership transfer
}
