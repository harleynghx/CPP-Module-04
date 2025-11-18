#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include <string>


class Cat : public Animal {   
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    virtual void makeSound() const;
};

#endif