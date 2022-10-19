#include "PriorityQueue.hpp"
#include <iostream>

int main() 
{
    PriorityQueue<int> a;
    a.enqueue(0,0);
    a.enqueue(1,1);
    a.enqueue(2,2);

    std::cout << a.front() << " ";
    a.dequeue();
    std::cout << a.front() << " ";
    a.dequeue();
    std::cout << a.front() << " ";


    std::cout << std::endl;

    /* Random Priorities

        PriorityQueue<int> a;
    a.enqueue(0,537812);
    a.enqueue(1,52);
    a.enqueue(2,52353);

    std::cout << a.front() << " ";
    a.dequeue();
    std::cout << a.front() << " ";
    a.dequeue();
    std::cout << a.front() << " ";


    std::cout << std::endl;
    */
}