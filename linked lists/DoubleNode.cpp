//Sylvia Lee Project 3 Professor Oyekoya
//October 14th, 2021
//DoubleNode cpp file implementation

#include <iostream>
#include <string>

//default constructor, sets next_ and prev_ to nullptr
template <class ItemType>
DoubleNode<ItemType>:: DoubleNode() 
{
    next_=nullptr;
    prev_=nullptr;
}

/*
Parameterized Constructor, sets item_ to anItem, next_ 
to nextNodePtr, prev_ to previousNodePtr
*/
template <class ItemType>
DoubleNode<ItemType>:: DoubleNode(const ItemType &anItem, DoubleNode<ItemType> *nextNodePtr, DoubleNode<ItemType> *previousNodePtr)
{
    item_= anItem;
    next_=nextNodePtr;
    prev_=previousNodePtr;
}

//sets item_ equal to anItem parameter
template <class ItemType>
void DoubleNode<ItemType>:: setItem(const ItemType &anItem)
{
    item_=anItem;
}

//sets prev_ equal to previousNodePtr parameter     
template <class ItemType>                                                                    
void DoubleNode<ItemType>:: setPrevious(DoubleNode<ItemType> *previousNodePtr)
{
    prev_=previousNodePtr;
}

//sets next_ equal to nextNodePtr parameter
template <class ItemType>
void DoubleNode<ItemType>:: setNext(DoubleNode<ItemType> *nextNodePtr)
{
    next_=nextNodePtr;
}

//returns item_
template <class ItemType>
ItemType DoubleNode<ItemType>:: getItem() const
{
    return item_;
}

//returns next_
template <class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>:: getNext() const
{
    return next_;
}

//returns prev_
template <class ItemType>
DoubleNode<ItemType>* DoubleNode<ItemType>:: getPrevious() const
{
    return prev_;
}