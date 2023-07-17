// ACT 70 --> K1145
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;
//MAIN FUNC
int main(){
      string nom, ape, linea;
      ofstream archivout; //Archivo de tipo out / escritura

      archivout.open("ArchivoTexto.txt"); //Creacion del Archivo de tipo out fisico
      cout<<"\nIngrese un nombre (punto para finalizar): ";cin>>nom;
      while (nom != "."){
      cout<<"\nIngrese un apellido: ";cin>>ape;
            archivout<<nom<< " "<<ape<<endl;
            cout<<"\nIngrese un nombre (punto para finalizar):";cin>>nom;
      }
      archivout.close(); //Cierre del Archivo de tipo out fisico

      cout<<"\nListado del archivo: "<<endl;
      ifstream archivin; //Archivo de tipo in/ lectura

      archivin.open("ArchivoTexto.txt"); //Creacion del Archivo de tipo in fisico
      while (!archivin.eof()){
            getline(archivin,linea);
            cout<<linea<<endl;
      }
      archivin.close();//Cierre del Archivo de tipo in fisico

      system("pause");
      return 0;
}
/***************************************************************************/
// ACT 71 --> K1145
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

//MAIN FUNC
int main(){
      int DNI, cantVend;
      string linea;

      ofstream Fout;
      Fout.open("ArchivoTexto.txt");

      cout<<"\nIngrese el DNI de un comprador (0 para terminar): ";cin>>DNI;
      while (DNI != 0){
            cout<<"\nIngrese cantidad comprada: ";cin>>cantVend;
            if(cantVend > 10){
            Fout<<DNI<<" "<<cantVend<<endl;
            }
            cout<<"\nIngrese el DNI de un comprador (0 para terminar): ";cin>>DNI;  
      }
      Fout.close();

      cout<<"\nListado de compradores de mas de 10 unidades:"<<endl;
      ifstream Fin;
      
      Fin.open("ArchivoTexto.txt");
      while (!Fin.eof()){
            getline(Fin,linea);
            cout<<linea<<endl;
      }
      Fin.close();

      system("pause");
      return 0;
}
/***************************************************************************/
// ACT 72 --> K1145
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

//MAIN FUNC
int main(){
      int Legajo, materia;
      string linea1;

      ofstream FileMat4;
      ofstream FileMat8;

      FileMat4.open("ArchivoTexto1.txt");
      FileMat8.open("ArchivoTexto2.txt");

      cout<<"\nIngrese el Legajo del alumno: ";cin>>Legajo;
      while (Legajo != 0){
            cout<<"\nIngrese materia a anotarse ( 4 o 8 / 0 PARA terminar): ";cin>>materia;
            if(materia == 4){
            FileMat4<<Legajo<<endl;
            }
            if(materia == 8){
                  FileMat8<<Legajo<<endl;
            }
      cout<<"\nIngrese materia a anotarse ( 4 o 8 / 0 PARA terminar): ";cin>>materia;

      }
      FileMat4.close();
      FileMat8.close();

      cout<<"\nListado de alumnos MATERIA 4:"<<endl;
      ifstream FileMat4;

      FileMat4.open("ArchivoTexto.txt");
      while (!FileMat4.eof()){
            getline(FileMat4,linea1);
            cout<<linea1<<endl;
      }
      FileMat4.close();

      cout<<"\nListado de alumnos MATERIA 8:"<<endl;
      ifstream FileMat8;
      
      FileMat8.open("ArchivoTexto.txt");
      while (!FileMat8.eof()){
            getline(FileMat8,linea1);
            cout<<linea1<<endl;
      }
      FileMat8.close();

      system("pause");
      return 0;
}
/***************************************************************************/
// ACT 73 --> K1145
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;
//MAIN FUNC
int main(){

      system("pause");
      return 0;
}
/***************************************************************************/
// ACT 74 --> K1145
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

//Definimos el Struct que complementa a nuestro Archivo Binario
struct  tVenta{ 
      int Cod;
      int CantVend;
};

//DEF FUNCS
void GenerarArchivo(){
      FILE *archviotas;  //Es el puntero al archivo fisico que tengo en el disco
      archviotas = fopen("Ventas.dat", "wb"); //Abrimos el archivo en modo "wb" = write Binary
      tVenta Rventa;

      cout<<"\nIngrese codigo de producto (0 para cortar): ";cin>>Rventa.Cod;
      while (Rventa.Cod != 0){
            cout<<"\nIngrese la cantidad vendida: ";cin>>Rventa.CantVend;
            fwrite(&Rventa, sizeof (Rventa), 1, archviotas); //Graba el struct indicado al archivo indicado
                        //Con el sizeof marcamos el tamaño de bytes del archivo asi despues lo emite
            cout<<"\nIngrese codigo de producto (0 para cortar): ";cin>>Rventa.Cod;
      }
      fclose(archviotas); //Cerramos el archivo 
}
//En esta FUNCION nosotros creamos el archivo binario

void LeerArchivo(){
      FILE *archviotas; //Puntero al archivo
      archviotas = fopen("Ventas.dat", "rb"); //Abrimos el archivo en modo "rb" = read Binary
      tVenta Rventa;
      if(archviotas == NULL){  //Con esto nos aseguramos que el archivo exista y se pueda leer
            cout<<"\nERROR no se pudo leer el archivo"<<endl; 
            exit(1);
      }
      fread(&Rventa, sizeof(Rventa), 1, archviotas); //Lee el registro indicado al archivo indicado
      while (!feof (archviotas)){
            cout<<"\nCodigo de producto: "<<Rventa.Cod<<endl;
            cout<<"\nCantidad vendida: "<<Rventa.CantVend<<endl;
            fread(&Rventa, sizeof(Rventa), 1, archviotas);
      }
      fclose(archviotas); //Cerramos el archivo 
}
//En esta FUNCION nosotros leemos el archivo binario

//MAIN FUNC
int main(){
      GenerarArchivo();
      LeerArchivo();

      system("pause");
      return 0;
}
/***************************************************************************/
// ACT 75 --> K1145
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

//Definimos el Struct que complementa a nuestro Archivo Binario
struct  tVenta{ 
      int Cod;
      int CantVend;
};

//DEF FUNCS
void GenerarArchivo(){
      FILE *archviotas;  //Es el puntero al archivo fisico que tengo en el disco
      archviotas = fopen("Ventas.dat", "wb"); //Abrimos el archivo en modo "wb" = write Binary
      tVenta Rventa;

      cout<<"\nIngrese codigo de producto (0 para cortar): ";cin>>Rventa.Cod;
      while (Rventa.Cod != 0){
            cout<<"\nIngrese la cantidad vendida: ";cin>>Rventa.CantVend;
            fwrite(&Rventa, sizeof (Rventa), 1, archviotas); //Graba el struct indicado al archivo indicado
                        //Con el sizeof marcamos el tamaño de bytes del archivo asi despues lo emite
            cout<<"\nIngrese codigo de producto (0 para cortar): ";cin>>Rventa.Cod;
      }
      fclose(archviotas); //Cerramos el archivo 
}
//En esta FUNCION nosotros creamos el archivo binario

void LeerArchivo(){
      FILE *archviotas; //Puntero al archivo
      archviotas = fopen("Ventas.dat", "rb"); //Abrimos el archivo en modo "rb" = read Binary
      tVenta Rventa;
      if(archviotas == NULL){  //Con esto nos aseguramos que el archivo exista y se pueda leer
            cout<<"\nERROR no se pudo leer el archivo"<<endl; 
            exit(1);
      }
      fread(&Rventa, sizeof(Rventa), 1, archviotas); //Lee el registro indicado al archivo indicado
      while (!feof (archviotas)){
            cout<<"\nCodigo de producto: "<<Rventa.Cod<<endl;
            cout<<"\nCantidad vendida: "<<Rventa.CantVend<<endl;
            fread(&Rventa, sizeof(Rventa), 1, archviotas);
      }
      fclose(archviotas); //Cerramos el archivo 
}
//En esta FUNCION nosotros leemos el archivo binario

//MAIN FUNC
int main(){
      int opc;
      do{   cout<<"\nIngrese una operacion: "<<endl;
            cout<<"\nIngrese (1) para Generar Archivo: "<<endl;
            cout<<"\nIngrese (2) para Leer Archivo: "<<endl;
            cout<<"\nIngrese (0) para Salir: "<<endl;
            cin>>opc;
      switch (opc){
      case 1:  
            GenerarArchivo();
            cout<<"\nOpcion elegida es GENERAR"<<endl;
            break;
      
      case 2: 
            LeerArchivo();
            cout<<"\nOpcion elegida es LEER"<<endl;
            break;
      case 0:
            cout<<"\nAQUI FINALIZA"<<endl;
            break;
      default : cout<<"ERROR! la opcion elegida no existe"<<endl;
            break;
      }
      }while(opc != 0);
      system("pause");
      return 0;
}
/***************************************************************************/
// ACT 76 --> K1145
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

//Definimos el Struct que complementa a nuestro Archivo Binario
struct  Ralu{ 
      int Legajo, P1, P2, Rp1, Rp2;
};

//DEF FUNCS
bool Aprobado(Ralu Rnotas){
      bool aprobado = false;
      if((Rnotas.P1 >=6) || (Rnotas.Rp1 >=6)){
            if((Rnotas.P2 >=6) || (Rnotas.Rp2 >=6)){
                  aprobado = true;
            }
      }
      return aprobado;
}
int AnalisiNota(int P1, int P2, int Rp1, int Rp2){
      int result;
      if ((P1 >= 8 || Rp1 >= 8) && (P2 >= 8)){
            result = 1;
      }
      else if ((P2 >= 8 || Rp2 >= 8) && (P1 >= 8)){
            result = 1;
      }
      else{
            result =0;
      }
      return result;
}
void GenerarArchivo(){
      Ralu Rnotas;
      FILE *FileAlumno = fopen("Alumnos.dat", "w+b");
      cout << "_________________________________________" << endl;

      cout<<"\nIngrese el legajo del alumno (0 para terminar): ";cin>>Rnotas.Legajo;
      while (Rnotas.Legajo != 0){
            Rnotas.Rp1=0;
            Rnotas.Rp2 =0;

            //PARCIALES
            cout<<"\nIngrese la nota del primer parcial: ";cin>>Rnotas.P1;
            cout<<"\nIngrese la nota del segundo parcial: ";cin>>Rnotas.P2;

            if(Rnotas.P1 < 6){
            cout<<"\nIngrese la nota del Recu primer parcial: ";cin>>Rnotas.Rp1;
            }
            if(Rnotas.P2 < 6){
            cout<<"\nIngrese la nota del Recu segundo parcial: ";cin>>Rnotas.Rp2;
            }
            fwrite(&Rnotas, sizeof(Rnotas), 1, FileAlumno);
            cout << "_________________________________________" << endl;

            cout<<"\nIngrese el legajo del alumno (0 para terminar): ";cin>>Rnotas.Legajo;
      }
      fclose(FileAlumno);

}
void LeerArchivo(){
      Ralu Rnotas;
      FILE *FileAlumno = fopen("Alumnos.dat", "r+b");

      if(FileAlumno == NULL){
            cout<<"\nNO SE LOGRO LEER EL ARCHIVO";
      }
      else{
            cout<<"\nALUMNOS CARGADOS:"<<endl;
            cout<<"\n Legajo | 1 Par | 2 Par | Rec 1P | Rec 2P "<<endl;
            //fread(&Rnotas, sizeof(Rnotas), 1, FileAlumno);
            while (fread(&Rnotas, sizeof(Rnotas), 1, FileAlumno)){
                  cout<< "   "<<Rnotas.Legajo<<"         "<<Rnotas.P1 << "         " << Rnotas.P2 << "         " << Rnotas.Rp1 << "         " << Rnotas.Rp2 << endl;
            }
      }
      fclose(FileAlumno);
}
void ProceArchivo(){
      int cant_Prom=0;
      Ralu Rnotas;

      FILE *FileAlumno = fopen("Alumnos.dat", "r+b");
      cout<<"\nALUMNOS CARGADOS:"<<endl;
      cout<<"\n Legajo | 1 Par | 2 Par | Rec 1P | Rec 2P "<<endl;

      fread(&Rnotas, sizeof(Rnotas), 1, FileAlumno);
      while (!feof(FileAlumno)){
            if(Aprobado(Rnotas)){
            cout<< "   "<<Rnotas.Legajo<<"         "<<Rnotas.P1 << "         " << Rnotas.P2 << "         " << Rnotas.Rp1 << "         " << Rnotas.Rp2 << endl;
            cant_Prom += AnalisiNota(Rnotas.P1, Rnotas.P2, Rnotas.Rp1, Rnotas.Rp2);
            }
            fread(&Rnotas, sizeof(Rnotas), 1, FileAlumno);
      }
      cout << endl << "PROMOCIONARON " << cant_Prom << " EN TOTAL" << endl;
      cout << endl;
      fclose(FileAlumno);
}
//MAIN FUNC
int main(){
      GenerarArchivo();
      LeerArchivo();
      ProceArchivo();

      system("pause");
      return 0;
}
/***************************************************************************/
// ACT 77 --> K1145
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct TProd{
      int CodProd, cantVend;
      float PU; 
};

//DEF FUNCS
void GenerarArchivo(){

      TProd RProd;
      FILE *Fileprod = fopen("Productos.dat", "w+b");
      cout << "_________________________________________" << endl;
      
       cout<<"\nIngrese el codigo de producto (0 para cortar): ";cin>>RProd.CodProd;
            while (RProd.CodProd !=0) {
                  cout<<"\nIngrese cantidad vendida: ";cin>>RProd.cantVend;
                  cout<<"\nIngrese el precio unitario del producto: ";cin>>RProd.PU;
                  fwrite(&RProd, sizeof(RProd), 1, Fileprod);
            
            cout << "_________________________________________" << endl;
            cout<<"\nIngrese el codigo de producto (0 para cortar): ";cin>>RProd.CodProd;                  
            };

      fclose(Fileprod);
}
void LeerArchivo(){
      TProd RProd;
      FILE *Fileprod = fopen("Productos.dat", "r+b");

      if(Fileprod ==NULL){
            cout<<"\nNO SE LOGRO LEER EL ARCHIVO";
            exit(1);
      }
      else{
            cout << "_________________________________________" << endl;
            cout<<endl;
            cout<<"\nInformacion de los Productos: "<<endl;
            cout<<"\nCodProd: "<< "  "<<"Precio total $: "<<endl;

            fread(&RProd, sizeof(RProd), 1, Fileprod);
            while (!feof (Fileprod)) {
                  cout<<RProd.CodProd<<"    "<<(RProd.cantVend*RProd.PU)<<endl;
            fread(&RProd, sizeof(RProd), 1, Fileprod);

            } 
      }
      fclose(Fileprod);
}

void BuscarenVec(TProd VP[], int a, int CodProd, int &pos){
      pos = 0;
      while ((VP[pos].CodProd != CodProd) && (pos<=31)) {
            pos = pos +1;
      }     
}

void ActualizVec(TProd VP[], int &a){
      FILE *Fileprod = fopen("Productos.dat", "wb");
      TProd RProd;
      for (int i=0; i <= a; i++){
            RProd = VP[i];
            fwrite(&RProd, sizeof(RProd),1, Fileprod);
      }
      fclose(Fileprod);
}

//MAIN FUNC
int main(){
      int CodProd, CantP, a, pos, i, opc;
      TProd VP[30];
      a=0;
      do {
            cout<<"\nIngrese una operacion: "<<endl;
            cout<<"\n 1 = Generar y mostrar el archivo"<<endl;
            cout<<"\n 2 = Venta"<<endl;
            cout<<"\n 0 = Salir"<<endl;
            cin>>opc;

      switch (opc) {
      case 0:
            cout<<"\nPrograma finalizado";
            break;

      case 1:
            GenerarArchivo();
            LeerArchivo();
            break;
      case 2:
            TProd RProd;
            FILE *Fileprod;
            Fileprod = fopen("Productos.dat", "rb");

            fread(&RProd, sizeof(RProd), 1, Fileprod);
            while (!feof (Fileprod)) {
                  VP[a] = RProd;

                  fread(&RProd, sizeof(RProd), 1, Fileprod);
                  a++;
            }
            cout << "_________________________________________" << endl;
            cout<<"\nIngrese el codigo de producto (0 para cortar): ";cin>>CodProd;
            while (CodProd != 0) {
                  BuscarenVec(VP, a, CodProd, pos);
                  if(pos > 30){
                        cout<<"\nEl producto no existe";
                  }
            }
            ActualizVec(VP, a);
            LeerArchivo();
            break;      
            }
      }while(opc !=0);

      system("pause");
      return 0;
}
/***************************************************************************/
// ACT 78 --> K1145
#include <iostream>
#include <stdio.h>
using namespace std;

struct Tproductos
{
  int CodProd;
  int Stock;
  float Punit;
};

void GenerarArchivoPro () {
  FILE *aProds = fopen ("Productos.dat", "wb");
  Tproductos RProds;
  cout << "Ingresar Codigo de Producto, 0 para cortar" << endl;
  cin >> RProds.CodProd;

  while (RProds.CodProd != 0) {

      cout << "Ingresar precio unitario" << endl;
      cin >> RProds.PU;
      cout << "ingrese stock de producto" << endl;
      cin >> RProds.Stock;
      fwrite (&RProds, sizeof (RProds), 1, aProds);
      cout << "ingrese el codigo de producto (0 para cortar)" << endl;
      cin >> RProds.CodProd;
    };
  fclose (aProds);
};

void LeerArchivoProds () {

  tProds RProds;
  FILE *aProds = fopen ("Productos.dat", "rb");
  if (aProds == NULL) {
      cout << "ERROR! No existe el archivo" << endl;
      return;
    }
  cout << "CodProd    P.Unit   Stock" << endl;
  fread (&RProds, sizeof (RProds), 1, aProds);
  while (!feof (aProds)) {
      cout << RProds.CodProd << "      ";
      cout << RProds.PU << "      ";
      cout << RProds.Stock << endl;
      fread (&RProds, sizeof (RProds), 1, aProds);
    };
  fclose (aProds);
};

void BuscarenVector (tProds VP[], int c, int CodProd, int &pos) {
  pos = 0;
  while ((VP[pos].CodProd != CodProd) && (pos <= 31)) {
      pos= pos + 1;
    }
}

void ActualizarProds (tProds VP[], int &c) {
  int i;
  FILE *aProds = fopen ("Productos.dat", "wb");
  tProds RProds;

  for (i = 0; i <= c; i++){
      RProds = VP[i];
      fwrite (&RProds, sizeof (RProds), 1, aProds);
     
    };
  fclose (aProds);
}

int main () {
  int CodProd, CantP, c, pos, i;
  int topep = 0;
  tProds VP[30];
  int opc = -1;
  float Imp;
  c=0;

do{
  cout << "Ingrese opcion deseada" << endl;
  cout << "1) Generar y mostrar archivo de productos" << endl;
  cout << "2)Venta" << endl;
  cout << "0)Salir" << endl;
  cin >> opc;

  switch (opc){
    case 0:
      //salir
      cout << "Gracias por usar el programa";
      break;

    case 1:
      //generar archivo
      GenerarArchivoPro ();
      LeerArchivoProds ();
      break;

    case 2:
      tProds RProds;
      FILE *aProds;
      aProds = fopen ("Productos.dat", "rb");
      fread (&RProds, sizeof (RProds), 1, aProds);
      while (!feof (aProds)) {
	  VP[c] = RProds;
	  fread (&RProds, sizeof (RProds), 1, aProds);
	  c++;
	}

      cout << "Ingresar Codigo de Producto, 0 para cortar" << endl;
      cin >> CodProd;
      while (CodProd != 0) {
	  cout << "ingrese Cantidad Pedida" << endl;
	  cin >> CantP;
	  BuscarenVector (VP, c, CodProd, pos);
	  if (pos > 30) {
	    cout << "el producto solicitado no existe " << endl;
	  }
	  else if (CantP > VP[pos].Stock) {
	      cout << "no puede entregarse el pedido por stock insuficiente"
		<< endl;
	    }
	  else if (CantP <= VP[pos].Stock) {
	      VP[pos].Stock -= CantP;
	      Imp= VP[pos].PU*CantP;
	      cout << "El pedido solicitado tiene un importe de " << Imp << endl;
	    }
	  cout << "Ingresar Codigo de Producto, 0 para cortar" << endl;
      cin >> CodProd;
	}
      ActualizarProds (VP, c);
      LeerArchivoProds();
    } 
}
while (opc!= 0);
  return 0;
}
/***************************************************************************/
// ACT 78 --> K1145
#include <iostream>
#include <stdio.h>
using namespace std;

struct Tproductos {
  int CodProd;
  int Stock;
  float Punit;
};

//PROTORIPOS DE FUNC
void GenerarArchivoPro();
void LeerArchivPro ();
void BuscVectorProductos(Tproductos [], int , int , int &);
void ActualizarProds (Tproductos [], int &);

//FUNC MAIN
int main () {
  int CodProd, CantPedida, a=0, posi, i;
  Tproductos VecProd[30];
  int operacion;
  float Importe;
  
do{
      cout <<"\n-------------MENU--------------" << endl;
	cout << "0) Finalizar programa         " << endl;
	cout << "1) Crear y Leer archivo de productos" << endl;
	cout << "2) Crear archivo Deposito" << endl;
      cout <<"----------------------------------" << endl;
	cout << "Ingrese Operacion: " << endl;
	cin >> operacion;

  switch (operacion){
    case 0:
      cout << "Gracias por usar el programa";
      break;

    case 1:
      GenerarArchivoPro ();
      LeerArchivPro ();
      break;

    case 2:
      Tproductos Rproductos;
      FILE *FileProds;
      FileProds = fopen ("Productos.dat", "rb");
      fread (&Rproductos, sizeof (Rproductos), 1, FileProds);
        while (!feof (FileProds)) {
	        VecProd[a] = Rproductos;
	        fread (&Rproductos, sizeof (Rproductos), 1, FileProds);
	        a++;
	      }

      cout << "\nIngresar Codigo de Producto, (0 para cortar): " << endl;
      cin >> CodProd;
        while (CodProd != 0) {
	      cout << "\ningrese Cantidad Pedida" << endl;
	      cin >> CantPedida;
	      BuscVectorProductos (VecProd, a, CodProd, posi);
	    if (posi > 30) {
	        cout << "\nEl producto solicitado no existe " << endl;
	      }

	    else if (CantPedida > VecProd[posi].Stock) {
	        cout << "\nNo puede entregarse el pedido por stock insuficiente"<< endl;
	      }

	    else if (CantPedida <= VecProd[posi].Stock) {
	        VecProd[posi].Stock -= CantPedida;
	        Importe= VecProd[posi].Punit*CantPedida;
	        cout << "\nEl pedido solicitado tiene un importe de " << Importe << endl;
	      }

	    cout << "\nIngresar Codigo de Producto, (0 para cortar): " << endl;
      cin >> CodProd;
	  }
      ActualizarProds (VecProd, a);
      LeerArchivPro();
    }  
}
while (operacion!= 0);
  return 0;
}

//DEF FUNCS
void GenerarArchivoPro () {
  FILE *FileProds = fopen ("Productos.dat", "wb");
  Tproductos Rproductos;
  cout << "Ingresar Codigo de Producto, (0 para finalizar)" << endl;
  cin >> Rproductos.CodProd;

  while (Rproductos.CodProd != 0) {

      cout << "Ingresar precio unitario" << endl;
      cin >> Rproductos.Punit;
      cout << "ingrese stock de producto" << endl;
      cin >> Rproductos.Stock;
      fwrite (&Rproductos, sizeof (Rproductos), 1, FileProds);
      cout << "ingrese el codigo de producto (0 para finalizar)" << endl;
      cin >> Rproductos.CodProd;
    };
  fclose (FileProds);
};

void LeerArchivPro () {

  Tproductos Rproductos;
  FILE *FileProds = fopen ("Productos.dat", "rb");
  if (FileProds == NULL) {
      cout << "ERROR! No existe el archivo" << endl;
      return;
    }
  cout << "CodProd    P.Unit   Stock" << endl;
  fread (&Rproductos, sizeof (Rproductos), 1, FileProds);
  while (!feof (FileProds)) {
      cout << Rproductos.CodProd << "      ";
      cout << Rproductos.Punit << "      ";
      cout << Rproductos.Stock << endl;
      fread (&Rproductos, sizeof (Rproductos), 1, FileProds);
    };
  fclose (FileProds);
};

void BuscVectorProductos (Tproductos VecProd[], int a, int CodProd, int &posi) {
  posi = 0;
  while ((VecProd[posi].CodProd != CodProd) && (posi <= 31)) {
      posi += 1;
    }
}

void ActualizarProds (Tproductos VecProd[], int & a) {
  FILE *FileProds = fopen ("Productos.dat", "wb");
  Tproductos Rproductos;

  for (int i = 0; i <= a; i++) {
      Rproductos = VecProd[i];
      fwrite (&Rproductos, sizeof (Rproductos), 1, FileProds);
    };
  fclose (FileProds);
}
