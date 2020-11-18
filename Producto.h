#include <iostream>

using  namespace std;

class Producto{
    protected:
        string codigo,nombre,tipo;
        int existencia;
        float precio;
    public:
        void setCodigo(string codigo){
            this -> codigo = codigo;
        }
        string getCodigo(){
            return codigo;
        }
        void setNombre(string nombre){
            this -> nombre = nombre;
        }
        string getNombre(){
            return nombre;
        }
        void setTipo(string tipo){
            this ->tipo = tipo;
        }
        string getTipo(){
            return tipo;
        }
        void setExistencia(int existencia){
            this ->existencia = existencia;
        }
        int getExistencia(){
            return existencia;
        }
        void setPrecio(float precio){
            this -> precio = precio;
        }
        float getPrecio(){
            return precio;
        }
};

struct Analgesico:public Producto{
    void setTipo(){
        this ->tipo = "Analgesico";
    }
};

struct Antibiotico:public Producto{
    void setTipo(){
        this -> tipo = "Antibiotico";
    }
};

struct Preventivo:public Producto{
    void setTipo(){
        this -> tipo = "Preventivo";
    }
};
