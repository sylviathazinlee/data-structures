// Sylvia Lee Project 4 Professor Oyekoya
// November 2nd, 2021
// Solutions cpp file implementation (Sorting)

#include "DoublyLinkedList.hpp"
#include <string>

namespace solutions
{
    /* Bubblesort */
    template <typename Comparable, typename Comparator>
    void bubbleSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {
      for(int i=1; i<a_list.getSize(); i++)
      {
        for(int j=i+1; j<=a_list.getSize(); j++)
        {
          DoubleNode<Comparable>* temp = a_list.getAtPos(i); 
          DoubleNode<Comparable>* temp2 = a_list.getAtPos(j); 
          if(comp(temp2->getItem(),temp->getItem()))
          {
            a_list.swap(i,j);
          }
        }
      }
    }

    /* Insertionsort */
    template <typename Comparable, typename Comparator>
    void insertionSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {
      /*
      for(int right=1; right<a_list.getSize(); right++)
      {
        DoubleNode<Comparable>* temp = a_list.getAtPos(right); 
        for(int left=right-1; left>=0; left--)
        {
          DoubleNode<Comparable>* prev = a_list.getAtPos(left); 
          if (comp(prev->getItem(), temp->getItem()))
          {
            a_list.swap(left,right);
          }
        }
      }
      */

      for(int i=1; i<a_list.getSize(); i++)
      {
        DoubleNode<Comparable>* temp = a_list.getAtPos(i); 
        int j=i-1;
        DoubleNode<Comparable>* prev = a_list.getAtPos(j); 
        while(j>=0 && comp(prev->getItem(), temp->getItem()))
        {
          a_list.swap(j,i);
          j--;
        }
      }
    }

    /* Merge */
    template <typename Comparable, typename Comparator>
    void merge(DoublyLinkedList<Comparable> &a_list, int left_index, int middle_index, int right_index, const Comparator &comp)
    {

    }

    /* Mergesort */
    template <typename Comparable, typename Comparator>
    void mergeSort(DoublyLinkedList<Comparable> &a_list, int left_index, int right_index, const Comparator &comp)
    {

    }

    /* Mergesort Wrapper */
	//this is what you use to test
    template <typename Comparable, typename Comparator>
    void mergeSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {
		  mergeSort(a_list, 1, a_list.getSize(),comp);
    }

}; // namespace solutions