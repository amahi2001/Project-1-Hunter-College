#ifndef JUNKFOOD_HPP
#define JUNKFOOD_HPP

#include <iostream>
#include <string>
#include "Grocery.hpp"

class JunkFood : public Grocery
{
   public: 
    /**
   unit of price: dollars
   unit of weight: pounds (lb)
*/
   JunkFood(std::string name, double price, double weight);

/**
   total_price_ <- product of: quantity and price per unit
*/
private:
   void updateCost(); //which updates total_price_
};

#endif
