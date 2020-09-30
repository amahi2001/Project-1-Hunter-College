#ifndef ShoppingCart_HPP
#define ShoppingCart_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include "Grocery.hpp"
#include "DynamicArray.hpp"

class ShoppingCart : public DynamicArray<Grocery *>
{
public:
   /* Default Constructor */
   ShoppingCart();

   /** 
        must call the destructor of DynamicArray
    */
   ~ShoppingCart();

   /**
      adds new_entry to the caller; if the entry
      already exists in the caller, increment
      quantity_ in the object, and increment 
      the curr_contents_weight_ of the caller
      by the unit_weight_ of the added item.
       
    @pre    :   the addition of the weight of 
                  new_entry does not bring the
                  curr_contents_weight_ over the 
                  carrying capacity
            
    @return :   true if the addition is successful            
    */
   bool add(Grocery *new_entry);

   /**  
      removes the first instance of an_item from the caller; 
      if the entry already exists in the caller, decrement
      quantity_ in the object, and decrement the 
      curr_contents_weight_ of the caller by the 
      unit_weight_ of the added item.
      --> !!!THIS FUNCTION MUST CALL garbageClear()!!! <--
      @return :   true if the addition is successful            
   */
   bool remove(Grocery *an_item);

   /** displays shopping cart contents in required format */
   double checkout();

   /** 
      iterates through caller and removes items whose quantity_ == 0
      --> !!!THIS FUNCTION MUST CALL DynamicArray::remove()!!! <--
      @post   :   every item in the caller has quantity_ >= 1
   */
   void garbageClear();

   /* Getter: curr_contents_weight_ */
   double getCurrentWeight();

private:
   double curr_contents_weight_;
};
#endif