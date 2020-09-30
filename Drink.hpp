
#ifndef DRINK_HPP
#define DRINK_HPP
#include <iostream>
#include "Grocery.hpp"

class Drink : public Grocery
{
public:
    Drink(std::string name, double price, double weight);

private:
    void updateCost(); // updates total_price_
};

#endif