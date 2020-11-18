#include <iostream>
#include "Persona.h"

class Cliente:public Persona{
    protected:
        string domicilio,codigo;
    public:
        void setDomicilio(string domicilio){
            this -> domicilio = domicilio;
        }
        string getdomicilio(){
            return domicilio;
        }
        void setCodigo(string codigo){
            this -> codigo = codigo;
        }
        string getCodigo(){
            return codigo;
        }
};