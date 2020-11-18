#include <iostream>
#include <string>
#include "Persona.h"
#include "Producto.h"
#include "Citas.h"
#include "Empleado.h"
#include "Cliente.h"

using namespace std;

class Laboratorio{
    Empleado * arrEmpleado;
    Cliente * arrCliente;
    Producto * arrProducto;
    Cita * arrCitas;

    int Tam, posEmpleado, posCliente, posProducto, posCitas;

  public:
    Laboratorio(){
        Tam = 5;
        posEmpleado = 0; posCliente = 0; posProducto = 0; posCitas = 0;
        arrEmpleado = new Empleado[Tam];
        arrCliente = new Cliente [Tam];
        arrProducto = new Producto[Tam];
        arrCitas = new Cita[Tam];
    }

    void menuP(){
        int op;
        do{
            cout << "\n***** Laboratorio de Analisis Clinicos *****" << endl;
            cout << "\n\t1. Recursos Materiales\n\t2. Control de Personal\n\t3. Manejo de Clientes\n\t4. Salir del Sistema\n\n";
            cout << "Seleccione una opcion:" << endl; cin >> op;
            switch(op){
                case 1:
                    system("cls");
                    menu1();
                    break;
                case 2:
                    system("cls");
                    menu2();
                    break;
                case 3:
                    system("cls");
                    menu3();
                    break;
                case 4:
                    break;
                default:
                    cout << "Opcion Invalida!";
                    break;
            }
        }while(op != 4);
    }


    void menu1(){
        int op;
        do{
            cout << "\n***** Recursos Materiales *****" << endl;
            cout << "\n\t1. Dar de alta Productos\n\t2. Buscar un Producto\n\t3. Modificar Precio de un Producto\n";
            cout << "\t4. Reporte de Analgesicos\n\t5. Reporte de Antibioticos\n\t6. Reporte de Preventivos\n\t7. Salir al Menu Principal\n\n";
            cout << "Seleccione una opcion:"  << endl;cin >> op;
            switch(op){
                case 1:
                    system("cls");
                    agregarP();
                    break;
                case 2:
                    system("cls");
                    buscarProducto();
                    break;
                case 3:
                    system("cls");
                    cambiarPrecio();
                    break;
                case 4:
                    system("cls");
                    mostrarAnalgesicos();
                    break;
                case 5:
                    system("cls");
                    mostrarAntibioticos();
                    break;
                case 6:
                    system("cls");
                    mostrarPreventivos();
                    break;
                case 7:
                    system("cls");
                    break;
                default:
                    cout << "Opcion Invalida!" << endl;
                    break;
            }
        }while (op != 7);
    }

    void agregarAnalgesico(){
        string n,c;
        int e;
        float p;
        fflush(stdin);
        cout << "ingrese el nombre del producto: "; getline(cin,n); cout << endl;
        arrProducto[posProducto].setNombre(n);
        cout << "ingrese el codigo del Producto: "; getline(cin,c); cout << endl;
        arrProducto[posProducto].setCodigo(c);
        cout << "ingrese el precio del producto: "; cin >> p; cout << endl;
        arrProducto[posProducto].setPrecio(p);
        cout << "Ingrese la cantidad de Productos: ";cin >> e; cout << endl;
        arrProducto[posProducto].setExistencia(e);
        ((Analgesico *)arrProducto)[posProducto].setTipo();
        cout << "### Producto agregado Satisfactoriamente! ###" << endl;
    }
    void agregarAntibiotico(){
        string n,c;
        float p;
        int e;
        fflush(stdin);
        cout << "ingrese el nombre del producto: "; getline(cin,n); cout << endl;
        arrProducto[posProducto].setNombre(n);
        cout << "ingrese el codigo del Producto: "; getline(cin,c); cout << endl;
        arrProducto[posProducto].setCodigo(c);
        cout << "ingrese el precio del producto: "; cin >> p; cout << endl;
        arrProducto[posProducto].setPrecio(p);
        cout << "Ingrese la cantidad de Productos: ";cin >> e; cout << endl;
        arrProducto[posProducto].setExistencia(e);
        ((Antibiotico *)arrProducto)[posProducto].setTipo();
        cout << "### Producto agregado Satisfactoriamente! ###" << endl;
    }
    void agregarPreventivo(){
        string n,c;
        float p;
        int e;
        fflush(stdin);
        cout << "ingrese el nombre del producto: "; getline(cin,n); cout << endl;
        arrProducto[posProducto].setNombre(n);
        cout << "ingrese el codigo del Producto: "; getline(cin,c); cout << endl;
        arrProducto[posProducto].setCodigo(c);
        cout << "ingrese el precio del producto: "; cin >> p; cout << endl;
        arrProducto[posProducto].setPrecio(p);
        cout << "Ingrese la cantidad de Productos: ";cin >> e; cout << endl;
        arrProducto[posProducto].setExistencia(e);
        ((Preventivo*)arrProducto)[posProducto].setTipo();
        cout << "### Producto agregado Satisfactoriamente! ###" <<  endl;
    }
    void agregarP(){
        if(posProducto < 5){
            int op;
            cout << "\nIngrese que tipo de Producto desea agregar\n\t1. Analgesico\n\t2. Antibiotico\n\t3. Preventivos\n\t4. salir\n";
            cin >> op;
            switch(op){
                case 1:
                    agregarAnalgesico();
                    posProducto++;
                    break;
                case 2:
                    agregarAntibiotico();
                    posProducto++;
                    break;
                case 3:
                    agregarPreventivo();
                    posProducto++;
                    break;
                case 4:
                    break;
                default:
                    cout << "\nseleccione una opcion valida!" << endl;
            }
        }
        else{
            cout << "\n\nSe ha alcanzado el limite de Productos!\n\n";
        }
    }
    void mostrarAnalgesicos(){
        cout << "Mostrando Productos:\n";
        for(int i = 0; i < posProducto; i++){
            if(arrProducto[i].getTipo()=="Analgesico"){
            cout << "-------------------- Producto "<<i+1<<" --------------------------\n\n";
            cout << "Nombre: " << arrProducto[i].getNombre() << endl;
            cout << "Codigo: " << arrProducto[i].getCodigo() << endl;
            cout << "Tipo: " << arrProducto[i].getTipo() << endl;
            cout << "Precio: " << arrProducto[i].getPrecio() << endl;
            cout << "Existencia: " << arrProducto[i].getExistencia() <<endl;
            cout << "\n----------------------------------------------------------\n";
            }
        }
    }
    void mostrarAntibioticos(){
        for(int i = 0; i < posProducto; i++){
            if(arrProducto[i].getTipo() == "Antibiotico"){
            cout << "-------------------- Producto "<<i+1<<" --------------------------\n\n";
            cout << "Nombre: " << arrProducto[i].getNombre() << endl;
            cout << "Codigo: " << arrProducto[i].getCodigo() << endl;
            cout << "Tipo: " << arrProducto[i].getTipo() << endl;
            cout << "Precio: " << arrProducto[i].getPrecio() << endl;
            cout << "Existencia: " << arrProducto[i].getExistencia() <<endl;
            cout << "\n----------------------------------------------------------\n";
            }
        }
    }
    void mostrarPreventivos(){
        for(int i = 0; i < posProducto; i++){
            if(arrProducto[i].getTipo() == "Preventivo"){
            cout << "-------------------- Producto "<<i+1<<" --------------------------\n\n";
            cout << "Nombre: " << arrProducto[i].getNombre() << endl;
            cout << "Codigo: " << arrProducto[i].getCodigo() << endl;
            cout << "Tipo: " << arrProducto[i].getTipo() << endl;
            cout << "Precio: " << arrProducto[i].getPrecio() << endl;
            cout << "Existencia: " << arrProducto[i].getExistencia() <<endl;
            cout << "\n----------------------------------------------------------\n";
            }
        }
    }
    void buscarProducto(){
        string n;
        int pos;
        bool b = false;
        cout << "\nIngrese el Nombre del Producto: ";
        fflush(stdin);
        getline(cin,n);cout << endl;
        for(int i = 0; i<posProducto;i++){
            if(arrProducto[i].getNombre() == n){
                pos = i;
                b = true;
                break;
            }
        }
        if(b == true){
            cout << "\n----------------------------------------------------------\n";
            cout << "\nNombre: " << arrProducto[pos].getNombre() << endl;
            cout << "Codigo: " << arrProducto[pos].getCodigo() <<endl;
            cout << "Tipo: " << arrProducto[pos].getTipo() << endl;
            cout << "Precio: " << arrProducto[pos].getPrecio() << endl;
            cout << "Existencia: " << arrProducto[pos].getExistencia() <<endl;
            cout << "\n----------------------------------------------------------\n";
        }
        else if(b==false){
            cout << "\nEl Producto no esta Registrado" << endl;
        }
    }
    void cambiarPrecio(){
        string c;
        int pos;
        float n;
        bool b = false;
        cout << "ingrese el codigo del producto: " << endl;
        fflush(stdin);
        getline(cin,c);
        for(int i= 0; i<posProducto;i++){
            if(arrProducto[i].getCodigo() == c){
                pos = i;
                b = true;
                break;
            }
        }
        if(b == true){
            cout << "\ningrese el nuevo Precio para el Producto: " << endl;cin >> n;arrProducto[pos].setPrecio(n);
            cout << "\nPrecio cambiado Correctamente!" << endl; 
            cout << "\n----------------------------------------------------------\n";
        }
        else{
            cout << "\nProducto no Registrado" << endl;
            cout << "\n----------------------------------------------------------\n";
        }
    }


    void menu2(){
        int op;
        do{
            cout << "\n***** Control de Personal *****" << endl;
            cout << "\n\t1. Agregar un Empleado\n\t2. Reporte de Empleados\n\t3. buscar un Empleado\n";
            cout << "\t4. Modificar Datos de un Empleado\n\t5. Eliminar un Empleado\n\t6. Agregar un Producto\n\t7. Salir al Menu Principal\n\n";
            cout << "Seleccione una opcion: "  << endl;cin >> op;
            switch(op){
                case 1:
                    system("cls");
                    agregarE();
                    break;
                case 2:
                    system("cls");
                    ReporteE();
                    break;
                case 3:
                    system("cls");
                    buscarE();
                    break;
                case 4:
                    system("cls");
                    ModificarDatos();
                    break;
                case 5:
                    system("cls");
                    eliminarEmpleado();
                    break;
                case 6:
                    system("cls");
                    agregarPxE();
                    break;
                case 7:
                    break;
                default:
                    cout << "Opcion Invalida!" << endl;
                    break;
            }
        }while (op != 7);
    }

    void agregarEmpleado(){
        string n,rfc,codigo,tipo;
        int edad;
        cout << "Ingrese el Nombre del Empleado: ";fflush(stdin);
        getline(cin,n); cout << endl;
        arrEmpleado[posEmpleado].setNombre(n);
        cout << "ingrese la Edad Empleado: "; cin >> edad; cout << endl;
        arrEmpleado[posEmpleado].setEdad(edad);
        cout << "ingrese el RFC del empleado: "; fflush(stdin);
        getline(cin,rfc); cout << endl;
        arrEmpleado[posEmpleado].setRfc(rfc);
        cout << "Ingrese el Codigo de empleado: ";fflush(stdin);
        getline(cin,codigo); cout << endl;
        arrEmpleado[posEmpleado].setCodigoE(codigo);
        cout << "\n##### Empleado agregado Correctamente #####\n\n";

    }
    void agregarE(){
        if(posEmpleado < 5){
            int op;
            cout << "Seleccione el tipo de Empleado:\n\t1. Administrativo\n\t2. Laboratorista\n\n"; cin >> op;
            switch(op){
                case 1:
                    agregarEmpleado();
                    ((Administrativo *)arrEmpleado)[posEmpleado].setTipo();
                    posEmpleado++;
                    break;
                case 2:
                    agregarEmpleado();
                    ((Laboratorista *)arrEmpleado)[posEmpleado].setTipo();
                    posEmpleado++;
                    break;
                default:
                    cout << "\nseleccione una opcion valida!" << endl;
                    break;
            }
        }
        else{
            cout << "\n\nSe ha alcanzado el limite de Empleados!\n\n";
        }
    }
    void ReporteE(){
        obtenerSalario();
        for (int i = 0; i < posEmpleado;i++){
            cout << "\n----------------------------------------------------------\n";
            cout << "Nombre: " << arrEmpleado[i].getNombre() << endl;
            cout << "Edad: " << arrEmpleado[i].getEdad() << endl;
            cout << "RFC: " << arrEmpleado[i].getRfc() << endl;
            cout << "Codigo de Empleado: " << arrEmpleado[i].getCodigoE() << endl;
            cout << "Ocupacion: " << arrEmpleado[i].getTipo() << endl;
            cout << "Salario: " << arrEmpleado[i].getSalario() << endl;
            cout << "----------------------------------------------------------\n";
        }
    }
    void obtenerSalario(){
        for(int i = 0; i < posEmpleado;i++){
            if(arrEmpleado[i].getTipo() == "Laboratorista"){
                arrEmpleado[i].setSalario(150 * posCitas);
            }
            else if(arrEmpleado[i].getTipo() == "Administrativo"){
                arrEmpleado[i].setSalario(100 * posCitas);
            }
        }
    }
    void buscarE(){
        string name;
        int pos;
        bool b = false; 
        cout << "Ingrese el Codigo del Empleado: ";fflush(stdin);
        getline(cin,name);cout << endl;
        for(int i = 0; i < posEmpleado;i++){
            if(arrEmpleado[i].getCodigoE() == name){
                pos = i;
                b = true;
                break;
            }
        }
        if(b == true){
            cout << "\n----------------------------------------------------------\n";
            cout << "Nombre: " << arrEmpleado[pos].getNombre() << endl;
            cout << "Edad: " << arrEmpleado[pos].getEdad() << endl;
            cout << "RFC: " << arrEmpleado[pos].getRfc() << endl;
            cout << "Codigo de Empleado: " << arrEmpleado[pos].getCodigoE() << endl;
            cout << "Ocupacion: " << arrEmpleado[pos].getTipo() << endl;
            cout << "Salario: " << arrEmpleado[pos].getSalario() <<endl;
            cout << "\n----------------------------------------------------------\n";
        }
        else{
            cout << "\n----------------------------------------------------------\n";
            cout << "\n----- El Empleado no esta registrado -----\n\n";
            cout << "\n----------------------------------------------------------\n";
        }
    }
    void ModificarDatos(){
        string name, code, rfc;
        int edad, pos;
        bool b = false;
        cout << "Ingrese el Codigo del Empleado: ";fflush(stdin);
        getline(cin,code);cout << endl;
        for(int i = 0; i < posEmpleado;i++){
            if(arrEmpleado[i].getCodigoE() == code){
                pos = i;
                b = true;
                break;
            }
        }
        if (b == true){
            int op,op1;
            cout << "\n¿Que elemento desea cambiar?" << endl;
            cout << "\t1. Nombre\n\t2. Edad\n\t3. RFC\n\t4. Codigo\n\t5. Tipo\nSeleccione una opcion: " << endl;cin >> op;
            switch(op){
                case 1:
                    cout << "Ingrese nuevo Nombre del Empleado: ";fflush(stdin);
                    getline(cin,name); cout << endl;
                    arrEmpleado[pos].setNombre(name);
                    break;
                case 2:
                    cout << "ingrese nueva Edad Empleado: "; cin >> edad; cout << endl;
                    arrEmpleado[pos].setEdad(edad);
                    break;
                case 3:
                    cout << "ingrese nuevo RFC del empleado: "; fflush(stdin);
                    getline(cin,rfc); cout << endl;
                    arrEmpleado[pos].setRfc(rfc);
                    break;
                case 4:
                    cout << "Ingrese nuevo Codigo de empleado: ";fflush(stdin);
                    getline(cin,code); cout << endl;
                    arrEmpleado[pos].setCodigoE(code);
                    break;
                case 5:
                    cout << "Seleccione el tipo de Empleado:\n\t1. Administrativo\n\t2. Laboratorista\n\n>"; cin >> op1;
                    switch(op1){
                        case 1:
                            ((Administrativo *)arrEmpleado)[pos].setTipo();
                            break;
                        case 2:
                            ((Laboratorista *)arrEmpleado)[pos].setTipo();
                            break;
                        default:
                            cout << "\nseleccione una opcion valida!" << endl;
                            break;
                    }
                    break;
                default:
                    cout  << "\nSeleccione una opcion valida" << endl;
                    break;
            }
             cout << "\n##### Datos del empleado Modificados con exito #####\n\n";
        }
        else{
             cout << "\n----- El Empleado no esta registrado -----\n\n";
        }
    }
    void eliminarEmpleado(){
        string code;
        int pos;
        bool b = false;
        cout << "Ingrese el Codigo del Empleado que desea Eliminar: ";fflush(stdin);
        getline(cin,code);cout << endl;
        for(int i = 0; i < posEmpleado;i++){
            if(arrEmpleado[i].getCodigoE() == code){
                pos = i;
                b = true;
                break;
            }
        }
        if (b == true){
            posEmpleado--;
            for(int i = pos; i < posEmpleado; i++){
                    arrEmpleado[i] = arrEmpleado[i + 1];
            }
            cout << "\n##### Empleado Eliminado Satisfactoriamente #####";
        }
        else{
            cout << "\n----- El Empleado no esta registrado -----\n\n";
        }
    }
    void agregarPxE(){
        string code;
        int pos;
        bool b = false;
        cout << "Ingrese el Codigo del Empleado: ";fflush(stdin);
        getline(cin,code);cout << endl;
        for(int i = 0; i < posEmpleado;i++){
            if(arrEmpleado[i].getCodigoE() == code){
                pos = i;
                b = true;
                break;
            }
        }
        if(b == true){
            if(arrEmpleado[pos].getTipo() == "Laboratorista"){
                agregarP();
            }
            else{
                cout << "\n##### El Empleado debe de ser un Laboratorista para agregar un producto #####\n\n";
            }
        }
        else{
            cout << "\n----- El Empleado no esta registrado -----\n\n";
        }
    }


    void menu3(){
        int op;
        do{
            cout << "\n***** Manejo de Clientes *****" << endl;
            cout << "\n\t1. Agregar un Cliente\n\t2. Buscar un Cliente\n\t3. Modificar Datos de un Cliente\n";
            cout << "\t4. Eliminar un Cliente\n\t5. Establecer una Cita\n\t6. Lista de Citas \n\t7. Reporte de Clientes que solicitaron Examen de Sangre\n";
            cout << "\t8. Reporte de clientes que solicitaron Examen de Nivel de Azucar\n\t9. Reporte de Clientes que solicitaron Examen de Orina\n\t10. Regresar al Menu Principal\n\n";
            cout << "Seleccione una opcion: "  << endl;cin >> op;
            switch(op){
                case 1:
                    system("cls");
                    agregarC();
                    break;
                case 2:
                    system("cls");
                    buscarC();
                    break;
                case 3:
                    system("cls");
                    modificarC();
                    break;
                case 4:
                    system("cls");
                    eliminarC();
                    break;
                case 5:
                    system("cls");
                    Establecer();
                    break;
                case 6:
                    system("cls");
                    Desplegar();
                    break;
                case 7:
                    system("cls");
                    citasSangre();
                    break;
                case 8:
                    system("cls");
                    citasAzucar();
                    break;
                case 9:
                    system("cls");
                    citasOrina();
                    break;
                case 10:
                    break;
                default:
                    cout << "Opcion Invalida!" << endl;
                    break;
            }
        }while (op != 10);
    }

    void agregarC(){
        if(posCliente < 5){
            string name, dom, code;
            int edad;
            cout << "Ingrese el Nombre del Cliente: "; fflush(stdin);
            getline(cin,name); cout << endl;
            cout << "Ingrese la Edad del Cliente: "; cin >> edad; cout << endl;
            cout << "Ingrese el Domicilio del cliente: "; fflush(stdin);
            getline(cin,dom); cout << endl;
            cout << "Establezca un Codigo para el Cliente: "; fflush(stdin);
            getline(cin,code);
            arrCliente[posCliente].setNombre(name);
            arrCliente[posCliente].setEdad(edad);
            arrCliente[posCliente].setDomicilio(dom);
            arrCliente[posCliente].setCodigo(code);
            posCliente++;
        }
        else{
            cout << "\n\n Se ha alcanzado el limite de Clientes\n\n";
        }
    }
    void buscarC(){
        string name;
        int pos;
        bool b = false;
        cout << "Ingrese el Nombre del Cliente: ";fflush(stdin);
        getline(cin,name);
        for(int i = 0; i < posCliente; i++){
            if(arrCliente[i].getNombre() == name){
                pos = i;
                b = true;
                break;
            }
        }
        if(b == true){
            cout << "\n----------------------------------------------------------\n";
            cout << "Nombre: " << arrCliente[pos].getNombre() << endl;
            cout << "Edad: " << arrCliente[pos].getEdad() << endl;
            cout << "Domicilio: " << arrCliente[pos].getdomicilio() << endl;
            cout << "Codigo: " << arrCliente[pos].getCodigo() << endl;
            cout << "\n----------------------------------------------------------\n";
        }
        else{
            cout << "\n----------------------------------------------------------\n";
            cout << "----- El cliente no esta registrado -----";
            cout << "\n----------------------------------------------------------\n";
        }
    }
    void modificarC(){
        string code, name, dom;
        int pos, edad;
        bool b = false;
        cout << "Ingrese el codigo del Cliente: ";fflush(stdin);
        getline(cin,code);
        for(int i = 0; i < posCliente; i++){
            if(arrCliente[i].getCodigo() == code){
                pos = i;
                b = true;
                break;
            }
        }
        if(b == true){
            int op;
            cout << "Mostrando Resultados: ";
            cout << "\n----------------------------------------------------------\n";
            cout << "Nombre: " << arrCliente[pos].getNombre() << endl;
            cout << "Edad: " << arrCliente[pos].getEdad() << endl;
            cout << "Domicilio: " << arrCliente[pos].getdomicilio() << endl;
            cout << "Codigo: " << arrCliente[pos].getCodigo() << endl;
            cout << "\n----------------------------------------------------------\n";
            cout << "\n¿Que elemento desea cambiar?" << endl;
            cout << "\t1. Nombre\n\t2. Edad\n\t3. Domicilio\n\t4. Codigo\nSeleccione una opcion: " << endl;cin >> op;
            switch(op){
                case 1:
                    cout << "Ingrese nuevo Nombre del Cliente: ";fflush(stdin);
                    getline(cin,name); cout << endl;
                    arrCliente[pos].setNombre(name);
                    cout << "\n##### Datos del Cliente Modificados con exito #####\n\n";
                    break;
                case 2:
                    cout << "ingrese nueva Edad Empleado: "; cin >> edad; cout << endl;
                    arrCliente[pos].setEdad(edad);
                    cout << "\n##### Datos del Cliente Modificados con exito #####\n\n";
                    break;
                case 3:
                    cout << "ingrese nuevo domicilio del empleado: "; fflush(stdin);
                    getline(cin,dom); cout << endl;
                    arrCliente[pos].setDomicilio(dom);
                    cout << "\n##### Datos del Cliente Modificados con exito #####\n\n";
                    break;
                case 4:
                    cout << "Ingrese nuevo Codigo de empleado: ";fflush(stdin);
                    getline(cin,code); cout << endl;
                    arrCliente[pos].setCodigo(code);
                    cout << "\n##### Datos del Cliente Modificados con exito #####\n\n";
                    break;
                default:
                    cout  << "\nSeleccione una opcion valida" << endl;
                    break;
            }
        }
        else{
            cout << "----- El cliente no esta registrado -----";
        }
    }
    void eliminarC(){
        string code;
        int pos;
        bool b = false;
        cout << "Ingrese el Codigo del Cliente que desea Eliminar: ";fflush(stdin);
        getline(cin,code);cout << endl;
        for(int i = 0; i < posCliente;i++){
            if(arrCliente[i].getCodigo() == code){
                pos = i;
                b = true;
                break;
            }
        }
        if (b == true){
            eliminarCita(pos);
            posCliente--;
            for(int i = pos; i < posCliente; i++){
                arrCliente[i] = arrCliente[i + 1];
            }
            cout << "\n##### Cliente Eliminado Satisfactoriamente #####";
        }
        else{
            cout << "\n----- El Cliente no esta registrado -----\n\n";
        }
    }
    void Establecer(){
        string code;
        int pos,op;
        bool b = false;
        if(posCitas < Tam){
            cout << "Ingrese el codigo del Cliente: ";fflush(stdin);
            getline(cin,code);
            for(int i = 0; i < posCliente; i++){
                if(arrCliente[i].getCodigo() == code){
                    pos = i;
                    b = true;
                    break;
                }
            }
            if( b == true){
                arrCitas[posCitas].setCodigoC(arrCliente[pos].getCodigo());
                arrCitas[posCitas].validar();
                cout << "Seleccione el tipo de Examen:\n\t1. Examen de Sangre\n\t2. Examen de nivel de Azucar\n\t3. Examen de Orina\n\n";
                cout << "ingrese una opcion: "; cin >> op;cout << endl;
                switch(op){
                    case 1:
                        ((Sangre *)arrCitas)[posCitas].setTipo();
                        break;
                    case 2:
                        ((NivelAzucar *)arrCitas)[posCitas].setTipo();
                        break;
                    case 3:
                        ((Orina *) arrCitas)[posCitas].setTipo();
                        break;
                    default:
                        cout << "seleccione una opcion valida" << endl;
                        break;
                }
                posCitas++;
                cout << "\n##### Se a guardado la Cita #####\n"; 
            }
            else{
                cout << "\n----- El Cliente no esta registrado -----\n\n";
            }
        }
        else{
            cout << "\n\nSe ha alcanzado el limite de citas\n\n";
        }
    }
    void Desplegar(){
        for(int i = 0; i < posCitas;i++){
            cout << "----------------------------------------------------------\n";
            cout << "Codigo de cliente: " << arrCitas[i].getCodigoC() << endl;
            cout << "Tipo de Cita: " << arrCitas[i].getTipo() << endl;
            cout << "Mes de la Cita: " << arrCitas[i].getMes() << endl;
            cout << "Dia de la Cita: " << arrCitas[i].getDia() << endl;
            cout << "\n----------------------------------------------------------\n";
        }
    }
    void citasSangre(){
        cout << "Mostrando citas para Examenes de Sangre!\n";
        for(int i = 0; i < posCitas;i++){
            if(arrCitas[i].getTipo() == "Sangre"){
                cout << "----------------------------------------------------------\n";
                cout << "Codigo de cliente: " << arrCitas[i].getCodigoC() << endl;
                cout << "Mes de la Cita: " << arrCitas[i].getMes() << endl;
                cout << "Dia de la Cita: " << arrCitas[i].getDia() << endl;
                cout << "Hora de la Cita: " << arrCitas[i].getHora() << endl;
                cout << "\n----------------------------------------------------------\n";
            }
        }
    }
    void citasAzucar(){
        cout << "Mostrando citas para Examenes de Azucar!\n";
        for(int i = 0; i < posCitas;i++){
            if(arrCitas[i].getTipo() == "Azucar"){
                cout << "----------------------------------------------------------\n";
                cout << "Codigo de cliente: " << arrCitas[i].getCodigoC() << endl;
                cout << "Mes de la Cita: " << arrCitas[i].getMes() << endl;
                cout << "Dia de la Cita: " << arrCitas[i].getDia() << endl;
                cout << "Hora de la Cita: " << arrCitas[i].getHora() << endl;
                cout << "\n----------------------------------------------------------\n";
            }
        }
    }
    void citasOrina(){
        cout << "Mostrando citas para Examenes de Orina!\n";
        for(int i = 0; i < posCitas;i++){
            if(arrCitas[i].getTipo() == "Orina"){
                cout << "----------------------------------------------------------\n";
                cout << "Codigo de cliente: " << arrCitas[i].getCodigoC() << endl;
                cout << "Mes de la Cita: " << arrCitas[i].getMes() << endl;
                cout << "Dia de la Cita: " << arrCitas[i].getDia() << endl;
                cout << "Hora de la Cita: " << arrCitas[i].getHora() << endl;
                cout << "\n----------------------------------------------------------\n";
            }
        }
    }
    void eliminarCita(int pos){
        int c=0;
        for(int j = 0;j<posCitas;j++){
            if(arrCitas[j].getCodigoC() == arrCliente[pos].getCodigo()){
                for (int i = pos;i<posCitas;i++){
                    arrCitas[i] = arrCitas[i+1];
                }
                posCitas--;
                j--;
            }
        }
        cout << c;
    }
};