#include<iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Talumnos{
      int legajo;
      int antiguedad;
      char NomyAP[30];
};
struct Tmaterias{
      int CodM;
      int capacidad;
      char Nom[30];
};
struct Tinscripciones{
      int legajo;
      int CodM;
};
struct Nodo{
      Talumnos Info;
      Nodo *sig;
};
struct Tmateriam{
      int CodM; 
      int CapaciIni; 
      int CapaciFin; 
      int SumAnti;
      char Nom[20];
};

//Generacion y Lectura de archivos
void GenerarArchivoAlumnos(){
    Talumnos Ralu;
    FILE *alumnos = fopen("TPIndiv-K1145-PaloMarcos-Alumnos.dat","wb");
    cout<<"\nIngresar legajo alumno (0 para cortar):" ;cin>>Ralu.legajo;

    while(Ralu.legajo!=0){
        cout<<"\nIngrese Nombre: " ;cin>>Ralu.NomyAP;
        cout<<"\nIngrese antiguedad: " ;cin>>Ralu.antiguedad;
        fwrite(&Ralu,sizeof(Ralu),1,alumnos);

        cout<<"\nIngresar legajo alumno (0 para cortar): ";cin>>Ralu.legajo;
    }
    fclose(alumnos);
}
void LeerArchivoAlumnos(){
    Talumnos Ralu;
    FILE *alumnos = fopen("TPIndiv-K1145-PaloMarcos-Alumnos.dat","rb");
    if (alumnos==NULL){
        cout<<"\nError al utilizar el archivo"<<endl;
    }
    cout << "\nListado de alumnos" << endl;
	cout << "Legajo: " <<" Nombre: " << " Antiguedad:" << endl;
	fread(&Ralu,sizeof(Ralu),1,alumnos);
    while(!feof(alumnos)){
        cout <<"  " << Ralu.legajo << "      " << Ralu.NomyAP << "       " << Ralu.antiguedad << endl;
        fread(&Ralu,sizeof(Ralu),1,alumnos);
    }
    fclose(alumnos);
}

void GenerarArchivoMaterias(){
    Tmaterias Rmat;
    FILE *materias = fopen("TPIndiv-K1145-PaloMarcos-Materias.dat","wb");
    cout<<"\nIngresar codigo de materia (0 para cortar):" ;cin>>Rmat.CodM;
    while(Rmat.CodM!=0){

        cout<<"\nIngrese nombre materia: "; cin>>Rmat.Nom;
        cout<<"\nIngrese capacidad disponible: " ;cin>>Rmat.capacidad;

        fwrite(&Rmat,sizeof(Rmat),1,materias);
        cout<<"\nIngresar codigo de materia (0 para cortar): ";cin>>Rmat.CodM;
    }
    fclose(materias);
}
void LeerArchivoMaterias(){
    Tmaterias Rmat;
    FILE *materias = fopen("TPIndiv-K1145-PaloMarcos-Materias.dat","rb");
    if (materias==NULL){
        cout<<"\nError al utilizar el archivo"<<endl;
    }
    cout << "Listado de Materias" << endl;
	cout << "Cod: " <<" Nombre: " <<"Capacidad:" << endl;
	fread(&Rmat,sizeof(Rmat),1,materias);
    while(!feof(materias)){
        cout <<" " << Rmat.CodM << "     " << Rmat.Nom << "      " << Rmat.capacidad <<endl;
        fread(&Rmat,sizeof(Rmat),1,materias);
    }
    fclose(materias);
}
void GenerarArchivoInscripciones(){
    Tinscripciones Rins;
    FILE *inscripciones = fopen("TPIndiv-K1145-PaloMarcos-Inscripciones.dat","wb");
    cout<<"\nIngresar legajo (0 para cortar): ";cin>>Rins.legajo;
    while(Rins.legajo!=0){

        cout<<"\nIngrese codigo de materia: ";cin>>Rins.CodM;

        fwrite(&Rins,sizeof(Rins),1,inscripciones);
        cout<<"\nIngresar legajo (0 para cortar):" ;cin>>Rins.legajo;
    }
    fclose(inscripciones);
}
void LeerArchivoInscripciones(){
    Tinscripciones Rins;
    FILE *inscripciones = fopen("TPIndiv-K1145-PaloMarcos-Inscripciones.dat","rb");
    if (inscripciones == NULL){
        cout<<"\nError al utilizar el archivo"<<endl;
    }
    cout << "\tListado de Inscripciones" << endl;
	cout << "Legajo: " <<" Cod:" << endl;
	fread(&Rins,sizeof(Rins),1,inscripciones);
    while(!feof(inscripciones)){
        cout <<"  " << Rins.legajo << "      " << Rins.CodM <<endl;
        fread(&Rins,sizeof(Rins),1,inscripciones);
    }
    fclose(inscripciones);
}

/************************************************************************************************/ 
void InsertarOrdenado(Nodo *&lista, Talumnos Ralu){
      Nodo *nuevo = new Nodo();

      nuevo->Info.antiguedad = Ralu.antiguedad;
      nuevo->Info.legajo = Ralu.legajo;
      strcpy(nuevo->Info.NomyAP, Ralu.NomyAP);

      if((lista == NULL) || (strcmp(nuevo->Info.NomyAP,lista->Info.NomyAP))<0){
            nuevo->sig = lista;
            lista = nuevo;
      }else{
            Nodo *aux1 = lista;
            Nodo *aux2;
            while((aux1 != NULL) && (strcmp(nuevo->Info.NomyAP, aux1->Info.NomyAP))>0){
                  aux2 = aux1;
                  aux1 = aux1->sig;
            }
            aux2->sig= nuevo;
            nuevo->sig = aux1;
      }
}
void CargarMatVec(Tmateriam VecMat[], int &tope2){
      tope2 = 0;
      Tmaterias Rmat;
      FILE *materias=fopen("TPIndiv-K1145-PaloMarcos-Materias.dat", "rb");

      if(materias == NULL){
            cout<<"ERROR al usar archivo"<<endl;
      }
      fread(&Rmat, sizeof(Rmat), 1, materias);
      while (!feof(materias)) {

            VecMat[tope2].CodM = Rmat.CodM;
            strcpy(VecMat[tope2].Nom , Rmat.Nom);
            VecMat[tope2].CapaciIni= Rmat.capacidad;
            VecMat[tope2].CapaciFin = VecMat[tope2].CapaciIni;
            VecMat[tope2].SumAnti = 0;
            tope2 ++;

            fread(&Rmat, sizeof(Rmat), 1, materias);
      }
      fclose(materias);
}
void CargarVecAlu(Talumnos VecAlu[], int &tope1){
    tope1 = 0;
    Talumnos Ralu;
    FILE *alumnos = fopen("TPIndiv-K1145-PaloMarcos-Alumnos.dat","rb");
      if (alumnos==NULL){
            cout<<"\nArchivo inexistente"<<endl;    
      }
      fread(&Ralu, sizeof(Ralu), 1, alumnos);
      while(!feof(alumnos)){

            VecAlu[tope1].antiguedad = Ralu.antiguedad;
            VecAlu[tope1].legajo = Ralu.legajo;
            strcpy(VecAlu[tope1].NomyAP, Ralu.NomyAP);
            tope1++;

            fread(&Ralu, sizeof(Ralu), 1, alumnos);
    }
    fclose(alumnos);
} 
int BusqAlumno(Talumnos VecAlu[], int Legajo, int tope1, int&pos){
      pos =0;
      while((pos <= tope1) && (VecAlu[pos].legajo != Legajo)){
            pos++;
      }
      if(pos > tope1){
            pos = -1;
      }
      return pos;
}
int BusqMat(Tmateriam VecMat[], int CodMat, int tope2, int&pos){
      pos =0;
      while((pos <= tope2) && (VecMat[pos].CodM != CodMat)){
            pos++;
      }
      if(pos > tope2){
            pos = -1;
      }
      return pos;
}
void AnalizarInscripciones(Nodo *&lista, Tmateriam VecMat[], Talumnos VecAlu[], int &tope1, int & tope2){
      Tinscripciones Rinscripciones;
      FILE *inscripciones = fopen("TPIndiv-K1145-PaloMarcos-Inscripciones.dat", "rb");
      int CapacidadFinal, PosMat, PosAlu;
      Talumnos RaluAux;

      CargarVecAlu(VecAlu, tope1);
      CargarMatVec(VecMat, tope2);

      fread(&Rinscripciones, sizeof(Rinscripciones), 1, inscripciones);
      while (!feof(inscripciones)){

            PosAlu = BusqAlumno(VecAlu, Rinscripciones.legajo, tope1, PosAlu);
            PosMat = BusqMat(VecMat, Rinscripciones.CodM, tope2, PosMat);

            if((PosAlu != -1) && (PosMat != -1)){
                  
                  CapacidadFinal = VecMat[PosMat].CapaciFin;
                  if((CapacidadFinal == VecMat[PosMat].CapaciIni) || (CapacidadFinal >0)){
                        VecMat[PosMat].SumAnti = VecMat[PosMat].SumAnti + VecAlu[PosAlu].antiguedad;
                        VecMat[PosMat].CapaciFin = VecMat[PosMat].CapaciIni -1; 
                  }
                  else if(CapacidadFinal == 0){
                        RaluAux = VecAlu[PosAlu];
                        InsertarOrdenado(lista, RaluAux);
                  }

            }
            fread(&Rinscripciones, sizeof(Rinscripciones), 1, inscripciones);
      }
      fclose(inscripciones);
}
/************************************************************************************************/ 
void MostrarMateriasSinAlumnos(Tmateriam VecMat[], int tope2){
      int MatSinAlu=0;
      for(int i=0; i<= tope2-1; i++){
            if(VecMat[i].CapaciIni == VecMat[i].CapaciFin){
                  MatSinAlu ++;
            }
      }
    cout << "Cantidad materias sin alumnos: " << MatSinAlu << endl;    
}
void PromedioMateriaEdad(Tmateriam VecMat[], int tope2){
      float Promedio=0;
      cout<<"Nombre: "<<"   "<<"Promedio:"<<endl;
      for(int j=0; j<= tope2-1; j++){
            if (VecMat[j].CapaciIni != VecMat[j].CapaciFin){
                  Promedio=float(VecMat[j].SumAnti) / (VecMat[j].CapaciIni - VecMat[j].CapaciFin);
                  cout<<"   "<< VecMat[j].Nom <<"           "<< Promedio<<endl;
            }     
      }
}
void EliminarNodo(Nodo *lista, Talumnos &info){
      Nodo *aux = lista;
      info = aux->Info;
      lista = lista->sig;
      delete aux;
} 
/****************************************************/ 
//Funcion Main
int main(){
      Nodo* lista = NULL;
    Tmateriam VecMat[40];
    Talumnos VecAlu[999], Raluaux;
    int opc, Tope1, Tope2;

      cout << "\tElegir opcion deseada" << endl;
      cout<<"==========================================="<<endl;
      cout << "1 -Generar el Archivo de Alumnos" << endl;
      cout << "2 -Leer el Archivo de Alumnos" << endl;
      cout << "3 -Generar el Archivo Materias" << endl;
      cout << "4 -Leer el Archivo Materias" << endl;
      cout << "5 -Generar el Archivo Inscripciones" << endl;
      cout << "6 -Leer el Archivo Inscripciones" << endl;
      cout << "7 -Analizar las inscripciones" << endl;
      cout << "8 -Mostrar cant de materias sin alumnos" << endl;
      cout << "9 -Promedio antiguedad de inscriptos por materia" << endl;
      cout << "10 -Alumnos no inscriptos por exceder capacidad" << endl;
      cout << "11 -Salir" << endl;
      cout<<"==========================================="<<endl;

      cin >> opc;

      while(opc!=11){
      switch(opc){
            case 1: 
                  GenerarArchivoAlumnos();
            break;
        
            case 2: 
                  LeerArchivoAlumnos();
            break;
        
            case 3: 
                  GenerarArchivoMaterias();
            break;
        
            case 4: 
                  LeerArchivoMaterias();
            break;
        
            case 5: 
                  GenerarArchivoInscripciones();
            break;
        
            case 6: 
                  LeerArchivoInscripciones();
            break;
        
            case 7: 
                  AnalizarInscripciones(lista, VecMat, VecAlu, Tope1, Tope2);
            break;
        
            case 8: 
                  MostrarMateriasSinAlumnos(VecMat, Tope2);
            break;
        
            case 9: 
                  PromedioMateriaEdad(VecMat, Tope2);
            break;
        
            case 10:    
                  cout << "Nombre " << " Legajo" << endl;
                  while(lista != NULL){
                        EliminarNodo(lista, Raluaux);
                        cout << "  " <<Raluaux.NomyAP <<"      " << Raluaux.legajo << endl;
                        lista = lista -> sig;
                  }   
              break;
            default: 
                  cout <<"ERROR! La opcion seleccionada es invalida"<<endl;
            break;
      }      
      cout << "\tElegir opcion deseada" << endl;
      cout<<"==========================================="<<endl;
      cout << "1 -Generar el Archivo de Alumnos" << endl;
      cout << "2 -Leer el Archivo de Alumnos" << endl;
      cout << "3 -Generar el Archivo Materias" << endl;
      cout << "4 -Leer el Archivo Materias" << endl;
      cout << "5 -Generar el Archivo Inscripciones" << endl;
      cout << "6 -Leer el Archivo Inscripciones" << endl;
      cout << "7 -Analizar las inscripciones" << endl;
      cout << "8 -Mostrar cant de materias sin alumnos" << endl;
      cout << "9 -Promedio antiguedad de inscriptos por materia" << endl;
      cout << "10 -Alumnos no inscriptos por exceder capacidad" << endl;
      cout << "11 -Salir" << endl;
      cout<<"==========================================="<<endl;
      
      cin >> opc;
    }
    cout<<"Muchas gracias por utilizar el programa"<<endl;

    return 0;
}
    