//Sylvia Lee Project 1 Professor Oyekoya
//August 30th, 2021
//Fish header file code implementation


#ifndef FISH_H_
#define FISH_H_
#include <string>
#include "Animal.hpp"
#include "Bird.hpp"
#include "Mammal.hpp"



class Fish: public Animal
{
    public:
        Fish();//default constructor
        Fish(std::string name, bool domestic, bool predator): Animal(name, domestic, predator)
        {
            venomous_=false;
        }; //parameterized constructor

        //display override
        void display() override;
        
        /** Checks to see if venomous_ is true
        @return venomous_
        */
        bool isVenomous() const;
        
        /** Mutates venomous_ and sets it to true
        @post venomous_ is set to true
        */
        void setVenomous();

    protected:
        bool venomous_;
};

#endif

