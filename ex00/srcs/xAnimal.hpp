#ifndef XANIMAL_HPP
#define XANIMAL_HPP

#include <string>
#include <iostream>


class xAnimal {
protected:
    std::string _type;
   
public:
    xAnimal();
    xAnimal(const xAnimal& other);
    xAnimal& operator=(const xAnimal& other);
    virtual ~xAnimal();

    virtual void makeSound() const;
    std::string getType() const;
};


#endif