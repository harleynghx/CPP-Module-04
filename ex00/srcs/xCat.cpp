#include "xCat.hpp"
#include "xAnimal.hpp"

xCat::xCat() {
    _type = "xCat";
    std::cout << "xCat defualt constructor called" << std::endl;
}

xCat::xCat(const xCat& other) : xAnimal(other) {
    std::cout << "xCat copy constructor called" << std::endl;
}

xCat& xCat::operator=(const xCat& other) {
    std::cout << "xCat assignment operator called" << std::endl;
    if (this != &other) {
        xAnimal::operator=(other);
    }
    return *this;
}

xCat::~xCat() {
    std::cout << "xCat destructor called" << std::endl;
}

void xCat::makeSound() const {
    std::cout << "xOIIA OIIA" << std::endl;
}