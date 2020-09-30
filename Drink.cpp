#include "Drink.hpp"

Drink::Drink(std::string name, double price, double weight) : Grocery(name, price, weight)
{
    updateCost();
}

void Drink::updateCost()
{
    //total_price_ <- product of: quantity, weight per liter, and price per liter
    total_price_ = quantity_ * ((unit_weight_ * 16) / 33.814) * unit_price_;
    //std::cout << "The drink costs: $" << total_price_ << std::endl;
}
