#include <iostream>

using namespace std;

class Cita{
    protected:
        string codigo, tipo;
        int mes,dia,hora;
    public:
        void setCodigoC(string codigo){
            this -> codigo = codigo;
        }
        string getCodigoC(){
            return codigo;
        }
        void setMes(int mes){
            this -> mes = mes;
        }
        int getMes(){
            return mes;
        }
        void setDia (int dia){
            this -> dia = dia;
        }
        int getDia(){
            return dia;
        }
        void setHora(int hora){
            this -> hora = hora;
        }
        int getHora(){
            return hora;
        }
        void setTipo(string tipo){
            this -> tipo = tipo;
        }
        string getTipo(){
            return tipo;
        }
        void leer_fecha(){
            cout << "ingrese la fecha: " << endl;
            cout << "\nMes: "; cin >> mes;
            cout << "\nDia: "; cin >> dia;
            cout << "\nhora: "; cin >> hora;
        }
        int agendar(){
            if (mes > 0){
                if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
                    if ((dia > 0 && dia <= 31) && (hora >= 0 && hora <= 24)){
                        return 1;
                    }
                    else{
                        return 0;
                    }
                }
                else if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
                    if ((dia > 0 && dia <= 30) && (hora >= 0 && hora <= 24)){
                        return 1;
                    }
                    else{
                        return 0;
                    }
                }
                else if (mes ==2){
                    if ((dia > 0 && dia <= 28) && (hora >= 0 && hora <= 24)){
                        return 1;
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        void validar(){
            do{
                leer_fecha();
                if(agendar() == 1){
                    setMes(mes);
                    setDia(dia);
                    setHora(hora);
                }
            else{
                cout << "la fecha introducida no es valida!! ingrese los datos nuevamente." << endl;
            }
            } while (agendar() == 0);
        }
};

struct Sangre:public Cita{
    void setTipo(){
        this -> tipo = "Sangre";
    }
};

struct NivelAzucar: public Cita{
    void setTipo(){
        this -> tipo = "Azucar";
    }
};

struct Orina:public Cita{
    void setTipo(){
        this -> tipo = "Orina";
    }
};