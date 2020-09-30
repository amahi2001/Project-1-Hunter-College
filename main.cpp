
#include "Vegetable.hpp"
#include "Drink.hpp"
#include "JunkFood.hpp"
#include "DynamicArray.hpp"
#include "ShoppingCart.hpp"

using namespace std;

int main()
{/*
    DynamicArray<int> abroot;
    abroot.add(1);
    abroot.add(2);
    abroot.add(3);
    abroot.add(4);
    abroot.add(5);
    /////////////////
    ////////////////
    abroot.remove(1); 
    abroot.remove(2);
    abroot.remove(3); 
    abroot.remove(4); 
    abroot.remove(5);
    /////////////////
    ////////////////
    */ 
    
    string jelly = "hello";
    //Drink hello(jelly, 10.0, 10.0);
    Vegetable nello(jelly, 10.0, 10.0);

    ShoppingCart cart; 
    Grocery *boi = &nello;
    cart.add(boi); 
    cart.add(boi);
    cart.add(boi);
    cart.checkout();
}
