//Sylvia Lee Project 5 Professor Oyekoya
//November 23rd, 2021
//PriorityNode cpp file implementation

#include <iostream>

/* Default Constructor */
template<typename ItemType>
PriorityNode<ItemType>::PriorityNode()
{
    priority_=0;
    next_=nullptr;
}

/* Parameterized Constructor */
template<typename ItemType>
PriorityNode<ItemType>::PriorityNode(const ItemType& an_item)
{
    item_=an_item;
    priority_=0;
    next_=nullptr;
}

/* Parameterized Constructor */
template<typename ItemType>
PriorityNode<ItemType>::PriorityNode(const ItemType& an_item, int priority)
{
    item_=an_item;
    priority_=priority;
    next_=nullptr;
}

/* Parameterized Constructor */
template<typename ItemType>
PriorityNode<ItemType>::PriorityNode(const ItemType& an_item, int priority, PriorityNode<ItemType>* next_node_ptr)
{
    item_=an_item;
    priority_=priority;
    next_=next_node_ptr;
}

/* Setter: item_ */
template<typename ItemType>
void PriorityNode<ItemType>::setItem(const ItemType& an_item)
{
    item_=an_item;
}

/* Setter: priority_ */
template<typename ItemType>
void PriorityNode<ItemType>::setPriority(const int priority)
{
    priority_=priority;
}

/* Setter: next_ */
template<typename ItemType>
void PriorityNode<ItemType>::setNext(PriorityNode<ItemType>* next_node_ptr)
{
    next_=next_node_ptr;
}

/* Accessor: item_ */
template<typename ItemType>
ItemType PriorityNode<ItemType>::getItem() const
{
    return item_;
}

/* Accessor: priority_ */
template<typename ItemType>
int PriorityNode<ItemType>::getPriority() const
{
    return priority_;
}

/* Accessor: next_ */
template<typename ItemType>
PriorityNode<ItemType>* PriorityNode<ItemType>::getNext() const
{
    return next_;
}
