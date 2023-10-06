#ifndef PERSONA_HPP
#define PERSONA_HPP
#include <iostream>
using namespace std;

class Persona
{
public:
    Persona(int edad);
    ~Persona();

    int getEdad();
    bool esMujer();
    void setEdad(int edad);
    void mostrar();

private:
    bool genero; // 1 = mujer, 0 = hombre
    int edad;
    char* dni[10];
};

#endif // PERSONA_HPP
