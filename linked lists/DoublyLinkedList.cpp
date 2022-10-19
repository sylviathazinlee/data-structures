#include <iostream>
#include <string>

// default constructor, sets headPtr_ to null and itemCount_ to 0
template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList()
{
    itemCount_ = 0;
    headPtr_ = nullptr;
}

/*
    Copy constructor that will make an exact copy of the list parameter, aList.
    This will make a deep copy of the list in the given parameter.
    You must iterate through the callee list parameter and insert nodes from aList into the caller list (the current one that isn't the parameter)
*/
template <class ItemType>
DoublyLinkedList<ItemType>::DoublyLinkedList(const DoublyLinkedList &aList)
{
    itemCount_ = 0;
    headPtr_ = nullptr;
    DoubleNode<ItemType> *copy = aList.headPtr_;
    for (int i = 1; i <= aList.getSize(); i++)
    {
        insert(copy->getItem(), i);
        copy = copy->getNext();
    }
}

// destructor that calls the clear function
template <class ItemType>
DoublyLinkedList<ItemType>::~DoublyLinkedList()
{
    clear();
}

// return itemCount_
template <class ItemType>
int DoublyLinkedList<ItemType>::getSize() const
{
    return itemCount_;
}

/**
 * Description: finds the node at parameter pos
 * Pre: pos is a valid place in the list, otherwise nullptr will be returned
 * Post: returns a pointer to the node at pos
 **/
template <class ItemType>
DoubleNode<ItemType> *DoublyLinkedList<ItemType>::getAtPos(const int &pos) const
{
    // Guided by textbook
    bool canGetPos = (pos >= 1) && (pos <= itemCount_);

    if (!canGetPos)
    {
        return nullptr;
    }
    else
    {
        DoubleNode<ItemType> *currentPtr = headPtr_;
        for (int i = 1; i < pos; i++)
        {
            currentPtr = currentPtr->getNext();
        }

        return currentPtr;
    }
}

// return *headPtr_
template <class ItemType>
DoubleNode<ItemType> *DoublyLinkedList<ItemType>::getHeadPtr() const
{
    return headPtr_;
}

/* *
 * Description: inserts parameter item in caller list at parameter position
 *IMPORTANT: Position 1 is the first position, not 0
 * Pre: position is a valid place within the list, otherwise false will be returned
 * Post: returns true if the item has been inserted in the caller list
 * Handles edge case of an invalid position parameter
 * Case: Inserting into head of the list
 * Case: Inserting into rear of the list
 * Case: Inserting into a position that is not an extremity
 * */
template <class ItemType>
bool DoublyLinkedList<ItemType>::insert(const ItemType &item, const int &position)
{
    // Guided by lecture and textbook
    bool canInsert= (position >= 1) && (position <=itemCount_+1);

    if(canInsert)
    {
        DoubleNode<ItemType> *newnodePtr = new DoubleNode<ItemType>(item);
        if (position == 1)
        {
            if (headPtr_ != nullptr)
            {
                newnodePtr->setNext(headPtr_);
                headPtr_->setPrevious(newnodePtr);
                headPtr_ = newnodePtr;
            }
            headPtr_=newnodePtr;
        }
        else
        {
            DoubleNode<ItemType> *prevPtr = headPtr_;
            for (int i = 1; i<position-1; i++) //loop to get to position where we want to insert new node
            {
                prevPtr = prevPtr->getNext();
            }
            if (prevPtr->getNext() != nullptr)
            {
                newnodePtr->setNext(prevPtr->getNext());
                prevPtr->getNext()->setPrevious(newnodePtr);
            }
            prevPtr->setNext(newnodePtr);
            newnodePtr->setPrevious(prevPtr);
        }
        itemCount_++;
    }
    return canInsert;
}

/* *
 * Description: removes node at parameter position
 *IMPORTANT: Position 1 is the first position, not 0
 * Pre: position is a valid place within the list, otherwise false will be returned
 * Post: returns true if the item at position has been removed from the caller list
 * Handles edge case of invalid position parameter
 * Case: removing only node in list
 * Case: removing from the end
 * Case: removing from the beginning
 * Case: removing from a position that is not an extremity
 * */
template <class ItemType>
bool DoublyLinkedList<ItemType>::remove(const int &position)
{
    // Guided by textbook
    bool canRemove = (position >= 1) && (position <= itemCount_);
    if (canRemove)
    {
        DoubleNode<ItemType> *currPtr; // was originally =nullptr;
        if (position == 1)
        {
            currPtr = headPtr_;             // Remove the first node in the chain
            headPtr_ = headPtr_->getNext(); // Save pointer to node
        }
        else
        {
            DoubleNode<ItemType> *prevPtr = getAtPos(position - 1); // Find node that is before the one to delete
            currPtr = prevPtr->getNext();                           // Point to node to delete

            /*Disconnect indicated node from chain by connecting the
            prior node with the one after*/
            prevPtr->setNext(currPtr->getNext());
        }
        // currPtr->setNext(nullptr); //return node to system
        delete currPtr;
        currPtr = nullptr;
        itemCount_--; // decrease item count
    }
    return canRemove;
}

// returns true if itemCount_ is 0
template <class ItemType>
bool DoublyLinkedList<ItemType>::isEmpty() const
{
    return itemCount_ = 0;
}

/* *
 * Description: removes all items from the caller list
 * Traverse through the linked list and delete each individual node
 * Post: no nodes remain in the list and itemCount_ is at 0
 * */
template <class ItemType>
void DoublyLinkedList<ItemType>::clear()
{
    DoubleNode<ItemType> *node = headPtr_;
    for (int i = 1; i <= itemCount_; i++)
    {
        if (node != nullptr)
        {
            headPtr_ = headPtr_->getNext();
            delete node;
            node = headPtr_;
        }
    }
    itemCount_ = 0;
    delete node;
}

// Iteratively outputs the contents of the caller list on the console
// Example "A B C D E"
// Note how theres no space at the end
template <class ItemType>
void DoublyLinkedList<ItemType>::display() const
{
    DoubleNode<ItemType> *nodes = headPtr_;
    for (int i = 0; i < itemCount_; i++)
    {
        if (i != itemCount_ - 1)
        {
            std::cout << nodes->getItem() << " ";
        }
        else
        {
            std::cout << nodes->getItem() << "\n";
        }

        nodes = nodes->getNext();
    }
}

// Iteratively outputs the contents of the caller list backwards on the console
// Example if we had A B C D E we would instead display "E D C B A"
template <class ItemType>
void DoublyLinkedList<ItemType>::displayBackwards() const
{
    DoubleNode<ItemType> *nodes = headPtr_;
    for (int i = 1; i < itemCount_; i++) // loops through the nodes to get to the last
    {
        nodes = nodes->getNext();
    }

    for (int i = 0; i < itemCount_; i++)
    {
        std::cout << nodes->getItem() << " ";
        if(i==itemCount_-1)
        {
            std::cout << "\n";
        }
        nodes = nodes->getPrevious();
    }
}

// Reverses the list such that if my list was A B C D it will now be D C B A
// Remember to change both previous and next pointers
// Will be tested with both display and displayBackwards, make sure you have those working
template <class ItemType>
void DoublyLinkedList<ItemType>::invert()
{
}
