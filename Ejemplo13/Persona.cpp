#include "Persona.hpp"

Persona::Persona(int edad) { this->edad = edad; }

int Persona::getEdad() { return this->edad; }
bool Persona::esMujer() { return this->genero; }
void Persona::setEdad(int edad) { this->edad = edad; }
void Persona::mostrar() {}

Persona::~Persona() {}
