
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
      for(int i=2; i<a_list.getSize()+1; i++)//start from 2 which is the second element in the list
      {
        int temp = a_list.getAtPos(i)->getItem(); 
        int j=i-1;
        while(j>0 && comp(temp, a_list.getAtPos(j)->getItem()))
        {
          a_list.getAtPos(j+1)->setItem(a_list.getAtPos(j)->getItem());
          j--;
        }
        a_list.getAtPos(j+1)->setItem(temp);
      }
    }

    /* Merge */
    template <typename Comparable, typename Comparator>
    void merge(DoublyLinkedList<Comparable> &a_list, int left_index, int middle_index, int right_index, const Comparator &comp)
    {
       //Guided by textbook pg. 316-317
       int size= a_list.getSize();
       int temp[size];

       //splits the list into parts
       int first=left_index;
       int last=middle_index;
       int first2=middle_index+1;
       int last2=right_index;

       int index=first;
       while((first<=last) && (first2<=last2))
       {
         if(comp(a_list.getAtPos(first)->getItem(),a_list.getAtPos(first2)->getItem()))
         {
            temp[index]=a_list.getAtPos(first)->getItem();
            first++;
         }
         else
         {
           temp[index]=a_list.getAtPos(first2)->getItem();
           first2++;
         }
         index++;
       }

       while(first<=last)
       {
         temp[index]=a_list.getAtPos(first)->getItem();
         first++;
         index++;
       }

       while(first2<=last2)
       {
         temp[index]=a_list.getAtPos(first2)->getItem();
         first2++;
         index++;
       }

       //put elements in temporary array back into the linked list
       for(index=left_index; index<=right_index; index++)
       {
         a_list.getAtPos(index)->setItem(temp[index]);
       }
    }

    /* Mergesort */
    template <typename Comparable, typename Comparator>
    void mergeSort(DoublyLinkedList<Comparable> &a_list, int left_index, int right_index, const Comparator &comp)
    {
      //Guided by textbook pg. 316-317
      if(left_index<right_index)
      {
        int mid= left_index+ (right_index-left_index)/2;
        mergeSort(a_list,left_index,mid,comp);
        mergeSort(a_list,mid+1,right_index,comp);
        merge(a_list, left_index,mid,right_index,comp);
      }
    }

    /* Mergesort Wrapper */
	//this is what you use to test
    template <typename Comparable, typename Comparator>
    void mergeSort(DoublyLinkedList<Comparable> &a_list, const Comparator &comp)
    {
	    mergeSort(a_list, 1, a_list.getSize(),comp);
    }

}; // namespace solutions
