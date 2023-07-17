// ACT 40 --> K1145
#include <iostream>
using namespace std;
//DEF DE FUNCS
void MostrarTabla(int Tabla, int &sumat){
      int valor, res;
      sumat =0;
      cout<<"\nTabla del "<< Tabla<<endl;
      for (valor= 1; valor <=10; valor++){
            res = Tabla*valor;
            cout<< Tabla << " x "<< valor<<" = "<<res<<endl;
            sumat += res;
      }
}
//FUNC MAIN
int main(){
      int n =5, sumat, Tabla;
      for(Tabla=1; Tabla<=n;Tabla++){
      MostrarTabla(Tabla, sumat);
      cout<< "\nLa sumatoria de los valores de la tabla del "<< Tabla << " = "<<sumat<<endl;
      cout<<" "<<endl;
      }
      return 0;
}
/*************************************************************************/
// ACT 41 --> K1145
#include <iostream>
#include<string.h>
using namespace std;

//DEF DE FUNCS
void Promediovoid(float edades, float cantAlu, float &Promedio);
void MayorEdad(int &Maxedad, int edad, string &MAXnom, string &MAXape, string nom, string ape);

void Promediovoid(float edades, float cantAlu, float &Promedio){
      Promedio = edades/cantAlu;
}
void MayorEdad(int &Maxedad, int edad, string &MAXnom, string &MAXape, string nom, string ape){
      Maxedad = 0;
      if (edad > Maxedad){
            Maxedad = edad;
            MAXnom = nom;
            MAXape = ape;
      }
}
//FUNC MAIN
int main(){
      int CantCurso=0, Sumacurso=0, CantTotal=0, SumaTotal=0, curso, edad, n, Maxedad=0;
      string nom, ape, MAXnom, MAXape;
      float PromCurso, PromTotal;

      cout<<"\nIngrese cantidad de cursos: ";cin>>n;
      for(curso=1; curso<=n;curso++){
            cout<<"\nIngrese el nombre del alumno o (fin para terminar): ";cin>>nom;
            while (nom != "fin"){
                  cout<<"\nIngrese el apellido del alumnno: ";cin>>ape;
                  cout<<"\nIngrese la edad del alumno: ";cin>>edad;
                  CantCurso +=1;
                  Sumacurso += edad;

                  cout<<"\nIngrese el nombre del alumno o (fin para terminar): ";cin>>nom;
            }
            CantTotal= CantTotal + CantCurso;
            SumaTotal = SumaTotal + Sumacurso;
            MayorEdad(Maxedad, edad, MAXnom, MAXape, nom, ape);
            cout<<"\nAlumno de mayor edad: "<<MAXnom<<" "<<MAXape<<endl;

            Promediovoid(Sumacurso, CantCurso, PromCurso);
            cout<<"\nEl promedio de las edades del curso es = "<<(PromCurso)<<endl;

      }
      Promediovoid(SumaTotal, CantTotal, PromTotal);
      cout<<"\nEl promedio de las edades totales es = "<<(PromTotal)<<endl;
      return 0;
}
/*************************************************************************/
// ACT 42 --> K1145
#include <iostream>
#include<string.h>
using namespace std;

//DEF DE FUNCS
void SumarPunt(int puntos, int &resultado);
float CalcPunt(string &codigo, int &partresu);

void SumarPunt(int puntos, int &resultado){
      resultado += puntos;
}
float CalcPunt(string &partresu){
      int puntos;
      if (partresu == "G"){
            puntos = 3;
      }
      if (partresu == "E"){
            puntos = 2;
      }
      if(partresu == "P"){
            puntos = 0;
      }
      return puntos;
}

//FUNC MAIN
int main(){
      int resultado, MaxResult=0, cantEquipos=0, cantPartidos =1, puntos=0;
      string nom, WinNom, partresu;

      cout<<"\nIngrese la cantidad de equipos: ";cin>>cantEquipos;

      for(int i=1; i<=cantEquipos;i++){
            resultado=0;
            cout<<"\nIngrese el nombre del equipo: ";cin>> nom;

            for(cantPartidos=1;cantPartidos<=(cantEquipos-1);cantPartidos++){
                  cout<<"\nIngrese el resultado del partido: (G = ganado / E = empatado / P = perdido)"<<endl;
                  cin>>partresu;
                  puntos = CalcPunt(partresu);
                  SumarPunt(puntos,resultado);
            }
            if((i==1) || (resultado>MaxResult)){
                  MaxResult = resultado;
                  WinNom = nom;
            }
            cout<<"\nEl equipo "<< nom <<" totalizo: "<<resultado<<" pts"<<endl;
      }
      cout<<"\nEl ganador del torneo es: "<< WinNom <<" con "<<MaxResult<<" puntos"<<endl;
      return 0;
}
/*************************************************************************/