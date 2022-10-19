//Sylvia Lee Project 1 Professor Oyekoya
//August 30th, 2021
//Animal cpp code implementation


#include "Animal.hpp"
#include <iostream>
#include <string>


Animal::Animal()//default constructor
{

}

Animal::Animal(std::string name, bool domestic, bool predator)//parameterized constructor
{
    name_=name;
    domestic_=domestic;
    predator_=predator;
}

/** Gives you the animal's name
@return the name_
*/
std::string Animal::getName() const
{
    return name_;
}

/** Checks if animal is domestic
@return true if domestic_ is true
*/
bool Animal::isDomestic() const
{
    return domestic_;
}

/** Checks if animal is a predator
@return true if predator_ is true
*/
bool Animal::isPredator() const
{
    return predator_;
}

/** Sets the animal's name to string name
@param name of the animal you want to set it to
*/
void Animal::setName(std::string name)
{
    name_=name;
}

/**
Mutates the animal's domestic_ variable to true
@post domestic_ is set to true
*/
void Animal::setDomestic()
{
    domestic_=true;
}

/**
Mutates the animal's predator_ variable to true
@post predator_ is set to true
*/
void Animal::setPredator()
{
    predator_=true;
}



