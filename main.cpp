#include <iostream>
#include<time.h>
#include<string.h>
#include <fstream>
using namespace std;

//////////////ESTRUCTURAS/////////////////////
int NumClientes = 0;
int NumEmpleados= 3;
int Gs=1,As=1,Ss=1;

struct empleados{
char puesto[2];
char nombrecom[50];
char nombre[40];
char direccion[40];
char telefono[20];
char RFC[12];
float codigo;
double salario;
};
empleados *pArregloEmpleados[16];

struct clientes{
bool espacioRegistrado = false;
char nombre[50];
char direccion[40];
char telefono[20];
char RFC[20];
char correo[30];
float codigo;
};
clientes *pArregloClientes[12];

struct habitaciones{
string tipo;
string codigo;
float precio;
bool estatus = false;
};
habitaciones *pArregloHabitaciones[12];

///////////////////DECLARACION DE FUNCIONES//////////////////
void RegistroEmpleados(empleados *pArregloEmpleados[16]);
void ConsultarEmpleados(empleados *pArregloEmpleados[16]);
void EliminarEmpleados(empleados *pArregloEmpleados[16]);
void RegistroClientes(clientes *pArregloClientes[12]);
void ConsultarClientes(clientes *pArregloClientes[12]);
void EliminarClientes(clientes *pArregloClientes[12]);
void Habitaciones(habitaciones *pArregloHabitaciones[12]);
void RentaDeHabitaciones(habitaciones *pArregloHabitaciones[12]);
void reportes();
ofstream habitacionOUT;
ofstream listaEmpleados;
ofstream habitacionTOTAL;
ofstream listaClientes;
ofstream habitacionesDisp;
/////////////////////////////////////////////////////////////
int main() {
    int opcion;
    int empleadosOP;
    int clientesOP;
    
    for(int i = 0;i<16;i++){
    pArregloEmpleados[i] = new empleados;
    }
    for(int i = 0;i<12;i++){
    pArregloClientes[i] = new clientes;
    }
    for(int i = 0;i<12;i++){
    pArregloHabitaciones[i] = new habitaciones;
    }
  //////////////////CLIENTES INICIALIZADOS///////////////
    strcpy(pArregloEmpleados[0]->puesto,"A");
    strcpy(pArregloEmpleados[0]->nombrecom,"Adolfo_Vidaña");
    strcpy(pArregloEmpleados[0]->direccion,"Loma_Bonita,3477");
    strcpy(pArregloEmpleados[0]->RFC,"347829601293");
    strcpy(pArregloEmpleados[0]->telefono,"3332409800");
    pArregloEmpleados[0]->codigo=201;
    pArregloEmpleados[0]->salario=15000;
    
    strcpy(pArregloEmpleados[1]->nombrecom,"Chuyin_Lopez");
    strcpy(pArregloEmpleados[1]->puesto,"G");
    strcpy(pArregloEmpleados[1]->direccion,"Loma_Tapada,1234");
    strcpy(pArregloEmpleados[1]->RFC,"146347601293");
    strcpy(pArregloEmpleados[1]->telefono,"331265878");
    pArregloEmpleados[1]->codigo=879;
    pArregloEmpleados[1]->salario=35000;

    strcpy(pArregloEmpleados[2]->nombrecom,"Rafa_Cañedo");
    strcpy(pArregloEmpleados[2]->puesto,"S");
    strcpy(pArregloEmpleados[2]->direccion,"El_Granado,306");
    strcpy(pArregloEmpleados[2]->RFC,"986547601293");
    strcpy(pArregloEmpleados[2]->telefono,"3336208694");
    pArregloEmpleados[2]->codigo=265;
    pArregloEmpleados[2]->salario=9000;
////////////////////////////////////////////////////////
    cout<<endl<<"Borra los reportes generados anteriormente PORFAVOR \n";
    cout<<"--------------------------------------------------\n";
    cout<<"   Bienvenidos al sistema del hotel ";
    while(true){
        cout<<endl;
        cout<<"--------------------------------------------------\n";
        cout<< "Ingresar a una de las siguientes opciones:\n\n";
        cout<<"1. Empleados "<<endl;
        cout<<"2. Clientes"<<endl;
        cout<<"3. Habitaciones"<<endl;
        cout<<"4. Renta de habitaciones"<<endl;
        cout<<"5. Reportes"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<endl<<"Ingresa la opcion a ejecutar: ";
        cin>>opcion;
    
        switch(opcion){
            case 1:
                cout<<"--------------------------------------------------\n"
                <<"                 MENU EMPLEADOS\n"
                <<"--------------------------------------------------\n"
                <<"¿Qué acción realizarás?\n\n"
                <<"1. Ingresar un nuevo registro \n" 
                <<"2. Consultar uno o varios registros \n"
                <<"3. Eliminar un registro.\n"
                <<"4. Atrás\n";
                
                cin>>empleadosOP;
                switch(empleadosOP){
                    case 1:
                        RegistroEmpleados(pArregloEmpleados);
                        NumEmpleados++;
                    break;
                    case 2:
                        ConsultarEmpleados(pArregloEmpleados);
                    break;
                    case 3:
                        EliminarEmpleados(pArregloEmpleados);
                    break;
                    case 4:
                    break;
                }
            break;
            case 2: 
                cout<<"--------------------------------------------------\n"
                <<"                 MENU CLIENTES\n"
                <<"--------------------------------------------------\n"
                <<"¿Qué acción realizarás?\n\n"
                <<"1. Ingresar un nuevo registro \n" 
                <<"2. Consultar uno o varios registros \n"
                <<"3. Eliminar un registro.\n"
                <<"4. Atrás\n";
                cin>>clientesOP;
                switch(clientesOP){
                    case 1:
                        RegistroClientes(pArregloClientes);
                        NumClientes++;    
                    break;
                    case 2:
                        ConsultarClientes(pArregloClientes);
                    break;
                    case 3:
                        EliminarClientes(pArregloClientes);
                    break;
                    case 4:
                    break;
                }
            break;
            case 3: 
                cout<<"---------------------------\n Has ingresado a la funcion Habitaciones \n-------------------";
                Habitaciones(pArregloHabitaciones);
            break;
            case 4: 
                RentaDeHabitaciones(pArregloHabitaciones);
            break;
            case 5: 
              reportes();
            break;  
            
            default:
            cout<<"Saliendo...";
            exit(1);
        }
    }
}



///////////////EMPLEADOS///////////////////////
void RegistroEmpleados(empleados *pArregloEmpleados[16]){
  string puesto;
    cout<<"--------------------------------------------------\n"
  <<"                 REGISTRO DE EMPLEADOS\n"
  <<"--------------------------------------------------\n";
if(NumEmpleados>=16){
    cout<<"EMPLEADOS COMPLETOS";
    return;
  }
else{
  cin.ignore();
  cout<<"Puesto('Gerente (G)', 'Administrador (A)', 'Servicio(S)': ";
  cin.getline(pArregloEmpleados[NumEmpleados]->puesto,20);

  
  puesto=pArregloEmpleados[NumEmpleados]->puesto;
    if(puesto=="G" || puesto=="g"){
    pArregloEmpleados[NumEmpleados]->salario=35000;
    Gs++;
  }
  else if(puesto=="A" || puesto=="a"){
    pArregloEmpleados[NumEmpleados]->salario=15000;
    As++;
  }
  else if(puesto=="S" || puesto=="s"){
    pArregloEmpleados[NumEmpleados]->salario=9000;
    Ss++;
  }
  else{
    cout<<"\n PUESTO NO PERMITIDO";
    exit(0);
  }
  if(Gs>2 && puesto=="G" || Gs>2 && puesto=="g"){
    cout<<"Limite de gerentes alcanzado, ingresa otro puesto";
    cin.getline(pArregloEmpleados[NumEmpleados]->puesto,20);
    puesto=pArregloEmpleados[NumEmpleados]->puesto;
    while(puesto=="g"|| puesto=="G"){
       cout<<"Limite de gerentes alcanzado, ingresa otro puesto";
    cin.getline(pArregloEmpleados[NumEmpleados]->puesto,20);
    puesto=pArregloEmpleados[NumEmpleados]->puesto;
      
    }
    if(puesto=="a" || puesto=="A"){
      pArregloEmpleados[NumEmpleados]->salario=15000;
    }
    else if(puesto=="s" || puesto=="S"){
      pArregloEmpleados[NumEmpleados]->salario=9000;
    }
  }
  else if(As>4 && puesto=="A" || As>4 && puesto=="a"){
    cout<<"Limite de Administradores alcanzado, ingresa otro puesto";
    cin.getline(pArregloEmpleados[NumEmpleados]->puesto,20);
    puesto=pArregloEmpleados[NumEmpleados]->puesto;
    while(puesto=="A"|| puesto=="a"){
       cout<<"Limite de Administradores alcanzado, ingresa otro puesto";
       cin.getline(pArregloEmpleados[NumEmpleados]->puesto,20);
       puesto=pArregloEmpleados[NumEmpleados]->puesto;
  }
    if(puesto=="g" || puesto=="G"){
      pArregloEmpleados[NumEmpleados]->salario=35000;
    }
    else if(puesto=="s" || puesto=="S"){
      pArregloEmpleados[NumEmpleados]->salario=9000;
    }
    }
  else if(Ss>10 && puesto=="S" || Ss>10 && puesto=="s"){
    cout<<"Limite de empleados de servicio alcanzado, ingresa otro puesto";
    cin.getline(pArregloEmpleados[NumEmpleados]->puesto,20); 
      while(puesto=="s"|| puesto=="S"){
       cout<<"Limite de empleados de Servicio alcanzado, ingresa otro puesto";
       cin.getline(pArregloEmpleados[NumEmpleados]->puesto,20);
       puesto=pArregloEmpleados[NumEmpleados]->puesto;
  }
    if(puesto=="a" || puesto=="A"){
      pArregloEmpleados[NumEmpleados]->salario=15000;
    }
    else if(puesto=="g" || puesto=="G"){
      pArregloEmpleados[NumEmpleados]->salario=35000;
    }
  }

  if(Gs>3 || As>5 || Ss>11){
    cout<<"Te avise y no hiciste caso, HAS SIDO VETADO DEL HOTEL";
    exit(0);
  }
  else{
  cout<<"Nombre: ";
  cin.getline(pArregloEmpleados[NumEmpleados]->nombrecom,40);
  cout<<"Dirección: ";
  cin.getline(pArregloEmpleados[NumEmpleados]->direccion,40);
  cout<<"RFC (12 dígitos): ";
  cin>>pArregloEmpleados[NumEmpleados]->RFC;
  cout<<"Teléfono: ";
  cin>>pArregloEmpleados[NumEmpleados]->telefono;
    
  srand(time(NULL));
  int num = rand();
  num=rand()%200;
  pArregloEmpleados[NumEmpleados]->codigo=num;
  cout<<"\n-------CODIGO DE EMPLEADO:"<<pArregloEmpleados[NumEmpleados]->codigo<<"\n"; 

  }
  }
 
      
}

void ConsultarEmpleados(empleados *pArregloEmpleados[16]){
  int busqueda;
  bool flag=false;
  string puesto;
  cout<<"\n *Ingresa el código del empleado \n *Ingresa '00' para mostrar todos los registros actuales \n";
  cin>>busqueda;
  if(busqueda==00){
    for(int i=0; i<NumEmpleados; i++){
    cout<<"--------------------------------------------------  \n"
    <<"                 EMPLEADO "<<i+1<<"\n"
    <<"--------------------------------------------------\n";
    cout<<"Nombre: "<<pArregloEmpleados[i]->nombrecom<<endl;
    puesto=pArregloEmpleados[i]->puesto;
    if(puesto=="g"|| puesto=="G"){
      puesto="Gerente";
    }
    else if(puesto=="a" || puesto=="A"){
      puesto="Administrador";
    }
    else if(puesto=="s"|| puesto=="S"){
      puesto="Servicio";
    }
    cout<<"Puesto: "<<puesto<<endl;
    cout<<"Salario mensual: "<<pArregloEmpleados[i]->salario<<endl;
    cout<<"Dirección: "<<pArregloEmpleados[i]->direccion<<endl;
    cout<<"RFC: "<<pArregloEmpleados[i]->RFC<<endl;
    cout<<"Teléfono: "<<pArregloEmpleados[i]->telefono<<endl;
    cout<<"Código: "<<pArregloEmpleados[i]->codigo<<endl;
    
    }
  }
  else{
   for(int i=0; i<NumEmpleados; i++){
    if(busqueda==pArregloEmpleados[i]->codigo){
      flag=true;
      cout<<"Nombre: "<<pArregloEmpleados[i]->nombrecom<<endl;
      puesto=pArregloEmpleados[i]->puesto;
    if(puesto=="g"|| puesto=="G"){
      puesto="Gerente";
    }
    else if(puesto=="a" || puesto=="A"){
      puesto="Administrador";
    }
    else if(puesto=="s"|| puesto=="S"){
      puesto="Servicio";
    }
      cout<<"Puesto: "<<pArregloEmpleados[i]->puesto<<endl;
      cout<<"Salario mensual: "<<pArregloEmpleados[i]->salario<<endl;
      cout<<"Dirección: "     
      <<pArregloEmpleados[i]->direccion<<endl;
      cout<<"RFC: "<<pArregloEmpleados[i]->RFC<<endl;
      cout<<"Teléfono: "<<pArregloEmpleados[i]->telefono<<endl;
      cout<<"Código: "<<pArregloEmpleados[i]->codigo<<endl;
      }   
    }
  if(flag==false){
    cout<<"\n REGISTRO INEXISTENTE";
  }
  }
}

void EliminarEmpleados(empleados *pArregloEmpleados[16]){
    int eliminable;
    cout<<"Selecciona el código a eliminar";
    for(int i = 0; i<12;i++){
        if(pArregloEmpleados[i]->codigo!=0){
            cout<<pArregloEmpleados[i]->codigo<<"\n";
        }
        else{
            i++;
        }
    }
    cin>>eliminable;
    for(int i = 0;i<16;i++){
        if(eliminable == pArregloEmpleados[i]->codigo){
            eliminable = i;
        }
        strcpy(pArregloEmpleados[eliminable]->puesto,"");
        strcpy(pArregloEmpleados[eliminable]->nombrecom,"");
        strcpy(pArregloEmpleados[eliminable]->direccion,"");
        strcpy(pArregloEmpleados[eliminable]->telefono,"");
        strcpy(pArregloEmpleados[eliminable]->RFC,"");
        pArregloEmpleados[eliminable]->codigo = 0;
        pArregloEmpleados[eliminable]->salario = 0;
}

}
///////////////CLIENTES/////////////////////////////
void RegistroClientes(clientes *pArregloClientes[12]){
    cin.ignore();
    cout<<"Nombre: ";
    cin.getline(pArregloClientes[NumClientes]->nombre,50);
    cout<<"Dirección: ";
    cin.getline(pArregloClientes[NumClientes]->direccion,40);
    cout<<"Correo: ";
    cin.getline(pArregloClientes[NumClientes]->correo,30);
    cout<<"Teléfono: ";
    cin.getline(pArregloClientes[NumClientes]->telefono,20);
    cout<<"RFC: ";
    cin.getline(pArregloClientes[NumClientes]->RFC,20);
    cout<<"Código: ";
    cin>>pArregloClientes[NumClientes]->codigo;

  listaClientes.open("Lista De Clientes.txt", ios::app);
  listaClientes<<"NOMBRE:"<<pArregloClientes[NumClientes]->nombre<<"\n"<<"DIRECCION:"<<pArregloClientes[NumClientes]->direccion<<"\n"<<"RFC:"<<pArregloClientes[NumClientes]->RFC<<"\n"<<"TELEFONO:"<<pArregloClientes[NumClientes]->telefono<<"\n"<<"CODIGO: "<<pArregloClientes[NumClientes]->codigo<<"\n"<<"CORREO:"<<pArregloClientes[NumClientes]->correo<<"\n"<<"\n---------------------------------------------------------------\n";
  listaClientes.close(); 
     
}

void ConsultarClientes(clientes *pArregloClientes[12]){
  int busqueda;
  bool flag=false;
  string puesto;
  cout<<"\n *Ingresa el código del cliente \n *Ingresa '00' para mostrar todos los registros actuales \n";
  cin>>busqueda;
  if(busqueda==00){
    for(int i=0; i<NumClientes; i++){
    cout<<"--------------------------------------------------  \n"
    <<"                 EMPLEADO "<<i+1<<"\n"
    <<"--------------------------------------------------\n";
    cout<<"Nombre: "<<pArregloClientes[i]->nombre<<endl;
    cout<<"Correo: "<<pArregloClientes[i]->correo<<endl;
    cout<<"Dirección: "<<pArregloClientes[i]->direccion<<endl;
    cout<<"RFC: "<<pArregloClientes[i]->RFC<<endl;
    cout<<"Teléfono: "<<pArregloClientes[i]->telefono<<endl;
    cout<<"Código: "<<pArregloClientes[i]->codigo<<endl;
    
    }
  }
  else{
   for(int i=0; i<NumClientes; i++){
    if(busqueda==pArregloEmpleados[i]->codigo){
      flag=true;
      cout<<"Nombre: "<<pArregloClientes[i]->nombre<<endl;
      cout<<"Correo: "<<pArregloClientes[i]->correo<<endl;
      cout<<"Dirección: "     
      <<pArregloClientes[i]->direccion<<endl;
      cout<<"RFC: "<<pArregloClientes[i]->RFC<<endl;
      cout<<"Teléfono: "<<pArregloClientes[i]->telefono<<endl;
      cout<<"Código: "<<pArregloClientes[i]->codigo<<endl;
      }   
    }
  if(flag==false){
    cout<<"\n REGISTRO INEXISTENTE";
  }
  }
}

void EliminarClientes(clientes *pArregloClientes[12]){
    int eliminable;
    cout<<"Selecciona el código a eliminar";
    for(int i = 0; i<12;i++){
        if(pArregloClientes[i]->codigo!=0){
            cout<<pArregloClientes[i]->codigo<<"\n";
        }
        else{
            i++;
        }
    }
    cin>>eliminable;
    for(int i = 0;i<12;i++){
        if(eliminable == pArregloClientes[i]->codigo){
            eliminable = i;
        }
        strcpy(pArregloClientes[eliminable]->nombre,"");
        strcpy(pArregloClientes[eliminable]->direccion,"");
        strcpy(pArregloClientes[eliminable]->correo,"");
        strcpy(pArregloClientes[eliminable]->telefono,"");
        strcpy(pArregloClientes[eliminable]->RFC,"");
        pArregloClientes[eliminable]->codigo = 0;
    }
}


////////////HABITACIONES//////////
void Habitaciones(habitaciones *pArregloHabitaciones[12]){
float codigoE;
string puesto,codigoH;
bool flag=false;
bool flag2=false;
  cout<<"\n Ingresa el código de empleado";
  cin>>codigoE;
  for(int i=0; i<NumEmpleados; i++){
    if(codigoE==pArregloEmpleados[i]->codigo){
      flag=true;
      puesto=pArregloEmpleados[i]->puesto;
      if(puesto=="g"|| puesto=="G"){
        flag2=true;
        cout<<"Ingreso valido \n";
        cout<<"Ingresa el codigo de habitación que será desalojada: ";
        cin>>codigoH;
        for(int i=0; i<12; i++){
          if(codigoH==pArregloHabitaciones[i]->codigo){
            pArregloHabitaciones[i]->estatus=false;
            cout<<"La habitación "<<i+1<<" ha sido desalojada";
            pArregloClientes[i]->espacioRegistrado=false;
          }  
        }
   
      }
    }
  }
  if(flag==false){
    cout<<"Codigo de empleado invalido";
  }
  if(flag2==false){
    cout<<"Solo los gerentes tienen permitido el acceso";
  }
}

void RentaDeHabitaciones(habitaciones *pArregloHabitaciones[12]){
    float comision,codigoE,costo,codigoC;
    bool flag=false, flag2=false, flag3=false,flag4=false,flag5=false;
    string puesto,estatus,codigoH,codigoRegistradoH;
    double total,dinero;
    int contador,dias,codigoRegistradoE,codigoRegistradoC;
    cout<<"--------------------------------------------------\n"
    <<"                 RENTA DE HABITACIONES\n"
    <<"--------------------------------------------------\n";
    for(int i=0; i<12; i++){
        if(pArregloClientes[i]->espacioRegistrado==false){
            flag4=true;
        }
    }
    if(flag4==false){
        cout<<"EL HOTEL SE ENCUENTRA LLENO";
        return;
    }
    cout<<"Ingresa el código de empleado";
    cin>>codigoE;
    for(int i=0; i<NumEmpleados; i++){
        if(codigoE==pArregloEmpleados[i]->codigo){
            flag=true;
          codigoRegistradoE=pArregloEmpleados[i]->codigo;
            contador=i;
            puesto=pArregloEmpleados[i]->puesto;
            if(puesto=="g"|| puesto=="G"){
                comision=0;
                flag2=true;
            }
            else if(puesto=="A"|| puesto=="a"){
                comision=0.05;
                flag2=true;
            }    
            else if(puesto=="S"|| puesto=="s"){
                cout<<"ACCESO DENEGADO";
                return;
            }
        }
    }
    if(flag==false){
        cout<<"Codigo de empleado invalido";
    return;
    }
    if(flag2==false){
        cout<<"Solo los gerentes tienen permitido el acceso";
        return;
    }
    cout<<"Ingresa el codigo del cliente que realizará la renta:";
    cin>>codigoC;
    for(int i=0; i<12; i++){
        if(codigoC==pArregloClientes[i]->codigo && pArregloClientes[i]->espacioRegistrado == false){
            cout<<"Codigo de cliente aprobado\n"; 
            flag5=true;
            codigoRegistradoC=pArregloClientes[i]->codigo;
            for(int i=0; i<12;i++){
                if(i<5){
                pArregloHabitaciones[i]->tipo=" Doble    ";
                pArregloHabitaciones[i]->precio=1200;
                pArregloHabitaciones[i]->codigo="D"+to_string(i);
                }
                if(i>=5 &&i<9){
                    pArregloHabitaciones[i]->tipo=" Cuadruple";
                    pArregloHabitaciones[i]->precio=2600;
                    pArregloHabitaciones[i]->codigo="C"+to_string(i);
                }
                if(i>= 9&& i<12){
                    pArregloHabitaciones[i]->tipo=" de_Lujo ";
                    pArregloHabitaciones[i]->precio=4500;
                    pArregloHabitaciones[i]->codigo="dl"+to_string(i);
                }  
            }
          
            cout<<"\n Tipo de habitación \t Código \t Precio \t Estatus \n";
            for(int i=0; i<12; i++){
                if(pArregloHabitaciones[i]->estatus==true){
                    estatus="Ocupada";
                }
                else if(pArregloHabitaciones[i]->estatus==false){
                    estatus="Disponible";
                }
                cout<<pArregloHabitaciones[i]->tipo<<"\t\t\t\t"<<pArregloHabitaciones[i]->codigo<<"\t\t\t"<<pArregloHabitaciones[i]->precio<<"\t\t\t"<<estatus;
                cout<<"\n";
              
            }
            cout<<"\nCódigo de la habitación a rentar:";
            cin>>codigoH;
            for(int i=0; i<12; i++){
                if(codigoH==pArregloHabitaciones[i]->codigo && pArregloHabitaciones[i]->estatus==false){
                  codigoRegistradoH=pArregloHabitaciones[i]->codigo;
                    flag3=true;
                    cout<<"Renta realizada\n";
                    pArregloClientes[i]->espacioRegistrado=true;
                    cout<<"Cuantos días estarás hospedado";
                    cin>>dias;
                    pArregloHabitaciones[i]->estatus=true;
                    costo=(pArregloHabitaciones[i]->precio)*dias;
                    total=(costo*comision);
                }
            }
            if(flag3==false){
                cout<<"Codigo Incorrecto/ Habitación ocupada";
            }
            pArregloEmpleados[contador]->salario+=total;
          dinero=pArregloEmpleados[contador]->salario+=total;
        }
      
        
    }
  if(flag5==false){
    cout<<"Codigo Incorrecto/El usuario ya cuenta con una habitación";
  }
    
  habitacionOUT.open("HabitacionesOcupadas.txt",ios::app);
  habitacionOUT<<"CODIGO_DE_EMPLEADO:"<<codigoRegistradoE<<"\n"<<"CODIGO_DE_CLIENTE:"<<codigoRegistradoC<<"\n"<<"CODIGO_DE_HABITACION:"<<codigoRegistradoH<<"\n"<<"COSTO:"<<dinero<<"\n"<<"DIAS:"<<dias<<"\n--------------------------------------\n";
  habitacionOUT.close();
 
} 
/////////////////////////FUNCION REPORTES///////////////
  void reportes(){
    int opcion;
    string estatus,puesto;
    cout<<"-----------------------------------\n REPORTES \n --------------------------";
    cout<<"\n1. Lista de clientes \n 2. Lista de habitaciones totales\n 3. Reporte de habitaciones disponibles\n 4. Reporte de habitaciones no disponibles \n 5. Lista de empleados \n 6. Lista de empleados organizados por puestos ";
    cout<<"\n\nNOTA: para acceder a los reportes de habitaciones, deberás generar una renta de habitación\n";
    cout<<"\n Ingresa el reporte que desees ver";
    cin>>opcion;
   if(opcion==1){
    ifstream clientesIN;
    clientesIN.open("Lista De Clientes.txt");
    string infoC;
      
    while(clientesIN.good()){
    clientesIN>>infoC;
    cout<<infoC<<"\n"; 
    }
    cout<<"\n";
    clientesIN.close();
  }
    else if(opcion==2){
         for(int i=0; i<12;i++){
           estatus=pArregloHabitaciones[i]->estatus;
           if(pArregloHabitaciones[i]->estatus==true){
                    estatus="Ocupada";
                }
                else if(pArregloHabitaciones[i]->estatus==false){
                    estatus="Disponible";
                }
   habitacionTOTAL.open("HabitacionesTotales.txt",ios::app);
  habitacionTOTAL<<"TIPO_DE_HABITACION:"<<pArregloHabitaciones[i]->tipo<<"\n"<<"CODIGO_DE_HABITACION:"<<pArregloHabitaciones[i]->codigo<<"\n"<<"PRECIO_DE_HABITACION:"<<pArregloHabitaciones[i]->precio<<"\n"<<"ESTATUS:"<<estatus<<"\n------------------------------------------------\n";
  habitacionTOTAL.close();
      }
      ifstream habitacionesTotalesIN;
      habitacionesTotalesIN.open("HabitacionesTotales.txt");
      string infoHT;
      while(habitacionesTotalesIN.good()){
      habitacionesTotalesIN>>infoHT;
      cout<<infoHT<<"\n"; 
      }
      cout<<"\n";
      habitacionesTotalesIN.close();
    }
      
    else if(opcion==3){
    for(int i=0;i<12;i++){
   if(pArregloHabitaciones[i]->estatus==false){
  habitacionesDisp.open("Habitaciones Disponibles.txt",ios::app);
  habitacionesDisp<<"PRECIO:"<<pArregloHabitaciones[i]->precio<<"\n"<<"\n"<<"CODIGO_DE_HABITACION:"<<pArregloHabitaciones[i]->codigo<<"\n"<<"TIPO_DE_HABITACION:"<<pArregloHabitaciones[i]->tipo<<"\n----------------------------------------------------\n";
  habitacionesDisp.close();
   }
}
      ifstream habitacionesDispIN;
      habitacionesDispIN.open("Habitaciones Disponibles.txt");
      string infoHD;
      while(habitacionesDispIN.good()){
      habitacionesDispIN>>infoHD;
      cout<<infoHD<<"\n";
      }
      cout<<"\n";
      habitacionesDispIN.close();
    }
      
    else if(opcion==4){
    ifstream habitacionIN;
    habitacionIN.open("HabitacionesOcupadas.txt");
    string infoH;
    while(habitacionIN.good()){
    habitacionIN>>infoH;
    cout<<infoH<<"\n";
    }
    cout<<"\n ";
    habitacionIN.close();
    }
      
    else if(opcion==5){
      for(int i=0; i<NumEmpleados; i++){
  listaEmpleados.open("Lista De Empleados.txt", ios::app);
    puesto=pArregloEmpleados[i]->puesto;
    if(puesto=="g"|| puesto=="G"){
      puesto="Gerente";
    }
    else if(puesto=="a" || puesto=="A"){
      puesto="Administrador";
    }
    else if(puesto=="s"|| puesto=="S"){
      puesto="Servicio";
    }
  listaEmpleados<<"PUESTO:"<<puesto<<"\n"<<"NOMBRE:"<<pArregloEmpleados[i]->nombrecom<<"\n"<<"DIRECCION:"<<pArregloEmpleados[i]->direccion<<"\n"<<"RFC:"<<pArregloEmpleados[i]->RFC<<"\n"<<"TELEFONO:"<<pArregloEmpleados[i]->telefono<<"\n"<<"CODIGO: "<<pArregloEmpleados[i]->codigo<<"\n------------------------------------------------\n";
  listaEmpleados.close();
      }
  
      ifstream empleadosIN;
      empleadosIN.open("Lista De Empleados.txt");
      string infoE;
      while(empleadosIN.good()){
      empleadosIN>>infoE;
      cout<<infoE<<"\n";
      }
      cout<<"\n";
      empleadosIN.close();
    }
      
    else if(opcion==6){
        int a = 0;
        int b = 0;
        int c = 0;
        ofstream empleadosOrdenadosIN;
        empleadosOrdenadosIN.open("Tipos de empleados.txt");
        for(int i = 0; i < 16;i++){
          puesto=pArregloEmpleados[i]->puesto;
            if(puesto =="G"|| puesto=="g"){
                empleadosOrdenadosIN<<"Gerente "<<a+1<<endl;
                empleadosOrdenadosIN<<pArregloEmpleados[i]->nombrecom<<endl;
                empleadosOrdenadosIN<<pArregloEmpleados[i]->direccion<<endl;
                empleadosOrdenadosIN<<pArregloEmpleados[i]->telefono<<endl;
                empleadosOrdenadosIN<<pArregloEmpleados[i]->RFC<<endl;

                cout<<"Gerente "<<a+1<<endl;
                cout<<pArregloEmpleados[i]->nombrecom<<endl;
                cout<<pArregloEmpleados[i]->direccion<<endl;
                cout<<pArregloEmpleados[i]->telefono<<endl;
                cout<<pArregloEmpleados[i]->RFC<<endl;
                a++;
            }
        }
      for(int i = 0; i < 16;i++){
          puesto=pArregloEmpleados[i]->puesto;
            if(puesto =="A"|| puesto=="a"){
                empleadosOrdenadosIN<<"Administrador "<<b+1<<endl;
                empleadosOrdenadosIN<<pArregloEmpleados[i]->nombrecom<<endl;
                empleadosOrdenadosIN<<pArregloEmpleados[i]->direccion<<endl;
                empleadosOrdenadosIN<<pArregloEmpleados[i]->telefono<<endl;
                empleadosOrdenadosIN<<pArregloEmpleados[i]->RFC<<endl;

                cout<<"Administrador "<<b+1<<endl;
                cout<<pArregloEmpleados[i]->nombrecom<<endl;
                cout<<pArregloEmpleados[i]->direccion<<endl;
                cout<<pArregloEmpleados[i]->telefono<<endl;
                cout<<pArregloEmpleados[i]->RFC<<endl;
                b++;
            }
        }
    for(int i = 0; i < 16;i++){
          puesto=pArregloEmpleados[i]->puesto;
            if(puesto =="S"|| puesto=="s"){
                empleadosOrdenadosIN<<"Empleado de servicio "<<c+1<<endl;
                empleadosOrdenadosIN<<pArregloEmpleados[i]->nombrecom<<endl;
                empleadosOrdenadosIN<<pArregloEmpleados[i]->direccion<<endl;
                empleadosOrdenadosIN<<pArregloEmpleados[i]->telefono<<endl;
                empleadosOrdenadosIN<<pArregloEmpleados[i]->RFC<<endl;

                cout<<"Empleado de servicio "<<c+1<<endl;
                cout<<pArregloEmpleados[i]->nombrecom<<endl;
                cout<<pArregloEmpleados[i]->direccion<<endl;
                cout<<pArregloEmpleados[i]->telefono<<endl;
                cout<<pArregloEmpleados[i]->RFC<<endl;
                c++;
            }
        }
        empleadosOrdenadosIN.close();
        
    }
      
}

