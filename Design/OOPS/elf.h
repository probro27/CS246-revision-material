#ifndef _ELF_H_
#define _ELF_H_

#include "creature.h"

class Elf : public Creature {
    const int _songsSung;
    double calculateSalary() const;
public:
    Elf(std::string, int songsSung);
    void printSalary() const override;
};

#endif
