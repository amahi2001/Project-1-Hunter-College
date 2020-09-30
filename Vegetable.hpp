#ifndef VEGETABLE_
#define VEGETABLE_

#include "Grocery.hpp"
#include <iostream>

class Vegetable : public Grocery
{
public:
    /**
   unit of price: dollars
   unit of weight: pounds (lb)
*/
    Vegetable(std::string name, double price, double weight); 

    /**
   total_price_ <- product of: quantity, weight per item, 
                                                and price per pound
*/
private:
    void updateCost(); // updates total_price_
};


#endif