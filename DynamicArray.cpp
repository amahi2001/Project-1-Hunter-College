/****************************************************************************************************************************
Title          :   DynamicArray.cpp
Auhor          :   Team FBK
Modified By    :   ** ENTER YOUR NAME **
Description    :   implementation file of a dynamically resizeable array class
Dependencies   :   DynamicArray.hpp
****************************************************************************************************************************/

#include <iostream>
using namespace std;
/****************************************************** Public Methods *****************************************************/

/* Default Constructor */
template <class T>
DynamicArray<T>::DynamicArray() : current_capacity_{1}, item_count_{0} // initializer list
{
    items_ = new T[current_capacity_]; /* initializes items_ to a dynamically 
                                           allocated array of size 
                                           current_capacity_ */
}

/* Destructor */
template <class T>
DynamicArray<T>::~DynamicArray()
{
    clear(); /* clear() releases dynamically allocated
                   memory - we want to repeat this behavior
                   in other methods, which is why the code 
                   in clear() is in its own function as 
                   opposed to simply being in the destructor */
}

/** 
    implements addition of an item of type T to the end of the caller
    @param new_entry to be added to the caller
    @post if successful, the caller contains the new_entry
    @return true if the addition was successful; false otherwise
*/
template <class T>
bool DynamicArray<T>::add(const T &new_entry)
{
    try
    {
        if (items_ == nullptr)
        {
            items_ = new T[1];
            current_capacity_ = 1;
            items_[0] = new_entry;
            items_[item_count_] = new_entry;
            item_count_ = 1;
            return true;
        }
        /*if items_ is a nullptr, set items_  equal to a new array of type T and a size of 1
        Set the curr capacity to 1 and then add the item we want to add
        Then set item_count_ to 1 */

        switch(item_count_)
        {
            case current_capacity_: 
                resize(); 
                break;
        }
        /*if (item_count_ == current_capacity_)
        {
            resize();
            // items_[item_count_] = new_entry;
        }*/ 
        items_[item_count_] = new_entry;

        item_count_ = item_count_ + 1;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

/**
    returns whether the caller contains parameter 
        T an_entry by checking whether its index 
        is above sentinel value -1
*/
template <class T>
bool DynamicArray<T>::contains(const T &an_entry) const
{
    return getIndexOf(an_entry) > -1;
}

/**
    returns whether the caller contains no items
 */
template <class T>
bool DynamicArray<T>::isEmpty() const
{
    return item_count_ == 0;
}

/**
    reassigns the caller's items_ array to parameter new_items_arr
    @param new_items_arr is a pointer to the first element of the
        array to which items_ will be assigned
    @param size is the number of entries in new_items_arr
    @post if successful, the items_ array has been assigned to new_items_arr
    @return true if the reassignment was successful; false otherwise
*/
template <class T>
bool DynamicArray<T>::setItems(T *new_items_arr, const size_t &size)
{
    try
    {
        clear();
        item_count_ = size;
        items_ = new_items_arr;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

/** 
    implements the removal of the first instance of parameter 
        an_item from the caller
    @param an_item to be removed from the caller
    @post if successful, the first instance of an_item has been 
        has been removed from the dynamic array 
    @return true if the removal was successful; false otherwise
*/
template <class T>
bool DynamicArray<T>::remove(const T &an_item)
{
    try
    {
         // getting the index i an item
        int item_index = getIndexOf(an_item);
        item_count_ = item_count_ - 1; //decrementing the item count
        //creating a new array that points to the position of current capacity
        T *new_array = new T [current_capacity_]; 
        
        if (item_index != -1) // if the item exists
        {
            int i,j;
            for (i=item_index; i < item_count_; i++) // looping through the the # of items through item and item index
            {
                new_array[i] = items_[i+1]; // settinf the new array spaces to the spaces 1 space above in items
            }
            // fixing the spacing issues within the item created by the space
            for (j =0; j < item_index; j++)
            {
                new_array[j] = items_[j]; 
            }
        }
        //deallocating memory and redefining items
        delete [] items_ ; 
        items_ = new_array;
        new_array = nullptr;

        //resize the aarray if it 1/4 the current capacity
        if (item_count_ < (current_capacity_ / 4))
        {
            resize();
        }

        //cout << "item count is " << item_count_
        //     << " size of array is " << current_capacity_ << endl;
        return true;
    }
    catch (...)
    {
        return false;
    }
}

/* Accessor: current_capacity_ */
template <class T>
size_t DynamicArray<T>::getCapacity() const
{
    return current_capacity_;
}

/* Accessor: item_count_ */
template <class T>
size_t DynamicArray<T>::getOccupiedSpaces() const
{
    return item_count_;
}

/* Accessor: items_ */
template <class T>
T *DynamicArray<T>::getItems() const
{
    return items_;
}

/**
    Releases dynamically allocated data and 
        handles the potential dangling pointer 
        that could be items_
*/
template <class T>
void DynamicArray<T>::clear()
{
    delete[] items_;
    item_count_ = 0;
    items_ = nullptr;
    current_capacity_ = 1;
}

/***************************************************** Private Methods *****************************************************/

/**
    returns whether the caller is full
    @pre item_count_ > -1
    @return true if the caller is at capacity; false otherwise
*/
template <class T>
bool DynamicArray<T>::atCapacity() const
{
    return item_count_ == current_capacity_;
}

/**
    @param target an object of type T that will be 
        parsed sought after in the caller
    @return the index of target if it is in the caller;
        -1 otherwise 
*/
template <class T>
int DynamicArray<T>::getIndexOf(const T &target) const
{
    bool found = false;
    int result = -1;
    int search_index = 0;

    // If the bag is empty, item_count_ is zero, so loop is skipped
    while (!found && (search_index < item_count_))
    {
        if (items_[search_index] == target)
        {
            found = true;
            result = search_index;
        }
        else
        {
            search_index++;
        } // end if
    }     // end while
    return result;
} // end getIndexOf

/* 
    copies the elements of items_ into a new dynamically allocated
        array which is either twice or half the size of current_capacity_
        depending on whether the resize was called because of an addition
        or a removal. If an item was added and items_ is now at capacity,
        double the size of the array. If an item was removed and 
        item_count_ < ( current_capacity / 4 ), reduce the size of the array
        by half.
*/
template <class T>
void DynamicArray<T>::resize()
{
    //if the item count is equal to the current capacity
    if (item_count_ == current_capacity_)
    {
        //doubling the current capacity
        current_capacity_ = current_capacity_ * 2;
        T *new_array = new T[current_capacity_]; // creating a new array and setting it to the size of the capacity
        for (int i = 0; i < item_count_; i++) // setting the new array equal to the items
        {
            new_array[i] = items_[i];
        }
        delete[] items_; //deallocating items and setting it equal to the new array
        items_ = new_array;
        new_array = nullptr;
    }

    //if the item count is less than a quarter of the current capacity
    else if (item_count_ < (current_capacity_ / 4))
    {
        // make a new array that is 1/2 the size
        current_capacity_ = current_capacity_ / 2;
        T *new_array = new T[current_capacity_];
        for (int i = 0; i < item_count_; i++)
        {
            new_array[i] = items_[i]; // storing the values
        }
        delete[] items_;
        items_ = new_array;
        new_array = nullptr;
    }
}