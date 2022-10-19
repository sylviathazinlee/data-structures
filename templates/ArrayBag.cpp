//Sylvia Lee Project 2 Professor Oyekoya
//September 20th, 2021
//ArrayBag cpp file implementation


#include "ArrayBag.hpp"
#include <iostream>
#include <string>


//default constructor
template<class ItemType>
ArrayBag<ItemType>:: ArrayBag()
{
    item_count_=0;
}

/**
    @return item_count_ : the current size of the bag
**/
template<class ItemType>
int ArrayBag<ItemType>:: getCurrentSize() const
{
    return item_count_;
}

/**
    @param target to be found in items_
    @return either the index target in the array items_ or -1,
    if the array does not contain the target.
**/
template <class ItemType>
int ArrayBag<ItemType>:: getIndexOf(const ItemType &target) const
{
    bool isFound=false;
    int result= -1;
    int searchIndex=0;

    while(!isFound && (searchIndex<item_count_))
    {
        if(items_[searchIndex]==target)
        {
            isFound=true;
            result=searchIndex;
        }
        else
        {
            searchIndex++;
        }
    }
    return result;
}

/**
    @return true if item_count_ == 0, false otherwise
**/
template <class ItemType>
bool ArrayBag<ItemType>:: isEmpty() const
{
    if(item_count_==0)
    {
        return true;
    }
    else
    { 
        return false;
    }
}

/**
    @return true if new_entry was successfully added to items_, false otherwise
**/
template <class ItemType>
bool ArrayBag<ItemType>:: add(const ItemType &new_entry)
{
    bool hasRoom= (item_count_ < DEFAULT_CAPACITY);
    if(hasRoom)
    {
        items_[item_count_]= new_entry;
        item_count_++;
    }
    return hasRoom;
}

/**
    @return true if an_entry was successfully removed from items_, false otherwise
**/
template<class ItemType>
bool ArrayBag<ItemType>:: remove(const ItemType &an_entry)
{
    int index= getIndexOf(an_entry);
    bool canRemove= (isEmpty()==false && index>=0);
    if(canRemove)
    {
        item_count_--;
        items_[index]=items_[item_count_];
    }
    return canRemove;
}

/**
    @post item_count_ == 0
**/
template <class ItemType>
void ArrayBag<ItemType>:: clear()
{
    item_count_=0;
}

/**
    @return true if an_entry is found in items_, false otherwise
**/
template<class ItemType>
bool ArrayBag<ItemType>:: contains(const ItemType &an_entry) const
{
    bool isFound= getIndexOf(an_entry) >= 0;
    if(isFound)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
    @return the number of times an_entry is found in items_
**/
template<class ItemType>
int ArrayBag<ItemType>:: getFrequencyOf(const ItemType &an_entry) const
{
    int count=0;
    for(int i=0; i<item_count_; i++)
    {
        if(items_[i]==an_entry)
        {
            count++;
        }
    }
    return count;
}

/**
    @return a vector having the same contents as items_
**/
template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>:: toVector() const
{
    std::vector<ItemType> bagContents;
    for(int i=0; i<item_count_; i++)
    {
        bagContents.push_back(items_[i]);
    }
    return bagContents;
}

/**
    @post prints the contents of items_ to the standard output separated by commas and followed by a new line.
    Example: A, B, C, D, E\n
    Note how there is no comma and space for the last item.
**/
template <class ItemType>
void ArrayBag<ItemType>:: display() const
{

    for(int i=0; i<item_count_; i++)
    {
        std:: cout << items_[i];
        if(i != item_count_-1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "\n";
}

/**
    duplicate all the items in the bag 
    meaning that for every item in the bag we add another copy of it. 
    Example: we originally have [A, B] and after duplication we have [A, B, A, B] or [A, A, B, B] or how ever order you want so long as there are 2 A's and 2 B's
    Return true if successfully duplicated 
    but return false if there is nothing to duplicate or if we go above the DEFAULT_CAPACITY which is 10 for this project
**/
template <class ItemType>
bool ArrayBag<ItemType>:: duplicateItems()
{
    bool canDuplicate= ((item_count_*2)<DEFAULT_CAPACITY && isEmpty()==false);
    if(canDuplicate)
    {
        int item_count_original=item_count_;
        for(int i=0; i<item_count_original; i++)
        {
            add(items_[i]);
        }
    }
    return canDuplicate;
}

/**
    @post every instance of an_entry is removed
**/
template <class ItemType>
void ArrayBag<ItemType>:: removeAllInstances(const ItemType &an_entry)
{
    if(isEmpty()==false)
    {
        for (int i = 0; i < item_count_; i++)
        {
            if(items_[i]==an_entry)
            {
                remove(items_[i]);
            }
        }
    }
}


/**
    @return true if we managed to remove all items that have duplicates in the bag
    Example: a duplicate would be [A, B, C, C, D, D, D, E]
    What we should have after running this function: [A, B, C, D, E] (may be out of order depending on how you do it, that doesn't matter)
    @return false if there are 1 or less items in the bag
**/
template <class ItemType>
bool ArrayBag<ItemType>::removeDuplicates()
{
    bool canRemoveDuplicates= item_count_>=1;
    if(canRemoveDuplicates)
    {
        for(int i=0; i<item_count_-1; i++)
        {
            for(int j=i+1; j<item_count_; j++)
            {
                if(items_[i]==items_[j])
                {
                    remove(items_[j]);
                    j--;
                }
            }
        }
    }
    return canRemoveDuplicates;
}

/* ---------- OPERATOR OVERLOADS ----------*/

/** 
    implements Set Union. The union of two sets A and B is the set of elements which are in A, in B, or in both A and B.  
	@param a_bag to be combined with the contents of this (the calling) bag
	@post adds as many items from a_bag as space allows    
**/
template <class ItemType>
void ArrayBag<ItemType>:: operator+=(const ArrayBag<ItemType> &a_bag)
{
    for(int i=0; i<a_bag.getCurrentSize(); i++)
    {
        if(!contains(a_bag.items_[i]))
        {
            add(a_bag.items_[i]);
        }
    }
}

/** 
    implements Set Difference  The (set) difference between two sets A and B is the set that consists of the elements of A which are not elements of  B 
	@param a_bag to be subtracted from this (the calling) bag
	@post removes all data from items_ that is also found in a_bag
    Example if A has [1, 2, 3, 4, 5] and B has [4, 5, 6, 7], then A-=B will result in A containing [1, 2, 3] and B remaining the same
**/
template <class ItemType>
void ArrayBag<ItemType>:: operator-=(const ArrayBag<ItemType> &a_bag)
{

    for(int i=0; i<a_bag.getCurrentSize(); i++)
    {
        if(contains(a_bag.items_[i]))
        {
            remove(a_bag.items_[i]);
        }
    }
}

/** 
    implements Set Intersection  The intersection of two sets A and B is the set that consists of the elements that are in both A and B 
	@param a_bag to be intersected with this (the calling) bag
	@post items_ no longer contains data not found in a_bag    
    Example if bag A has [1,2,3,4,5] and Bag B has [7,8,5,9] then A /= B will result in A containing only 5 since 5 is found in both bag A and bag B
**/
template <class ItemType>
void ArrayBag<ItemType>:: operator/=(const ArrayBag<ItemType> &a_bag)
{
    bool hasContent;
    int item_count_original=item_count_;
    if(isEmpty()==false && a_bag.isEmpty()==false)
    {
        for(int i =0; i < item_count_original; i++)
        {
        
            for(int j =0; j < a_bag.getCurrentSize(); j++)
            {
                if(items_[i] == a_bag.items_[j])
                {
                    hasContent= true;
                    break;
                }
                else
                {
                    hasContent= false;
                }
            }
            if(hasContent == false)
            {
                remove(items_[i]);
            }
        }   
    }


    /*CONCISE AND EFFICIENT WAY
        int originalitemcount= item_count_;
        for(int i=0; i<originalitemcount; i++)
        {
            if(contains(items_[i])==true && a_bag.contains(items[i])==false)
            {
                remove(items_[i]);
            }
        }
    */
}


