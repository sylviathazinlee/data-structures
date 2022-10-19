#include "DoubleNode.hpp"
#include "DoublyLinkedList.hpp"

#include <iostream>

int main() {
   DoublyLinkedList<std::string> a;

   a.insert("1",1);
   a.insert("2",2);
   a.insert("3",3);
   a.display();
   a.remove(3);
   a.display();

}