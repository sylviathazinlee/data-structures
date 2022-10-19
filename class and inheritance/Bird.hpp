//Sylvia Lee Project 1 Professor Oyekoya
//August 30th, 2021
//Bird header file code implementation


#ifndef BIRD_H_
#define BIRD_H_
#include <iostream>
#include <string>
#include "Animal.hpp"


class Bird: public Animal
{
    public:
        Bird();//default constructor
        Bird(std::string name, bool domestic, bool predator): Animal(name, domestic, predator)
        {
            airborne_=false;
            aquatic_=false;

        };//parameterized constructor
        
        //display override
        void display() override;

        /** Checks to see if Bird airborne_ is true
        @return airborne_
        */
        bool isAirborne() const;

        /** Checks to see if Bird aquatic_ is true
        @return aquatic_
        */
        bool isAquatic() const;

        /** Mutates airborne_ and sets it to true
        @post airborne_ is set to true
        */
        void setAirborne();

        /** Mutates aquatic_ and sets it to true
        @post aquatic_ is set to true
        */
        void setAquatic();
        
    protected:
        bool airborne_;
        bool aquatic_;
};

#endif
