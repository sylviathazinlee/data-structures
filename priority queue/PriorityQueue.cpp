//Sylvia Lee Project 5 Professor Oyekoya
//November 23rd, 2021
//PriorityQueue cpp file implementation

#include <iostream>

/* Default Constructor */
template<typename ItemType>
PriorityQueue<ItemType>::PriorityQueue()
{
    back_=nullptr;
    front_=nullptr;
    item_count=0;
}


/* Copy Constructor */
template<typename ItemType>
PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue<ItemType>& a_priority_queue)
{
    back_=nullptr;
    front_=nullptr;
    item_count=0;

    PriorityNode<ItemType> *temp=a_priority_queue.front_;

    //starts at 1
    for(int i=1; i<=a_priority_queue.size(); i++)
    {
        if(front_==nullptr)
        {
            front_=new PriorityNode<ItemType>(temp->getItem(), temp->getPriority());
            back_=front_;
        }
        else
        {
            back_->setNext(new PriorityNode<ItemType>(temp->getItem(), temp->getPriority()));
            back_=back_->getNext();
        }
        temp=temp->getNext();
    }
}


/* Destructor: Releases memory */
template<typename ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
{
    while(front_!=nullptr)
    {
        PriorityNode<ItemType>* temp=front_;
        front_=front_->getNext();
        delete temp;
    }
    back_=nullptr;
}

/* Inserts node based on given item and priority into queue in order of priority.
   Less value equals greater priority
*/
template<typename ItemType>
void PriorityQueue<ItemType>::enqueue(const ItemType& new_entry, int priority)
{
    PriorityNode<ItemType>* newNodePtr= new PriorityNode<ItemType>(new_entry, priority);
    if(isEmpty()==true)
    {
        front_=newNodePtr;
        back_=newNodePtr;
    }
    else
    {
        if(front_->getPriority()>priority)
        {
            newNodePtr->setNext(front_);
            front_=newNodePtr;
        }
        else
        {
            PriorityNode<ItemType>* temp=front_;
            while(temp->getNext() != nullptr && temp->getNext()->getPriority() <= priority)
            {
                temp=temp->getNext();
            }
            
            newNodePtr->setNext(temp->getNext());
            temp->setNext(newNodePtr);
        }
    }

    item_count++;
}

/* Removes node from queue*/
template<typename ItemType>
void PriorityQueue<ItemType>::dequeue()
{
    if(isEmpty()==false)
    {
        PriorityNode<ItemType>* temp=front_;
        front_=front_->getNext();
        delete temp;
        item_count--;
    }
}

/* Accessor: front_->getItem() */
template<typename ItemType>
ItemType PriorityQueue<ItemType>::front() const 
{
    return front_->getItem();
}

/* Accessor: front_ */
template<typename ItemType>
PriorityNode<ItemType>* PriorityQueue<ItemType>::getFrontPtr() const
{
    return front_;
}

/* Accessor: item_count */
template<typename ItemType>
int PriorityQueue<ItemType>::size() const 
{
    return item_count;
}

/* Accessor: itemCount_ == 0 ? */
template<typename ItemType>
bool PriorityQueue<ItemType>::isEmpty() const
{
    return (item_count==0); 
}
