//Sylvia Lee Project 1 Professor Oyekoya
//August 30th, 2021
//Mammal cpp code implementation


#include "Mammal.hpp"
#include <iostream>
#include <string>


Mammal::Mammal() //Default constructor
{

}

//Checks to see if Mammal hair_ is true
bool Mammal::hasHair() const
{
    return hair_;
}

//Checks to see if Mammal airborne_ is true
bool Mammal::isAirborne() const
{
    return airborne_;
}

//Checks to see if Mammal aquatic_ is true
bool Mammal::isAquatic() const
{
    return aquatic_;
}

//Checks to see if Mammal toothed_ is true
bool Mammal::isToothed() const
{
    return toothed_;
}

//Checks to see if Mammal fins_ is true
bool Mammal::hasFins() const
{
    return fins_;
}

//Checks to see if Mammal tail_ is true
bool Mammal::hasTail() const
{
    return tail_;
}

//returns the amount of legs Mammal has
int Mammal::legs() const
{
    return legs_;
}

//Mutates hair_ and sets it to true
void Mammal::setHair() 
{
    hair_=true;
}

//Mutates airborne_ and sets it to true
void Mammal::setAirborne()
{
    airborne_=true;
}

//Mutates aquatic_ and sets it to true
void Mammal::setAquatic()
{
    aquatic_=true;
}

//Mutates toothed_ and sets it to true
void Mammal::setToothed()
{
    toothed_=true;
}

//Mutates fins_ and sets it to true
void Mammal::setFins()
{
    fins_=true;
}

//Mutates tail_ and sets it to true
void Mammal::setTail()
{
    tail_=true;
}

//Sets legs_ to the formal parameter legs
void Mammal::setLegs(int legs)
{
    legs_=legs;
}


/** @post displays mammal data in the form:
"animal_name is [not] domestic and [it is / is not] a predator,\n
it is [not] airborne and it is [not] aquatic,\n
it has [no] hair, [no] teeth, [no] fins, [no] tail and legs_ legs.\n”
*/

void Mammal::display()
{
    /*
    Ternary operator used. Eight strings created that would either 
    print is or is not depending on if the functions return true or false.
    */
    std:: string domes= isDomestic() ? "is": "is not";
    std:: string pred= isPredator() ? "it is" : "is not";
    std:: string air= isAirborne() ? "it is" : "it is not";
    std:: string aqua= isAquatic() ? "it is" : "it is not";
    std:: string hair= hasHair() ? "it has" : "it has no";
    std:: string teeth= isToothed() ? "" : "no";
    std:: string fins= hasFins() ? "" : "no ";
    std:: string tail= hasTail() ? "" : "no";
    

    std:: cout << name_ + " " << domes <<" domestic and "<< pred << " a predator,\n" << \
        air << " airborne and " << aqua << " aquatic,\n" << hair << " hair," << teeth \
        << " teeth, " << fins << "fins," << tail << " tail and " << legs_ << " legs.\n";

}