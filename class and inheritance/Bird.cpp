#include "Bird.hpp"
#include <iostream>
#include <string>


Bird::Bird()
{

} //default constructor

/** Checks to see if Bird airborne_ is true
@return airborne_
*/
bool Bird::isAirborne() const
{
    return airborne_;
}

/** Checks to see if Bird aquatic_ is true
@return aquatic_
*/
bool Bird::isAquatic() const
{
    return aquatic_;
}
/** Mutates airborne_ and sets it to true
@post airborne_ is set to true
*/
void Bird::setAirborne()
{
    airborne_=true;
}

/** Mutates aquatic_ and sets it to true
@post aquatic_ is set to true
*/
void Bird::setAquatic()
{
    aquatic_=true;
}

/** @post displays bird data in the form:
“animal_name is [not] domestic and [it is / is not] a predator,\n
it is [not] airborne and it is [not] aquatic.\n”
*/
void Bird::display() 
{
        /*
        Ternary operator used. Four strings created that would either 
        print is or is not depending on if the functions return true or false.
        */
        std:: string domes = isDomestic() ? "is" : "is not";
        std:: string pred = isPredator() ? "it is" : "is not";
        std:: string air = isAirborne() ? "it is" : "it is not";
        std:: string aqua = isAquatic() ? "it is" : "it is not";

        std:: cout << name_ + " "<< domes <<" domestic and "<< pred << " a predator,\n" << air << " airborne and " << aqua << " aquatic.\n";
        
}



