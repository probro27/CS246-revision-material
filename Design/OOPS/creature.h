#ifndef _CREATURE_H_
#define _CREATURE_H_

#include <string>

class Creature {
protected:
    const std::string _name;
public:
    Creature(std::string name): _name{name} {}
    virtual void printSalary() const = 0;
    virtual ~Creature() {}
};

#endif
