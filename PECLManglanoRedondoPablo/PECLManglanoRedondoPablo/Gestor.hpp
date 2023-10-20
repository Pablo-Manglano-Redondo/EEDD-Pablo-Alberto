#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Cola.hpp"

class Gestor
{
public:
    Gestor();
    ~Gestor();
private:
    Cola estacionA;
    Cola estacionB;
    Cola estacionC;
    Cola estacionD;
};

#endif // GESTOR_HPP