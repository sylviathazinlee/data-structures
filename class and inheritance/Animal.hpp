#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>


class Animal
{
    public:
        Animal();//default constructor
        Animal(std::string name, bool domestic , bool predator); //parameterized
        /**
        This is what makes the class abstract
        You will override this for each inherited class
        */
        virtual void display()=0;

        /** Gives you the animal's name
        @return the name_
        */
        std::string getName() const;

        /** Checks if animal is domestic
        @return true if domestic_ is true
        */
        bool isDomestic() const;

        /** Checks if animal is a predator
        @return true if predator_ is true
        */
        bool isPredator() const;

        /** Sets the animal's name to string name
        @param name of the animal you want to set it to
        */
        void setName(std::string name);

        /**
        Mutates the animal's domestic_ variable to true
        @post domestic_ is set to true
        */
        void setDomestic();
        
        /**
        Mutates the animal's predator_ variable to true
        @post predator_ is set to true
        */
        void setPredator();

    protected:
        std::string name_;
        bool domestic_;
        bool predator_;
}; 

#endif

