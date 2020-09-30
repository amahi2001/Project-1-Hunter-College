
#include "JunkFood.hpp"

JunkFood :: JunkFood(std::string name, double price, double weight) : Grocery(name, price, weight) 
{
    updateCost();
}

void JunkFood :: updateCost()
{
    total_price_ = quantity_ * unit_price_; 
    //cout << "junkfood costs: $" <<total_price_ << endl; 
}
