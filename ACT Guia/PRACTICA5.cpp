// ACT 50 --> K1145
#include <iostream>
#include<string.h>
using namespace std;

//DEF DE FUNCS
float Prom(int nAlumnos, int Edad, float &Promedio){
      Promedio +=Edad;
      return Promedio;
}

//FUNC MAIN
int main(){
      int nAlumnos, VecAlu[70], MayorEdad=0, Edad, edadAlu;
      float Promedio =0;
      
      cout<<"\nIngrese la cantidad alumnos: ";cin>>nAlumnos;
      for (edadAlu=0; edadAlu <nAlumnos; edadAlu++){

            cout<<"\nIngrese la edad del alumno: ";cin>>VecAlu[edadAlu];
            Edad = VecAlu[edadAlu];

            Prom(nAlumnos,Edad, Promedio);
            if(VecAlu[edadAlu] > Promedio){
                  MayorEdad++;            
            }
      }
      cout<<"\nPromedio de edad = "<<(Promedio/nAlumnos)<<endl;
      cout<<"\nCantidad de alumnos que sobrepasaron el promedio = "<<MayorEdad<<endl;
      return 0;
}
/************************************************************************/
// ACT 51 --> K1145
#include <iostream>
#include<string.h>
using namespace std;

//DEF DE FUNCS

//FUNC MAIN
int main(){

      return 0;
}
/************************************************************************/