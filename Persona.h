#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

using namespace std;

class Persona{
    protected:
        string nombre;
        int edad;
    public:
        void setNombre(string nombre){
            this -> nombre = nombre;
        }
        string getNombre(){
            return nombre;
        }
        void setEdad(int edad){
            this -> edad = edad;
        }
        int getEdad(){
            return edad;
        }
};

#endif