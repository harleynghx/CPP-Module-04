#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
private:
    //? static = only 1 memory occupied, instead of new memory for every object created.
   static const unsigned int size = 100;
   std::string ideas[size];
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    //? getter and setter for ideas to access them safetly 
    void setIdea(unsigned int index, const std::string& idea);
    std::string getIdea(unsigned int index) const;
};

#endif