/* If two threads call getInstance() at the same time, both might create different Singalton objects, violating the singleton pattern.
So use Mayers Singleton desing pattern to prevent by defining static local variable in function itself*/
#include <iostream>

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance; // created once, thread-safe since C++11
        return instance;
    }

    void sayHello() {
        std::cout << "Hello from Singleton" << std::endl;
    }

private:
    Singleton() {
        std::cout << "Singleton object created" << std::endl;
    }
    ~Singleton() {
        std::cout << "Singleton object destroyed" << std::endl;
    }

    // prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    s1.sayHello();

    return 0; // Singleton destroyed automatically
}
