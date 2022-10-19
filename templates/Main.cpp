#include "ArrayBag.hpp"
#include <iostream>
#include <string>



int main() {
    ArrayBag<std::string> bagA;
    ArrayBag<std::string> bagB;

    bagA.add("A");
    bagA.add("B");
    bagA.add("C");
    bagA.add("D");
    bagA.add("E");
    bagB.add("B");
    bagB.add("D");
    bagB.add("Z");

    std::cout << "DISPLAY BOTH BAG_A AND BAG_B" << std::endl;
    bagA.display();
    bagB.display();
    std::cout << std::endl;

    /*cout << "SET UNION OF BOTH BAG_A AND BAG_B" << endl;
    bagA += bagB;
    bagA.display();
    cout << endl;

    cout << "SET DIFFERENCE OF BOTH BAG_A AND BAG_B" << endl;
    bagA -= bagB;
    bagA.display();
    cout << endl; */

    std::cout << "SET INTERSECTION OF BOTH BAG_A AND BAG_B" << std::endl;
    bagA /= bagB;
    bagA.display();
    std::cout << std::endl;
}