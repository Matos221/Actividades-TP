//ACT 60 --> K1145
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

struct Ttriangulos{
      int L1, L2, L3;
};

//PROTOTIPOS DE FUNCS
void IngresarDatos(Ttriangulos &);
void Perimetro( Ttriangulos, int &);

//FUNC MAIN
int main(){
 Ttriangulos Rtriangulos;
 int suma=0;
 char rpt;
 do{
  IngresarDatos(Rtriangulos);
  Perimetro(Rtriangulos, suma);
  cout<<"\nDesea realizar un nuevo ingreso de valores (S/N): ";cin>>rpt;
 }while((rpt == 'S') || (rpt == 's'));

 cout<<"\nGracias por usar el programa"<<endl;
      getch();
      return 0;
}
//DEF DE FUNCS
void IngresarDatos(Ttriangulos &Rtriangulos){
      cout<<"\nIngrese el lado 1 del triangulo: ";cin>>Rtriangulos.L1;
      cout<<"\nIngrese el lado 2 del triangulo: ";cin>>Rtriangulos.L2;
      cout<<"\nIngrese el lado 3 del triangulo: ";cin>>Rtriangulos.L3;
      cout<<"\tLados ingresados de forma correcta";
      cout<<"\n";
}
void Perimetro(Ttriangulos Rtriangulos,int &suma){
      suma = Rtriangulos.L1 + Rtriangulos.L2 + Rtriangulos.L3;
      cout<<"\nLa suma dio de resultado: "<<suma;
}
/*************************************************************************/
//ACT 61 --> K1145
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

struct Talumnos{
      int edad;
      char nombre[20];
} ;

//PROTOTIPOS DE FUNCS
void CargarVecAlu(Talumnos [], int , int &);
float CalcularProm(int, int);

//FUNC MAIN
int main(){
      int n, suma=0, i;
      float Promedades=0;
      Talumnos VecAlu[70];

      cout<<"\nIngrese cantidad de alumnos (max 70): ";cin>>n;
      CargarVecAlu(VecAlu, n, suma);
      Promedades = CalcularProm(suma, n);
      cout<<"\nEl promedio de edades es: "<<Promedades<<endl;

      cout<<"\n";
      cout<<"\nAlumnos que superaron el promedio: "<<endl;
      for(i=0; i<=n-1; i++){
            if(VecAlu[i].edad > Promedades){
                  cout<<VecAlu[i].nombre<<"   "<<VecAlu[i].edad<<endl;
            }
      }
      getch();
      return 0;

}
//DEF DE FUNCS
void CargarVecAlu(Talumnos VecAlu[], int n, int &suma){
      for(int i=0; i<n-1; i++){
            cout<<"\nIngrese la edad del alumno: ";cin>>VecAlu[i].edad;
            cout<<"\nIngrese el nombre del alumno: ";cin>>VecAlu[i].nombre;
            suma += VecAlu[i].edad;
      }
}
float CalcularProm(int suma, int n){
      return suma / (n*1.0);
}
/*************************************************************************/
//ACT 62 --> K1145
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

struct Tproductos{
      int CodProd;
      float PrecioUnit;
};
struct Tventas{
      int CodProd, Cantvend;
};


//PROTOTIPOS DE FUNCS
void BuscarProd(Tproductos [], int , int&, int);

//FUNC MAIN
int main(){
      Tproductos VecProd[100];
      Tventas Rventas;
      int pos, n;
      cout<<"\nIngrese la cantidad de producto: ";cin>>n;
      cout<<"\n"<<endl;

      cout<<"\t==== LOTE DE PRODUCTOS ==== "<<endl;
      for(int i=0; i<=n; i++){
            cout<<"\nIngrese codigo de producto: ";cin>>VecProd[i].CodProd;
            cout<<"\nIngrese precio unitario: ";cin>>VecProd[i].PrecioUnit;
      }

      cout<<"\n"<<endl;
      cout<<"\t==== LOTE DE VENTAS ===== "<<endl;
      
      cout<<"\nIngrese codigo de producto (0 para cortar): ";cin>>Rventas.CodProd;
      while(Rventas.CodProd !=0){
      cout<<"\nIngrese cantidad vendida: ";cin>>Rventas.Cantvend;
      BuscarProd(VecProd, Rventas.CodProd, pos, n);
      cout<<"Cod Prod"<<"    "<<"total a abonar"<<endl;
      cout<<VecProd[pos].CodProd<<"         "<<Rventas.Cantvend * VecProd[pos].PrecioUnit<<endl;
      cout<<"\nIngrese codigo de producto (0 para cortar): ";cin>>Rventas.CodProd;
      
      }
      getch();
      return 0;
}
//DEF DE FUNCS
void BuscarProd(Tproductos VecProd[], int CodProd, int&pos, int n){
      pos =0;
      while ((VecProd[pos].CodProd != CodProd) && (pos<n)){
            pos++;
      }
      if(pos ==n){
            pos = -1;
      }
}
/******************************************************************/
//ACT 63 --> K1145
#include <iostream>
using namespace std;

struct tVuelo {       //necesito este vector para cargar los datos más un campo para acumular rechazos
   int CodVuelo;
   int CantPasDis;
   int PasNoVend;
};

struct tPedido {       //no es necesario este registro; sería sólo una cuestión organizativa
   int CodVuelo;
   int CantPasSol;
};

void BuscarenVec(tVuelo vvuelos[], int CodVuelo, int &pos){
   pos=0;
//   while(pedidos.CodVuelo.compare(vuelos[pos].CodVuelo) != 0){    si el cod de vuelo fuese de tipo cadena de caracteres
   while(vvuelos[pos].CodVuelo != CodVuelo) {
      pos++;
   };
};

// Este BuscarenVec2 es por si hay que considerar que el elemento a buscar puede no estar
// en este ejercicio no es necesario ya que el usuario ingresa pedidos de vuelos existentes
void BuscarenVec2(tVuelo vvuelos[], int n, int CodVuelo, int &pos){
   pos=0;
   while((vvuelos[pos].CodVuelo != CodVuelo) && (pos<n)) {
      pos++;
   };
   if (pos==n) {      
     pos=-1;    // -1 como señal de no encontrado 
   }  
};

//En este caso se recibe todo el vector como parámetro aunque se trabajará con una sola posición
void AnalizarDisponibilidad(tPedido Rpedido, tVuelo vvuelo[], int pos){
   if(Rpedido.CantPasSol<=vvuelo[pos].CantPasDis){
         cout << "--INFORMACION DE LA VENTA--" << endl;
         cout << "Cod de vuelo: " << Rpedido.CodVuelo << endl;
         cout << "Pasajes vendidos: " << Rpedido.CantPasSol << endl;
         vvuelo[pos].CantPasDis = vvuelo[pos].CantPasDis - Rpedido.CantPasSol;
    } 
    else {
        cout << "-- No hay suficientes pasajes para dicho vuelo --" << endl;
        vvuelo[pos].PasNoVend = vvuelo[pos].PasNoVend + Rpedido.CantPasSol;
    }

};

//En este otro caso se recibe sólo el REGISTRO de la posición del vector con la que se trabajará
void AnalizarDisponibilidad2(tPedido Rpedido, tVuelo & Rvuelo){
   if(Rpedido.CantPasSol<=Rvuelo.CantPasDis){
         cout << "--INFORMACION DE LA VENTA--" << endl;
         cout << "Cod de vuelo: " << Rpedido.CodVuelo << endl;
         cout << "P asajes vendidos: " << Rpedido.CantPasSol << endl;
         Rvuelo.CantPasDis = Rvuelo.CantPasDis - Rpedido.CantPasSol;
    } 
    else {
        cout << "-- No hay suficientes pasajes para dicho vuelo --" << endl;
        Rvuelo.PasNoVend = Rvuelo.PasNoVend + Rpedido.CantPasSol;
    }

};

void Informes(tVuelo vvuelos[], int n){
   int i;
   cout << "--- LISTADO ---" << endl;
   for(i=0;i<=n-1;i++){
         cout << endl;
         cout << endl;
         cout << "CODIGO DE VUELO: " << vvuelos[i].CodVuelo << endl;
         cout << "Pasajes disponibles: " << vvuelos[i].CantPasDis << endl;
         cout << "Pasajes no vendidos: " << vvuelos[i].PasNoVend << endl;
         cout << "------------------------" << endl;
      };
}

int main() {
   tVuelo vvuelos[500];
   tPedido Rpedido;
   int i,pos, n;

   cout << "Ingrese cantidad de vuelos" << endl;
   cin >> n;
   cout << "--INFORMACION DE LOS VUELOS--" << endl;
   for (i=0;i<=n-1;i++) {
      cout << "Ingrese el codigo de vuelo: ";
      cin >>vvuelos[i].CodVuelo;
      cout << "Cantidad de pasajes disponibles: ";
      cin >> vvuelos[i].CantPasDis;
      vvuelos[i].PasNoVend = 0;
   };
   cout << "---------------------" << endl;
   

   cout << "--VENTA DE PASAJES--" << endl;
   cout << "Ing el codigo de vuelo deseado: ";
   cin >> Rpedido.CodVuelo;
   while(Rpedido.CodVuelo!=0){
      cout << "Ingr la cant de pasajes solicit: ";
      cin >> Rpedido.CantPasSol;
      BuscarenVec(vvuelos,Rpedido.CodVuelo,pos);  //normalmente se pasa el n del vector pero acá no es necesario porque encuentra seguro el dato 
//      BuscarenVec2(vvuelos,n,Rpedido.CodVuelo,pos);
//      if pos == 1 quiere decir que no lo encontró
      AnalizarDisponibilidad2(Rpedido,vvuelos[pos]);    //sólo paso esa pos del vector QUE ES UN REGISTRO 
//      AnalizarDisponibilidad(Rpedido,vvuelos,pos);     //paso todo el vector (no es necesario ya que voy a trabajar con la posic pos)
      cout << "---------------------" << endl;;
      cout << "Ing el codigo de vuelo deseado: ";
      cin >> Rpedido.CodVuelo;
   };

   Informes(vvuelos, n);

   cout << "---------FIN DEL PROGRAMA---------";
   return 0;
}