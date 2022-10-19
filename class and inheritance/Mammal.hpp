#ifndef MAMMAL_H_
#define MAMMAL_H_
#include <string>
#include "Animal.hpp"


class Mammal:public Animal
{
    public:
        Mammal();
        Mammal(std::string name, bool domestic, bool predator): Animal(name, domestic, predator)
        {
            hair_=false;
            airborne_=false;
            aquatic_=false;
            toothed_=false;
            fins_=false;
            tail_=false;
            legs_=0;

        }; //parameterized constructor
        
        void display() override;
        bool hasHair() const;
        bool isAirborne() const;
        bool isAquatic() const;
        bool isToothed() const;
        bool hasFins() const;
        bool hasTail() const;
        int legs() const;
        void setHair();
        void setAirborne();
        void setAquatic();
        void setToothed();
        void setFins();
        void setTail();
        void setLegs(int legs);

    protected:
        bool hair_;
        bool airborne_;
        bool aquatic_;
        bool toothed_;
        bool fins_;
        bool tail_;
        int legs_;
}; 

#endif
