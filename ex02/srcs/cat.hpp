#ifndef CAT_HPP
#define CAT_HPP

#include "animal.hpp"
#include "brain.hpp"
#include <string>


class Cat : public Animal {   
private:
    Brain* brain;
public:
    Cat();
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);
    ~Cat();

    virtual void makeSound() const;

    Brain* getBrain() const;
    void setIdea(unsigned int index, const std::string& idea);
};

#endif