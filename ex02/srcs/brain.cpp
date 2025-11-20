#include "brain.hpp"

//? default constructor to initialised all "ideas[100]"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    for (unsigned int i = 0; i < size; i++)
        ideas[i] = "Empty String";
}

//? Create deep copy of ideas
Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (unsigned int i = 0; i < size; i++)
        ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other) {
        for (unsigned int i = 0; i < size; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

std::string Brain::getIdea(unsigned int index) const {
    if (index < size)
        return ideas[index];
    return "index error";
}

void Brain::setIdea(unsigned int index, const std::string& idea){
    if(index < size) 
        ideas[index] = idea;
}

//todo check when index < 0 for both method


