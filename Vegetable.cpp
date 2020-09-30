
#include "Vegetable.hpp"



Vegetable:: Vegetable(std::string name, double price, double weight): Grocery( name,  price,  weight)
{
  updateCost();
}

void Vegetable :: updateCost() 
{
  total_price_ = quantity_ * unit_price_ * unit_weight_;
  //cout << "Vegetables cost: $" << total_price_ << endl;
}

