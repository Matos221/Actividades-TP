//ACT 80 --> K1145
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Talumnos{
      char Nom[20];
      int edad;
};

void GenerarArchivo(){
      Talumnos Ralu;
      FILE *f=fopen("Alumnos.dat", "wb");
      cout<<"\nIngrese la edad de un alumno (0 para cortar): ";cin>>Ralu.edad;

      while(Ralu.edad !=0){
            cout<<"\nIngrese el nombre del alumno: ";cin>>Ralu.Nom;
            fwrite(&Ralu, sizeof(Ralu), 1, f);

            cout<<"\nIngrese la edad de un alumno (0 para cortar): ";cin>>Ralu.edad;
      }
      fclose(f);
}     
void LeerArchivo(){
      FILE *f = fopen("Alumnos.dat", "rb");
      Talumnos Ralu;

      if(f == NULL){
            cout << "ERROR! No existe el archivo" << endl;
      }
      fread(&Ralu, sizeof(Ralu), 1, f);
      while (!feof(f)){

            cout<<"Nombre: "<<Ralu.Nom<<endl;
            cout<<"Edad: "<<Ralu.edad<<endl;
            fread(&Ralu, sizeof(Ralu), 1, f);
      }
      fclose(f);
}
int Cargaralumnos(Talumnos VecAlu[70]){
      FILE *f=fopen("Alumnos.dat", "rb");
      Talumnos Ralu;
      int i=0;
      if(f == NULL){
            cout << "ERROR! No existe el archivo" << endl;
            return 1;
      }
      fread(&Ralu, sizeof(Ralu), 1, f);
      while (!feof(f)){
            strcpy( VecAlu[i].Nom, Ralu.Nom);
            VecAlu[i].edad = Ralu.edad;
            fread(&Ralu, sizeof(Ralu), 1, f);
            i++;
            
      }
      fclose(f);
      return i;
}
void CalcPromedio(Talumnos VecAlu[70], int n){
      float promedio=0;
      int suma =0;

      for(int i=0; i<=n-1; i++){
            suma += VecAlu[i].edad;
            i++;
      }
      promedio = suma /n * 1.0;
      cout<<"\nPromedio de edades: "<<promedio<<endl;
      cout<<"--------------------------------------------"<<endl;

      cout<<"\nAlumnos que superaron el promedio: "<<endl;
      cout<<"Nombre:          "<<"Edad:          "<<endl;
      for(int i=0; i<=n-1; i++){
            if(VecAlu[i].edad > promedio){
                  cout<<VecAlu[i].Nom<<"     "<<VecAlu[i].edad<<endl;
            }
            i++;
      } 
}
int main(){
      Talumnos VecAlu[70];
      int operacion, n=0;

      do {
            cout<<"Ingrese la opcion deseada: "<<endl;
            cout<<"1) Generar Archivo de Alumnos"<<endl;
            cout<<"2) Mostrar Archivo Alumnos"<<endl;
            cout<<"3) Calcular promedio y Lista de alumnos"<<endl;
            cout<<"0) Salir"<<endl;
            cin >> operacion;

            switch (operacion) {
            case 0:
                  cout<<"\nFinal del programa"<<endl;
                  break;
            case 1:
                  GenerarArchivo();
                  break;
            case 2:
                  LeerArchivo();
                  break;
            case 3:
                  n = Cargaralumnos(VecAlu);
                  CalcPromedio(VecAlu, n);
                  break;

            default:
                  cout <<"\nERROR! La opcion seleccionada es invalida"<<endl;
                  break;
            }
      }while (operacion !=0);
      return 0;
}
/********************************************************************/
// ACT 81 y 82 --> K1145
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct RvuelosF {
      int CodVue, pasajesDispo;
};
struct RvuelosV {
      int CodVue, pasajesDispo, pasajesRecha;
};
struct Rpedidos {
      int Dni, CodVue, cantPasjSolic;
};
//DEF FUNC
void GenerarArchivoVuelos() {
      RvuelosF Tvuelos;
      FILE *FileVue = fopen("Vuelos.dat", "wb");

      cout<<"\nIngrese el codigo (0 para terminar): ";cin>>Tvuelos.CodVue;
      while (Tvuelos.CodVue != 0) {

            cout<<"\nIngrese la cantidad de pasajes disponibles: ";cin>>Tvuelos.pasajesDispo;
             fwrite(&Tvuelos, sizeof(Tvuelos), 1, FileVue);
             cout<<"\nIngrese el codigo (0 para terminar): ";cin>>Tvuelos.CodVue;
      }
      fclose(FileVue);
}
void GenerarArchivoPedidos() {
      Rpedidos Tpedidos;
      FILE *FileVue = fopen("Pedidos.dat", "wb");

      cout<<"\nIngrese el codigo (0 para terminar): ";cin>>Tpedidos.CodVue;
      while (Tpedidos.CodVue != 0) {

            cout<<"\nIngrese la cantidad de pasajes solicitados: ";cin>>Tpedidos.cantPasjSolic;
             fwrite(&Tpedidos, sizeof(Tpedidos), 1, FileVue);
             cout<<"\nIngrese el codigo (0 para terminar): ";cin>>Tpedidos.CodVue;
      }
      fclose(FileVue);
}
void LeerArchivoVuelos() {
      RvuelosF Tvuelos;
      FILE *FileVue = fopen("Vuelos.dat", "rb");

      if( FileVue == NULL) {
            cout <<"\nERROR! No existe el archivo" << endl;
            return ;
      }
      fread(&Tvuelos, sizeof(Tvuelos), 1, FileVue);
      while (!feof (FileVue)) {
            cout<<"\nCodigo: "<<Tvuelos.CodVue;
            cout<<"\nPasajes disponibles: "<<Tvuelos.pasajesDispo;
      fread(&Tvuelos, sizeof(Tvuelos), 1, FileVue);
      }
      fclose(FileVue);
}
void LeerArchivoPedido() {
      Rpedidos Tpedidos;
      FILE *FileVue = fopen("Pedidos.dat", "rb");

      if( FileVue == NULL) {
            cout <<"\nERROR! No existe el archivo" << endl;
            return ;
      }
      fread(&Tpedidos, sizeof(Tpedidos), 1, FileVue);
      while (!feof (FileVue)) {
            cout<<"\nCodigo: "<<Tpedidos.CodVue;
            cout<<"\nDni: "<<Tpedidos.Dni;
            cout <<"\nPasajes solicitados: "<< Tpedidos.cantPasjSolic<< endl;
            
      fread(&Tpedidos, sizeof(Tpedidos), 1, FileVue);
      }
      fclose(FileVue);
}
int CargarVue(RvuelosV VecVue[]) {
      FILE *FileVue= fopen("Vuelos.dat", "rb");
      RvuelosF Tvuelos;
      int i=0;

      if(FileVue == NULL){
      cout <<"\nERROR! No existe el archivo" << endl;
            exit(1);
      }
      fread(&Tvuelos, sizeof(Tvuelos), 1, FileVue);

      while (!feof (FileVue)) {
            VecVue[i].CodVue = Tvuelos.CodVue;
            VecVue[i].pasajesDispo = Tvuelos.pasajesDispo;
            VecVue[i].pasajesRecha = 0;

            fread(&Tvuelos, sizeof(Tvuelos), 1, FileVue);
            i++;
      }
      fclose(FileVue);
      return i;
}
void OrdenarXburb(RvuelosV VecVue[], int tope) {
      RvuelosV Raux;
      for(int pas=0; pas<= tope-1; pas++){

            for(int i=0; i<= tope-pas; i++){

                  if(VecVue[i].CodVue > VecVue[i+1].CodVue){
                        Raux = VecVue[i];
                        VecVue[i] = VecVue[i+1];
                        VecVue[i+1] = Raux;
                  }
            }
            pas++;
      }
}
int BuscarVue(Rpedidos Tpedido, RvuelosV VecVue[], int tope, int &pos){
      pos = 0;
      while ((pos <= tope) && (VecVue[pos].CodVue != Tpedido.CodVue)){
            pos ++;
      }
      if(pos > tope){
            pos = -1;
      }
      else return pos;
}
void AnalizPed(RvuelosV VecVue[], int tope){
      FILE *FileVue = fopen("Pedidos.dat", "rb");
      Rpedidos Tpedido;
      RvuelosV Tvuelo;
      //bool encontro;
      int posicion =0;

      while (fread(&Tpedido, sizeof(Tpedido), 1, FileVue)) {
            cout<<"\nProcesando el pedido, Vuelo: "<<Tpedido.CodVue<< "Cant.solicitada: "<<Tpedido.cantPasjSolic<<endl;
            BuscarVue(Tpedido, VecVue, tope, posicion);

            if(posicion != -1){
                  if(Tpedido.cantPasjSolic >VecVue[posicion].pasajesDispo) {
                        cout<<"\nPedido Rechazado, pasajes solicitados para el vuelo "<< Tpedido.CodVue<< "mayor a los "<< VecVue[posicion].pasajesDispo<< "disponibles" <<endl;
                        VecVue[posicion].pasajesRecha += Tpedido.cantPasjSolic;
                  }
                  else{
                        cout<<"\nDNI: "<<Tpedido.Dni<< ", pasajes vendidos: "<<Tpedido.cantPasjSolic<< ",codigo: "<<Tpedido.CodVue<<endl;
                        VecVue[posicion].pasajesDispo -= Tpedido.cantPasjSolic;
                  }
            }
            else{
                  cout<<"\nNo se encontro el codigo de vuelo"<<Tpedido.CodVue<<endl;
            }
      }
      fclose(FileVue);
}
void ImprimVue(RvuelosV VecVue[], int Cant){
      cout<< "\nESTADO FINAL DE LOS VUELOS"<<endl;
      cout<<"\nCodigo de vuelo          "<<"Pasajes Disponibles            "<< "Pasajes no vendidos          "<<endl;
      for(int cont =0; cont< Cant; cont++){
            cout<< VecVue[cont].CodVue<<"                  "<< VecVue[cont].pasajesDispo<<"                "<< VecVue[cont].pasajesRecha<<endl;
      }
}
//MAIN FUNC
int main(){
      RvuelosV VecVue[500];
      int opcion;
      int n=0;
      int c;

      do {
      cout<<"Ingrese la opcion deseada: "<<endl;
      cout<<"1) Generar y mostrar archivo vuelos"<<endl;
      cout<<"2) Generar archivo pedidos"<<endl;
      cout<<"3) Analizar los pedidos"<<endl;
      cout<<"4) Leer archivo pedidos"<<endl;
      cout<<"5) Leer archivo vuelos"<<endl;
      cout<<"0) Salir"<<endl;
      cin >> opcion;

      switch (opcion) {
      case 0:
            cout<<"\nFinal del programa"<<endl;
            break;
      case 1:
            GenerarArchivoVuelos();
            LeerArchivoVuelos();
            break;
      case 2:
            GenerarArchivoPedidos();
            LeerArchivoPedido();
            break;
      case 3:
            n = CargarVue(VecVue);
            OrdenarXburb(VecVue, n);
            // si quiero ver el vector ordenado - imprimoVuelos(vuelos,cantidad);
            AnalizPed(VecVue, n);
            ImprimVue(VecVue, n);
            break;
      case 4:
            LeerArchivoPedido();
            break;
      case 5: 
            LeerArchivoVuelos();
            break;
      default:
            cout <<"\nERROR! La opcion seleccionada es invalida"<<endl;
            break;
      }
}while (opcion !=0);
      system("pause");
      return 0;
}
/***************************************************************************/
