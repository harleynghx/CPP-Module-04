#ifndef XCAT_HPP
#define XCAT_HPP

#include <string>
#include <iostream>
#include "xAnimal.hpp"


class xCat : public xAnimal {
public:
    xCat();
    xCat(const xCat& other);
    xCat& operator=(const xCat& other);
    ~xCat();

    void makeSound() const {
    std::cout << "OIIA OIIA" << std::endl;
}
};



#endif