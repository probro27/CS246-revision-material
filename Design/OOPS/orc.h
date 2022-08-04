#ifndef _ORC_H_
#define _ORC_H_

#include "creature.h"

class Orc : public Creature {
    const int _battlesWon;
    const int _murdersCommitted;
    double calculateSalary() const;
public:
    Orc(std::string name, int battlesWon, int murdersCommitted);
    void printSalary() const override;
};

#endif
