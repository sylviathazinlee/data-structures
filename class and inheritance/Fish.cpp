#include "Fish.hpp"
#include <iostream>
#include <string>

Fish::Fish()//default constructor
{
    
}

/** Checks to see if venomous_ is true
@return venomous_
*/
bool Fish::isVenomous() const
{
    return venomous_;
}

/** Mutates venomous_ and sets it to true
@post venomous_ is set to true
*/
void Fish::setVenomous()
{
    venomous_=true;
}

/** @post displays fish data in the form:
"animal_name is [not] domestic, [it is / is not] a predator\n
and it is [not] venomous.\n"
*/
void Fish::display() 
{
    /*
    Ternary operator used. Three strings created that would either 
    print is or is not depending on if the functions return true or false.
    */
    std:: string domes= isDomestic() ? "is": "is not";
    std:: string pred= isPredator() ? "it is" : "is not";
    std:: string venom= isVenomous() ? "it is": "it is not";

    std:: cout << name_ + " "<< domes <<" domestic, "<< pred << " a predator\n" <<"and "+venom+ " venomous.\n";


}
