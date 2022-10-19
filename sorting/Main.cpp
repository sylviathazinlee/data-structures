#include <iostream>
#include "Solutions.cpp"


int main()
{
  DoublyLinkedList<int> list;

  list.insert(10,1);
  list.insert(3,2);
  list.insert(7,3);
  list.display();

  solutions::bubbleSort(list, std::less<int>{});

  list.display();

}