#include "xAnimal.hpp"

xAnimal::xAnimal() : _type("xAnimal") {
    std::cout << "xAnimal default constructor called" << std::endl;
}

xAnimal::xAnimal(const xAnimal& other) : _type(other._type) {
    std::cout << "xAnimal copy constructor called" << std::endl;
}

xAnimal& xAnimal::operator=(const xAnimal& other)  {
    std::cout << "xAnimal assignment operator called" << std::endl;
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

xAnimal::~xAnimal() {
     std::cout << "xAnimal destructor called" << std::endl;
}

void xAnimal::makeSound() const {
    std::cout << "brr br patapim" << std::endl;
}

std::string xAnimal::getType() const {
    return _type;
}

