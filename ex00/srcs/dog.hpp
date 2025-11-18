#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "animal.hpp"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    virtual void makeSound() const;
};

#endif