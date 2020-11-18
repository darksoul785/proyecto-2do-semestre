#include <iostream>
#include "Persona.h"

using namespace std;

class Empleado:public Persona{
    protected:
        string codigoE, rfc,tipo;
        float salario = 0;
    public:
        void setCodigoE(string codigo){
            this -> codigoE = codigo;
        }
        string getCodigoE(){
            return codigoE;
        }
        void setRfc(string rfc){
            this -> rfc = rfc;
        }
        string getRfc(){
            return rfc;
        }
        void setSalario(float salario){
            this -> salario = salario;
        }
        float getSalario(){
            return salario;
        }
        void setTipo(string tipo){
            this -> tipo = tipo;
        }
        string getTipo(){
            return tipo;
        }
};

struct Laboratorista:public Empleado{
    void setTipo(){
        this -> tipo = "Laboratorista";
    }
};

struct Administrativo:public Empleado{
    void setTipo(){
        this -> tipo = "Administrativo";
    }
};
