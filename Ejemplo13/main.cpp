#include <Persona.hpp>

int main(int argc, char** argv)
{

    Persona* maria = new Persona(18);
    Persona nora(5);
    cout << nora.getEdad()<<endl;
    cout << maria->getEdad()<<endl;
    
    return 0;
}
