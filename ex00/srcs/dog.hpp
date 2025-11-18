#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include "animal.hpp"

class Dog : public Animal {
private:
   
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();
};

#endif