#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

constexpr int MAX = 10;

std::mutex mtx;
std::condition_variable cv;
int number = 1;

void print_odd()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [] {
            return (number % 2 == 1) || (number >= MAX);
        });

        if (number >= MAX)
            break;

        std::cout << "Odd number = " << number << std::endl;
        ++number;

        cv.notify_one();
    }
}

void print_even()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [] {
            return (number % 2 == 0) || (number >= MAX);
        });

        if (number >= MAX)
            break;

        std::cout << "Even number = " << number << std::endl;
        ++number;

        cv.notify_one(); // We can use notify_all() also in this case we have to notify only one thread. So used notify_one() for efficiency.
    }
}

int main()
{
    std::thread odd(print_odd);
    std::thread even(print_even);

    odd.join();
    even.join();

    return 0;
}
