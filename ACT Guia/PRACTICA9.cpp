// ACT 91 ARCHIVOS --> K1145
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Talu{
      int lejago, materia;
      char nombre[20];
};
void ListarFinales(FILE *f){
      Talu Ralu;
      cout<<" LEGAJO     Cod MATERIA      NOMBRE "<<endl;
      if(f==NULL){
            cout<<"\nNo se logro crear/leer el archivo"<<endl;
            exit(1);
      }
      else{
            while(fread(&Ralu, sizeof(Ralu),1 ,f)){
                  cout<< "     " <<Ralu.lejago<< "     " <<Ralu.materia<< "     " <<Ralu.nombre<<endl;
            }
      }
}
void CargarFinales(FILE *f){
      Talu Ralu;
      cout<<"\tINSCRIPCIONES A FINALES"<<endl;
      cout<<"\nIngrese el legajo (0 para cortar): ";cin>>Ralu.lejago;
      while(Ralu.lejago !=0){
            cout<<"\nIngrese el codigo de materia: ";cin>>Ralu.materia;
            fflush(stdin);
            cout<<"\nIngrese el nombre del alumno: ";cin.getline(Ralu.nombre,25,'\n');
            
            fwrite(&Ralu, sizeof(Ralu),1, f);
            cout<<"\nIngrese el legajo (0 para cortar): ";cin>>Ralu.lejago;
      }
}
void ApareoFinales(FILE *f1, FILE *f2, FILE *f3){
      Talu Ralu1, Ralu2;

      fread(&Ralu1, sizeof(Ralu1),1 ,f1);
      fread(&Ralu2, sizeof(Ralu2),1 ,f2);

      while(!feof(f1) && !feof(f2)){
            if(Ralu1.materia <= Ralu2.materia){
                  fwrite(&Ralu1, sizeof(Ralu1),1, f3);
                  fread(&Ralu1, sizeof(Ralu1), 1,f1);
            }
            else{
                  fwrite(&Ralu2, sizeof(Ralu2),1 ,f3);
                  fread(&Ralu2, sizeof(Ralu2), 1,f2);
            }
      }
      if(feof(f2)){
            while(!feof(f1)){
                  fwrite(&Ralu1, sizeof(Ralu1),1,f3);
                  fread(&Ralu1, sizeof(Ralu1),1,f1);
            }
      }
      else{
            while(!feof(f2)){
                  fwrite(&Ralu2, sizeof(Ralu2),1,f3);
                  fread(&Ralu2, sizeof(Ralu2),1,f1);
            } 
      }
      ListarFinales(f3);
}
int main(){
      int operacion, operacionFIle;
      FILE *f1, *f2, *f3;
      do{
            cout <<"\n|-------------MENU--------------|" << endl;
		cout << " | 0) Finalizar programa         |" << endl;
		cout << " | 1) Cargar FINALES de la semana|" << endl;
		cout << " | 2) Cargar FINALES de Dia      |" << endl;
		cout << " | 3) Apareo                     |" << endl;
            cout << " | 4) Listar archivo/os          |" << endl;
            cout<<"   |-------------------------------|"<<endl;;
		cin >> operacion;
            switch (operacion){
            case 0:
                  system("cls");
                  cout<<"Gracias por utilizar el Programa"<<endl;
                  break;
            case 1:
                  cout<<"\tCARGAMOS FINALES DE LA SEMANA (ord por materia):"<<endl;
                  cout << " ___________________________" << endl;
                  f1 = fopen("FINALES.dat", "wb");
                  CargarFinales(f1);
                  fclose(f1);
                  break;

            case 2:
                  cout<<"\tCARGAMOS FINALES DEL DIA (ord por materia):"<<endl;
                  cout << " ___________________________" << endl;
                  f1 = fopen("FINALESdia.dat", "wb");
                  CargarFinales(f2);
                  fclose(f2);
                  break;
            case 3:
                  cout<<"\tAPAREO"<<endl;
                  cout << " ___________________________" << endl;
                  f1 = fopen("FINALES.dat", "rb");
                  f2 = fopen("FINALESdia.dat", "rb");
                  f3 = fopen("FINALESact.dat", "wb");
                  ApareoFinales(f1, f2, f3);
                  
                  fclose(f1);
                  fclose(f2);
                  fclose(f3);
                  break;
            case 4:  
               system("cls");
                  cout<<"\nQue archivo debe listar? : "<<endl;
                  cout<<"1) INSCRIPCIONES DE LA SEMANA"<<endl;
                  cout<<"2) INSCRIPCIONES DEl DIA"<<endl;
                  cout<<"3) ARCHIVO DEL APAREO"<<endl;
                  cout<<".... ";cin>>operacionFIle;

                  switch (operacionFIle){
                  case 1: 
                        f1= fopen("FINALES.dat", "rb");
                        ListarFinales(f1);
                        fclose(f1);
                        break;
                  case 2:
                        f2= fopen("FINALESdia.dat", "rb");
                        ListarFinales(f2);
                        fclose(f2);
                        break;
                  case 3:
                        f3= fopen("FINALESact.dat", "rb");
                        ListarFinales(f3);
                        fclose(f3);
                        fclose(f2);
                        fclose(f1);
                        break;
                  }
            break;

            default:
                  system("cls");
                  cout<<"ERROR OPERACION INVALIDA";
                  break;
            }
      }while (operacion !=0);
      return 0;
}
/***************************************************************************************************************************************************/
// ACT 91 VECTORES --> K1145
#include <iostream>
#include <string.h>
using namespace std;

struct Talu{
      int lejago, materia;
      char nombre[20];
};

void cargarVec(Talu Vecalu[], int &tope){
      int i=0;
      cout<<"\nDatos del alumno ";
      cout<<endl;
      cout<<"\nLegajo (0 para cortar): ";cin>>Vecalu[i].lejago;
      while (Vecalu[i].lejago !=0) {
            cout<<"\nCodigo de materia: ";cin>>Vecalu[i].materia;
            cout<<"\nNombre: ";cin>>Vecalu[i].nombre;
            i++;
      cout<<"\nDatos del alumno ";
      cout<<endl;
      cout<<"\nLegajo: ";cin>>Vecalu[i].lejago;
      };

      tope = i-1;
}
void OrdxMateria(Talu Vecalu[], int tope) {
      int pas =1;
      bool ordenado =false;
      Talu Ralu;
      while (!ordenado) {
            ordenado = true;

            for(int i=0; i<=tope -pas; i++){
                  if(Vecalu[i].materia > Vecalu[i+1].materia){
                        Ralu = Vecalu[i];
                        Vecalu[i] = Vecalu[i+1];
                        Vecalu[i+1] = Ralu;
                        ordenado = false;
                  }
            }
            pas++;
      }
      
}
void ApareoVec(Talu VecaluA[], int &tope1, Talu VecaluB[], int &tope2, Talu VecaluFinal[], int &tope3) {
      int j=0, k=0, i=0;
      while (j <= tope1 && k <= tope2) {
            if(VecaluA[j].materia <= VecaluB[k].materia) {
                  VecaluFinal[i] = VecaluA[j];
                  j++;
            }
            else{
                  VecaluFinal[i] = VecaluB[k];
                  k++;
            }
      };
      if(j > tope1){
            while (k <= tope2){
                  VecaluFinal[i] = VecaluB[k];
                  k++;
                  i++;
            }
      }
      else{
            while (j <= tope1) {
                  VecaluFinal[i] = VecaluA[j];
                  j++;
                  i++;
            }
      }
      tope3 = i -1;
}
void MostrarVec(Talu VecaluFinal[], int tope){
      for(int i=0; i <= tope; i++){
            cout<<VecaluFinal[i].materia<<"       "<<VecaluFinal[i].lejago<<"      "<<VecaluFinal[i].nombre<<endl;
      }
}
int main(){
      Talu VecFinal[100];
      Talu VecDIAFinal[100];
      Talu VecFinalACT[100];
      int tope1 =0, tope2=0,tope3=0;

      cout<<"\nIngreso de alumnos anotados hasta ayer: "<<endl;
      cargarVec(VecFinal, tope1);
      cout<<"\nIngreso de alumnos anotados hoy: "<<endl;
      cargarVec(VecDIAFinal, tope2);
      cout<<"\n-----------------------------------------"<<endl;
      cout<<"\nVECTORES ORDENADOS:"<<endl;
      OrdxMateria(VecFinal, tope1);
      OrdxMateria(VecDIAFinal, tope2);
      MostrarVec(VecFinal, tope1);
      cout<<"\n-----------------------------------------"<<endl;
      MostrarVec(VecDIAFinal, tope1);
      ApareoVec(VecFinal, tope1, VecDIAFinal, tope2,VecFinalACT, tope3);
      for(int i=0; i<= tope3; i++){
            cout<<VecFinalACT[i].lejago<<"       ";
            cout<<VecFinalACT[i].materia<<"       ";
            cout<<VecFinalACT[i].nombre<<"       "<<endl;
      }
      system("pause");
      return 0;
}
/***************************************************************************************************************************************************/
// ACT 92 --> K1145
#include <iostream>
#include <string.h>
using namespace std;

struct ArtLocal {
      int codLib, stockLib;
      char titulo[20];
      char genero[3];
};

struct ArtDepos{
      int codLib, stockLib;
};


//DEF FUNC
void GenerarArchivoLocal(){
      FILE *Flocal;
      ArtLocal Rlocal;

      Flocal = fopen("StockEnLocal.dat", "wb");
      cout<<"\nIngreso de datos del local: "<<endl;
      cout<<"\nIngrese el cod del Libro: ";cin>>Rlocal.codLib;

      while (Rlocal.codLib !=0) {
            cout<<"\nIngrese el titulo del libro: ";cin>>Rlocal.titulo;
            cout<<"\nIngrese stock en local: ";cin>>Rlocal.stockLib;
            cout<<"\nIngrese el genero del libro: ";cin>>Rlocal.genero;
      
            fwrite(&Rlocal, sizeof(Rlocal), 1, Flocal);

            cout<<"\nIngrese el cod del Libro: ";cin>>Rlocal.codLib;
      }
      fclose(Flocal);
}
void GenerarArchivoDeposito(){
      FILE *Fdeposito;
      ArtDepos Rdeposito;

      Fdeposito = fopen("StockEnDeposito.dat", "wb");
      cout<<"\nIngreso de datos del deposito: "<<endl;
      cout<<"\nIngrese el cod del Libro: ";cin>>Rdeposito.codLib;

      while (Rdeposito.codLib !=0) {
            cout<<"\nIngrese el stock en deposito: ";cin>>Rdeposito.stockLib;

            fwrite(&Rdeposito, sizeof(Rdeposito), 1, Fdeposito);
            cout<<"\nIngrese el cod del Libro: ";cin>>Rdeposito.codLib;
      }
      fclose(Fdeposito);
}

void MostrarArchLocal(){
      FILE *Flocal;
      ArtLocal Rlocal;

      Flocal = fopen("StockEnLocal.dat", "rb");
      if(Flocal == NULL){
            cout<<"\nNO SE LOGRO LEER EL ARCHVIO";
      }
      else{
            cout<<"\nListado de libros del Local: "<<endl;
            cout<<"\nCod Libro:    Titulo:   Stock:     Genero:  "<<endl;
            fread(&Rlocal, sizeof(Rlocal), 1 ,Flocal);
            while (!feof(Flocal)){
                  cout<<Rlocal.codLib<<"          "<<Rlocal.titulo<<"          "<<Rlocal.stockLib<<"          "<<Rlocal.genero<<endl;
            fread(&Rlocal, sizeof(Rlocal), 1 ,Flocal);
            }      
      }
      fclose(Flocal);
}
void MostrarArchDepos(){
      FILE *Fdeposito;
      ArtDepos Rdeposito;

      Fdeposito = fopen("StockEnDeposito.dat", "rb");
      if(Fdeposito == NULL){
            cout<<"\nNO SE LOGRO LEER EL ARCHVIO";
      }
      else{
            cout<<"\nListado de libros del Deposito: "<<endl;
            cout<<"\nCod Libro:       Stock: "<<endl;
            fread(&Rdeposito, sizeof(Rdeposito), 1 ,Fdeposito);
            while (!feof(Fdeposito)){
                  cout<<Rdeposito.codLib<<"                 "<<Rdeposito.stockLib<<endl;
            fread(&Rdeposito, sizeof(Rdeposito), 1 ,Fdeposito);
            }      
      }
      fclose(Fdeposito);
}

void RevisarStock(){
      ArtLocal Rlocal;
      FILE *Flocal;
      Flocal = fopen("StockEnLocal.dat", "rb");
      int i=0;

      ArtDepos Rdeposito;
      FILE *Fdeposito;
      Fdeposito = fopen("StockEnDeposito.dat", "rb");

      fread(&Rlocal, sizeof(Rlocal), 1 ,Flocal);
      fread(&Rdeposito, sizeof(Rdeposito), 1 ,Fdeposito);
      while (!feof(Flocal) && !feof(Fdeposito)) {

            if(Rlocal.codLib < Rdeposito.codLib){
                  cout<<"\nFalta en deposito cod: "<<Rlocal.codLib<<endl;
                  if(Rlocal.stockLib ==0){
                        cout<<"\nFalta en local cod: "<<Rlocal.codLib<<endl;
                  }
            fread(&Rlocal, sizeof(Rlocal), 1 ,Flocal);
            }
            else if(Rdeposito.codLib < Rlocal.codLib){
                  cout<<"\nFalta en local cod: "<<Rdeposito.codLib<<endl;
                  if(Rdeposito.stockLib ==0){
                        cout<<"\nFalta en el deposito cod: "<<Rdeposito.codLib<<endl;
                  }
            fread(&Rdeposito, sizeof(Rdeposito), 1 ,Fdeposito);
            }
            //Coinciden los Cod libro
            else{
                  if(Rlocal.stockLib ==0){
                        cout<<"\nFalta en local cod: "<<Rlocal.codLib<<endl;
                  }
                  if(Rdeposito.stockLib ==0){
                        cout<<"\nFalta en el deposito cod: "<<Rdeposito.codLib<<endl;
                  }
                  fread(&Rlocal, sizeof(Rlocal), 1 ,Flocal);
                  fread(&Rdeposito, sizeof(Rdeposito), 1 ,Fdeposito);
            }
            i++;
      };
            if(feof(Flocal)){
                  while (!feof(Fdeposito)) {
                        cout<<"\nFalta en local cod: "<<Rdeposito.codLib<<endl;
                        if(Rdeposito.stockLib ==0){
                              cout<<"\nFalta en deposito cod: "<<Rdeposito.codLib<<endl;
                        }
                        fread(&Rdeposito, sizeof(Rdeposito), 1, Fdeposito);
                        i++;
                  }  
            }
            else if(feof(Fdeposito)){
                  while (!feof(Flocal)) {
                        cout<<"\nFalta en deposito cod: "<<Rlocal.codLib<<endl;
                        if(Rlocal.stockLib ==0){
                              cout<<"\nFalta en local cod: "<<Rlocal.codLib<<endl;
                        }
                        fread(&Rlocal, sizeof(Rlocal), 1, Flocal);
                        i++;
                  }
            };
            fclose(Flocal);
            fclose(Fdeposito);
}
//MAIN FUNC
int main(){
      int operacion;
      do{
            cout <<"\n|-------------MENU--------------|" << endl;
		cout << " | 0) Finalizar programa         |" << endl;
		cout << " | 1) Generar archivo Local      |" << endl;
		cout << " | 2) Generar archivo Deposito   |" << endl;
		cout << " | 3) Ver archivo de Local       |" << endl;
            cout << " | 4) Ver archivo de Deposito    |" << endl;
		cout << " | 5) Procesar apareo            |" << endl;
            cout<<"   |-------------------------------|"<<endl;;
		cin >> operacion;
            switch (operacion)
            {
            case 0:
                  cout<<"Gracias por utilizar el Programa"<<endl;
                  break;
            case 1:
                  GenerarArchivoLocal();
                  break;
            case 2:
                  GenerarArchivoDeposito();
                  break;
            case 3:
                  MostrarArchLocal();
                  break;
            case 4:
                  MostrarArchDepos();
                  break;
            case 5:
                  RevisarStock();
                  break;
            default:
                  cout<<"ERROR OPERACION INVALIDA";
                  break;
            }
      }while (operacion !=0);

      system("pause");
      return 0;
}
/***************************************************************************************************************************************************/
// ACT 93 --> K1145
#include <iostream>
#include <string.h>
using namespace std;

struct Talumno {
      int legajo, Ingreso;
      char ApeNom[31], codOp;
      // Datos comentados:
      /*char Dom[21];
        int CodPost, Telf;
      */
};
//DEF FUNC
void ApareoArchivos(FILE *File1, FILE *File2, FILE *File3){
      Talumno Ralu;
      Talumno Rnov;

      fread(&Ralu , sizeof(Ralu), 1, File1);
      fread(&Rnov, sizeof(Rnov),1 , File2);
      while(!feof(File1) && !feof(File2)){
            if(Ralu.legajo < Rnov.legajo){ // es decir el alumno está en Alumnos y no en Novedades
                  fwrite(&Ralu, sizeof(Ralu),1, File3);
                  fread(&Ralu, sizeof(Ralu), 1, File1);
            }
            if(Rnov.legajo < Ralu.legajo){ // es decir el alumno está en Novedades y no en Alumnos
                  switch (Rnov.codOp) {
                  case 'A': case 'a':
                        fwrite(&Rnov, sizeof(Rnov),1, File3);
                        fread(&Rnov, sizeof(Rnov), 1, File2);
                        break;
                  case 'B': case 'b':
                        cout<<"ERROR - Baja Inexistente"<<endl;
                        fread(&Rnov, sizeof(Rnov), 1, File2);
                        break;
                  case 'M': case 'm':
                        cout<<"ERROR - Modificacion Inexistente"<<endl;
                        fread(&Rnov, sizeof(Rnov), 1, File2);
                        break;
                  }
            }
            if(Ralu.codOp == Rnov.legajo){ // es decir el alumno está en ambos archivos
                  switch (Rnov.codOp) {
                  case 'A': case 'a':
                        cout<<"AVISO: ALTA DUPLICADA!";
                        fwrite(&Ralu, sizeof(Ralu), 1, File3);
                        fread(&Ralu, sizeof(Ralu),1 , File1);
                        fread(&Rnov, sizeof(Rnov),1 , File2);
                        break;
                  case 'B': case 'b':
				//Al no copiar ningun registro, No estará en el nuevo archivo.
                        fread(&Rnov, sizeof(Rnov),1 , File2);
                        fread(&Ralu, sizeof(Ralu),1 , File1);
                        break;
                  case 'M': case 'm':
                        fwrite(&Rnov, sizeof(Rnov),1 , File3);
                        fread(&Ralu, sizeof(Ralu),1 , File1);
                        fread(&Rnov, sizeof(Rnov),1 , File2);
                        break;
                  }
            }
      }
      if(!feof(File1)){ //QUEDAN DATOS EN EL ARCHIVO 1 PERO NO EN ARCHIVO 2
            while (!feof(File1)) {
                  fwrite(&Ralu, sizeof(Ralu),1, File3);
                  fread(&Ralu, sizeof(Ralu), 1, File1);
            }
      }
      else{ //QUEDAN DATOS EN EL ARCHIVO2 PERO NO EN ARCHIVO 1
      while (!feof(File2)) {
            switch (Rnov.codOp) {
            case 'A': case 'a':
                  fwrite(&Rnov, sizeof(Rnov), 1, File3);
                  fread(&Rnov, sizeof(Rnov), 1, File2);
                  break;
            case 'B': case 'b':
                  cout<<"ERROR - Baja Inexistente"<<endl;
                  fread(&Rnov, sizeof(Rnov), 1, File2);
                  break;
            case 'M': case 'm':
                  cout<<"ERROR - Modificacion Inexistente"<<endl;
                  fread(&Rnov, sizeof(Rnov), 1, File2);
                  break;
            }
      }   
 }
      fclose(File1); fclose(File2); fclose(File3);
}
void BuscInsert(Talumno VecAlu[], int &tope, Talumno RaluBusc){
      int pos =0;
      while ((pos <= tope) && (VecAlu[pos].legajo <= RaluBusc.legajo)) {
            pos ++;
      }
      if(pos <= tope){
            for(int j=tope; j>=pos; j--){
                  VecAlu[j+1] = VecAlu[j];
            }      
      }
      VecAlu[pos] = RaluBusc;
      tope++;
}
void CargVec(FILE *File, Talumno Vecalu[], int &tope){
      Talumno Raux;
      tope = -1;
      while (fread(&Raux, sizeof(Raux),1, File)){
            BuscInsert(Vecalu, tope, Raux);
      }
      fclose(File);
}
void GenerarArchAlu(){
      FILE *Falu = fopen("Alumnnos.dat", "w+b");
      Talumno Ralu;
      cout<<"\nIngrese el legajo del alumno (o para cortar): ";cin>>Ralu.legajo;
      while(Ralu.legajo !=0){
            cout<<"\nIngrese el Apellido y Nombre del alumno: ";cin>>Ralu.ApeNom;
            /*
            cout<<"\nIngrese el Domicilio: ";cin>>Ralu.Dom;
            cout<<"\nIngrese el codigo postal: ";cin>>Ralu.CodPost;
            cout<<"\nIngrese el telefono: ";cin>>Ralu.Telf; */
            cout<<"\nIngrese el anio de ingreso: ";cin>>Ralu.Ingreso;
            fwrite(&Ralu, sizeof(Ralu), 1, Falu);
      cout<<"\nIngrese el legajo del alumno (o para cortar): ";cin>>Ralu.legajo;
      }
      fclose(Falu);
}
void GenerarArchivoNov(){
      FILE *Fnov = fopen("Novedades.dat", "w+b");
      Talumno Rnov;
      cout<<"\nIngrese el legajo del alumno (o para cortar): ";cin>>Rnov.legajo;
      while(Rnov.legajo !=0){
            cout<<"\nIngrese el Apellido y Nombre del alumno: ";cin>>Rnov.ApeNom;
            /*
            cout<<"\nIngrese el Domicilio: ";cin>>Ralu.Dom;
            cout<<"\nIngrese el codigo postal: ";cin>>Ralu.CodPost;
            cout<<"\nIngrese el telefono: ";cin>>Ralu.Telf; */
            cout<<"\nIngrese el anio de ingreso: ";cin>>Rnov.Ingreso;
            cout<<"\nIngrese el codigo de operacion: ";cin>>Rnov.codOp;
            //cin.ignore(numeric_limits<int>::max(), '\n');

            fwrite(&Rnov, sizeof(Rnov), 1, Fnov);
      cout<<"\nIngrese el legajo del alumno (o para cortar): ";cin>>Rnov.legajo;
      }
      fclose(Fnov);
}
void MostrarArchivoAlu(){
      FILE *File = fopen("Alumnos.dat", "rb");
      Talumno Ralu;
      if(File == NULL){
            cout<<"ERROR AL LEER EL ARCHVIO" <<endl;
            exit(1);
      }
      else{
            fread(&Ralu, sizeof(Ralu),1 , File);
            cout<<"\n |Legajo| " << "Apellido y Nombre| " << "    AnioIngreso|"<<endl; 
            while (!feof(File)) {
                  cout<< " " << Ralu.legajo << "       " << Ralu.ApeNom << "       " << Ralu.Ingreso<<endl;
            fread(&Ralu, sizeof(Ralu),1 , File);
            }
            fclose(File);
      }
}
void MostrarArchivoNov(){
      FILE *File = fopen("Novedades.dat", "rb");
      Talumno Rnov;
      if(File == NULL){
            cout<<"ERROR AL LEER EL ARCHVIO" <<endl;
            exit(1);
      }
      else{
            fread(&Rnov, sizeof(Rnov),1 , File);
            cout<<"\n |Legajo| " << "Apellido y Nombre| " << "    AnioIngreso|" << "    CodOp|"<<endl; 
            while (!feof(File)) {
                  cout<< " " << Rnov.legajo << "       " << Rnov.ApeNom << "       " << Rnov.Ingreso << "       " << Rnov.codOp<<endl;
            fread(&Rnov, sizeof(Rnov),1 , File);
            }
            fclose(File);
      }
}
void MostrarArchivoAct(){
      FILE *File = fopen("AlumnosAcutalizados.dat", "rb");
      Talumno Registro;
      if(File == NULL){
            cout<<"ERROR AL LEER EL ARCHVIO" <<endl;
            exit(1);
      }
      else{
            fread(&Registro, sizeof(Registro),1 , File);
            cout<<"\n |Legajo| " << "Apellido y Nombre| " << "    AnioIngreso|"<<endl; 
            while (!feof(File)) {
                  cout<< " " << Registro.legajo << "       " << Registro.ApeNom << "       " << Registro.Ingreso <<endl;
            fread(&Registro, sizeof(Registro),1 , File);
            }
            fclose(File);
      }
}
void EjecutarEjercicio(){
      FILE *Falu = fopen("Alumnos.dat", "rb");
      FILE *Fnov = fopen("Novedades.dat", "rb");
      FILE *Factualizado = fopen("AlumnosAcutalizados.dat", "w+b");
      ApareoArchivos(Falu, Fnov, Factualizado);
      cout<<"\nSe genero el nuevo archivo"<<endl;
}
//MAIN FUNC
int main(){
      int operacion;
      do{
            cout <<"\n |--------------MENU--------------|" << endl;
		cout << " | 0) Finalizar programa          |" << endl;
		cout << " | 1) Generar archivo Alumnos     |" << endl;
		cout << " | 2) Generar archivo Novedades   |" << endl;
		cout << " | 3) Imprimir archivo Alumnos    |" << endl;
		cout << " | 4) Imprimir archivo Novedades  |" << endl;
		cout << " | 5) Ejecutar Apareo             |" << endl;
		cout << " | 6)Imprimir archivo Actualizado |" << endl;
            cout<<" |--------------------------------|"<<endl;
		cin >> operacion;

            switch (operacion)
            {
            case 0:
                  cout<<"Gracias por utilizar el Programa"<<endl;
                  break;
            case 1: 
            GenerarArchAlu();
                  break;
            case 2: 
            GenerarArchivoNov();
                  break;
            case 3: 
            MostrarArchivoAlu();
                  break;
            case 4: 
            MostrarArchivoNov();
                  break;
            case 5: 
            EjecutarEjercicio();
                  break;
            case 6: 
            MostrarArchivoAct();
                  break;
            default:
                  cout<<"ERROR OPERACION INVALIDA";
                  break;
            }
      }while (operacion !=0);

      system("pause");
      return 0;
}
/***************************************************************************************************************************************************/
// ACT 94 y 94´ --> K1145
#include <iostream>
#include <string.h>
using namespace std;

struct Tseries {
      int IdSeries, episodio, temporada;
      long int descargas;

};
//PROTOTIPOS DE FUNCS
void GenerarArchivoSerie();
void CorteyControl();

//MAIN FUNC
int main(){
      int operacion;
      do{
            cout <<"\n |=============== MENU ==================|" << endl;
		cout << " | 0) Finalizar programa          |" << endl;
		cout << " | 1) Generar archivo             |" << endl;
		cout << " | 2) Corte y Control             |" << endl;
            cout<<" |=======================================|"<<endl;
            cout<<"\nIngrese una operacion: ";cin >> operacion;

            switch (operacion)
            {
            case 0:
                  cout<<"Gracias por utilizar el Programa"<<endl;
                  break;
            case 1: 
                  GenerarArchivoSerie();
                  break;
            case 2: 
                  CorteyControl();
                  break;
            default:
                  cout<<"ERROR OPERACION INVALIDA";
                  break;
            }
      }while (operacion !=0);
      system("pause");
      return 0;
}
//DEF FUNC
void GenerarArchivoSerie(){
      FILE *File = fopen("Episodios.dat", "w+b");
      Tseries Rseries;

      cout<<"\nIngrese de forma ascendente el ID de la serie (0 para cortar): ";cin>>Rseries.IdSeries;
      while (Rseries.IdSeries !=0) {
            cout<<"\nIngrese la temporada: ";cin>>Rseries.temporada;
            cout<<"\nIngrese el episodio: ";cin>>Rseries.episodio;
            cout<<"\nIngrese la cantidad de descargas: ";cin>>Rseries.descargas;

            fwrite(&Rseries, sizeof(Rseries), 1, File);
            cout<<"\nIngrese de forma ascendente el ID de la serie (0 para cortar): ";cin>>Rseries.IdSeries;
      }
      fclose(File);
}
void CorteyControl(){
      Tseries Ractual;
      int IdAnterior,TempAnterior, cantEpisodios=0, totalSeries=0;
      long int cantDescargas=0, totalDescargas=0;
      FILE *File =fopen("Episodios.dat", "rb+");

      fread(&Ractual, sizeof(Ractual), 1, File);
      while(!feof(File)){
            IdAnterior = Ractual.IdSeries; //inicializamos nuevo anterior
            cantEpisodios =0;
            cantDescargas =0;

            cout<<"\n";
            
            cout<<"==============================================="<<endl;
            cout<<"\nListado de Descargas de Serie "<<Ractual.IdSeries<<" Temporada "<<Ractual.temporada<<" :"<<endl;
            cout<<"TEMPORADA   N.episodio    CANT.descargas"<<endl;

            while((!feof(File)) && (IdAnterior == Ractual.IdSeries)){
            TempAnterior = Ractual.temporada;
            
                  while((!feof(File)) && (IdAnterior == Ractual.IdSeries) &&(TempAnterior == Ractual.temporada)){

                  cout<< "    " << Ractual.temporada<< "             " <<Ractual.episodio<< "             " << Ractual.descargas<<endl;
                  cantEpisodios +=1;
                  cantDescargas += Ractual.descargas;
                  fread(&Ractual, sizeof(Ractual), 1, File);
                  }
            }
            cout<<"==============================================="<<endl;
            cout<<"\tCant. de episodios de la serie "<<Ractual.IdSeries<<" : "<<cantEpisodios<<endl;
            cout<<"\tCant. de descargas de la serie "<<Ractual.IdSeries<<" : "<<cantDescargas<<endl;
      
            totalDescargas += cantDescargas;
            totalSeries += 1;
      }
      cout<<"==============================================="<<endl;
      cout<<"\nCant. de total de series: "<<totalSeries<<endl;
      cout<<"\nCant. de total de descargas: "<<totalDescargas<<endl;
}
/********************************************************************************************/
// ACT 95 --> K1145
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct Tproductos {
      int CodProd, Cantvend;
      char Desc[20];
      float TotFact, PU;
};

//DEF FUNC
void GenerarArchivoProd(){
      FILE *f = fopen("Productos.dat", "w+b");
      Tproductos Rproductos;

      cout<<"\nIngrese el codigo de producto (0 para cortar): ";cin>>Rproductos.CodProd;
      while (Rproductos.CodProd !=0) {
            cout<<"\nIngrese descripcion del producto: ";cin>>Rproductos.Desc;
            cout<<"\nIngrese cantidad vendida: ";cin>>Rproductos.Cantvend;
            cout<<"\nIngrese Precio Unitario: ";cin>>Rproductos.PU;

      fwrite(&Rproductos, sizeof(Rproductos), 1, f);
      cout<<"\nIngrese el codigo de producto (0 para cortar): ";cin>>Rproductos.CodProd;
      }
      fclose(f);
}
void LeerArchivoProd(){
      FILE *f = fopen("Productos.dat", "rb");
      Tproductos Rprod;

      fread(&Rprod, sizeof(Rprod),1,f);
      cout<<"Codigo       Descrip         CantVend      PU"<<endl;
      while (!feof(f)){
            cout<<" "<<Rprod.CodProd<<"       "<<Rprod.Desc<<"       "<<Rprod.Cantvend<<"       "<<Rprod.PU<<endl;
            fread(&Rprod, sizeof(Rprod),1,f);
      }
      fclose(f);
}
int BuscVec(Tproductos VecProd[] ,int tope, int CodP, int &pos){
      pos=0;
      while ((pos<=tope) && (VecProd[pos].CodProd != CodP)){
            pos ++;
      }
      if(pos > tope){
            pos = -1;
      }
      return pos;
}
void OrdVec(Tproductos VecProd[], int tope){
      Tproductos aux;
      for(int pas=0; pas <=tope; pas++){
            for(int j=0; j<=tope-pas; j++){
                  if(VecProd[j].CodProd > VecProd[j+1].CodProd){
                        aux = VecProd[j];
                        VecProd[j] = VecProd[j+1];
                        VecProd[j+1] = aux;
                  }
            }
      }
}
//MAIN FUNC
int main(){
      int i=0, operacion, sumaVend=0, Codant, a=0, b=0, c=0,pos;
      Tproductos VecProd[5000];
      Tproductos Rprod;
      float totalProd=0;
      FILE *f;
      do{
            cout <<"\n=============== MENU ==================" << endl;
		cout << " | 0) Finalizar programa          " << endl;
		cout << " | 1) Generar archivo productos   " << endl;
		cout << " | 2) Mostrar archivo productos   " << endl;
	      cout << " | 3) Promedio de Productos y Ver productos > $1000" << endl;
            cout<<"======================================="<<endl;
            cout<<"\nIngrese una operacion: ";cin >> operacion;

            switch (operacion)
            {
            case 0:
                  cout<<"Gracias por utilizar el Programa"<<endl;
                  break;
            case 1: 
                  GenerarArchivoProd();
                  break;
            case 2: 
                  LeerArchivoProd();
                  break;
            case 3: 
                  f= fopen("Productos.dat", "rb");
                  fread(&Rprod, sizeof(Rprod),1 ,f);
                  while (!feof(f)){
                        Codant = Rprod.CodProd;
                        if(Rprod.PU >1000){
                              i++;
                              VecProd[i].CodProd = Rprod.CodProd;
                              strcpy(VecProd[i].Desc, Rprod.Desc);
                              VecProd[i].Cantvend = Rprod.Cantvend;
                              VecProd[i].PU = Rprod.PU;
                        }
                        while (!feof(f) && Rprod.CodProd == Codant){
                              sumaVend += Rprod.Cantvend;
                              a++;
                              Rprod.TotFact += Rprod.PU*Rprod.Cantvend;
                              totalProd += Rprod.TotFact;
                              if(Rprod.PU > 3000){
                                    b++;
                              }
                              fread(&Rprod, sizeof(Rprod),1,f);
                        }
                        cout<<"\tDATOS DEL PRODUCTO "<<endl;
                        cout<<"\nPromedio de cantVentas: "<<(sumaVend / (a*1.0))<<endl;
                        cout<<"\nTotal Facturado del producto: "<<totalProd<<endl;
                        if(totalProd>5000){
                              c++;
                        }
                        cout<<"\nCantidad de Ventas > a $3000: "<<b;
                  }
                  cout<<"\nCantidad de prod con facturado > $5000: "<<c<<endl;
                  fclose(f);
                  cout<<"-----------------------------------------------------------------"<<endl;
                  cout<<"-----------------------------------------------------------------"<<endl;

                  cout<<"\tVector con prod > $1000"<<endl;
                  OrdVec(VecProd, i);
                  for(int j=0; j<=i;j++){
                        
                  }
                  cout<<"\nIngrese cod Prod (0 para cortar): ";cin>>Rprod.CodProd;
                  while (Rprod.CodProd != 0){
                        BuscVec(VecProd, i, Rprod.CodProd, pos);
                        if(pos != -1){
                              cout<<VecProd[pos].Desc<<endl;
                              cout<<VecProd[pos].PU<<endl;
                        }     
                  }
            break;
            default:
                  cout<<"ERROR OPERACION INVALIDA";
                  break;
            }
      }while (operacion !=0);
      return 0;
}

