#include <iostream>
#include "ShoppingCart.hpp"
#include "DynamicArray.hpp"

ShoppingCart ::ShoppingCart() : DynamicArray<Grocery *>()
{
    //initialize the current weight to 0;
    curr_contents_weight_ = 0; 
}

ShoppingCart::~ShoppingCart()
{
}

bool ShoppingCart::add(Grocery *new_entry) //add function
{
    double unit_wieght = new_entry->getUnitWeight(); // storing the unit weight of the caller into the file

    if ((unit_wieght + curr_contents_weight_) <= 350) // if the unit weight and the current weight are less than or equal to the max weight
                                                     // makes sure that adding extra weight won't tip over the cart =
    {
        switch (contains(new_entry))
        {
        case true: // if the item exists
            items_[getIndexOf(new_entry)]->incrementQuantity(); //add the item and increment the weight
            curr_contents_weight_ += unit_wieght;
            return true;
            break;
        case false: // if the item doesn't exist, add it by making space in dynamic array add and increment the weight
            DynamicArray::add(new_entry);
            curr_contents_weight_ += unit_wieght;
            return true;
            break;
        }
    } // if the item is too heavy or the cart won't be able to add , return false
    return false;
}

bool ShoppingCart::remove(Grocery *an_item)
{
    bool flag = contains(an_item);
    switch (flag)
    {
    case true: // if the item exists, remove it and decrement the weight, call garbageclear()
        items_[getIndexOf(an_item)]->decrementQuantity();
        curr_contents_weight_ = curr_contents_weight_ - an_item->getUnitWeight();
        garbageClear();
        return true;
        break;
    case false: // if the item doesn't exist return false
        return false;
        break;
    }
}

void ShoppingCart ::garbageClear() 
{
    for (int i = 0; i < item_count_; i++) //loops throught the # of items
    {
        switch (items_[i]->getQuantity()) 
        {
            case 0: // if an empty item ios found, remove it with dynamic array
            DynamicArray::remove(items_[i]);
            break;    
        }
    }
}

double ShoppingCart::checkout()
{
    if (item_count_ == 0)
    {
        std::cout << "Your cart is empty!" << std::endl;
        return 0;
    }

    double total = 0;
    for (size_t i = 0; i < item_count_; i++)
    {
        std::cout << "\n"
                  << std::setw(10) << std::left << items_[i]->getName() << "\t" << items_[i]->getQuantity()
                  << "\t" << std::fixed << std::setprecision(2)
                  << items_[i]->getTotalPrice();
        total += items_[i]->getTotalPrice();
    }
    std::cout << std::setfill('-') << std::setw(40) << "\n"
              << std::endl
              << "Total:                  "
              << total << std::endl
              << std::endl;
    clear();
    return total;
}

double ShoppingCart::getCurrentWeight() //getter for getCurrentWeight()
{
    return curr_contents_weight_;
}