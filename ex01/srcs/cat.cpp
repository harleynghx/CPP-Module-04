#include "cat.hpp"

Cat::Cat() {
    _type = "Cat";
    brain = new Brain();
    std::cout << "Cat defualt constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        brain = new Brain(*other.brain);
        delete brain;
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "OIIA OIIA" << std::endl;
}