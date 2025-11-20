#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
protected:
    std::string _type;
   
public:
    Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual~Animal();

    //? adding  = 0 makes it a pure virtual
    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif