// ACT 31 --> K1145
#include <iostream>
using namespace std;
int main(){
      int cantalu, edad, promedio =0, suma =0;
      cout<<"Ingrese la cantidad de alumnos: ";cin>>cantalu;

      for (int i=1; i<=cantalu; i++) {
            cout<<"Ingrese la edad del alumno: ";cin>>edad;
            suma += edad;
            i++;
      }
      promedio = suma/cantalu;
      cout<<"El promedio de edades es: "<<promedio<<endl;
      return 0;
}
/***************************************************************/
// ACT 32 --> K1145
#include <iostream>
using namespace std;
int main(){
      int l1, l2, l3, suma=0, perimetro=0, Triequila =0;
      
      cout<<"\nIngrese un lado del triangulo (0 para cortar): "<<endl;cin>>l1;
      while(l1 != 0){
            cout<<"\nIngrese otro lado del triangulo: "<<endl;cin>>l2;
            cout<<"\nIngrese otro lado del triangulo: "<<endl;cin>>l3;

            if((l1=l2) && (l2=l3)){
                  Triequila++;
            }
            perimetro = l1+l2+l3;
            suma +=perimetro;
            cout<<"\n--------------------------------------------"<<endl;
      
            cout<<"\nIngrese un lado del triangulo (0 para cortar): "<<endl;cin>>l1;

      };
      
      cout<<"\nCantidad de Triangulos equilateros: "<<Triequila<<endl;
      cout<<"\nSumatoria = "<<suma<<endl;
      return 0;
}
/***********************************************************/
// ACT 33 --> K1145
#include <iostream>
using namespace std;
int main(){
      int valor, Nent=0, pares=0, Multtre=0;
      cout<<"\nDigite un valor (0 para cortar): ";cin>>valor;
      while (valor !=0){
            if(valor%2 ==0){
                  pares++;
            }
            if (valor%3 ==0){
                  Multtre++;
            }
            if (valor%2 !=0){
                  Nent++;
            } 
            cout<<"\nDigite un valor (0 para cortar): ";cin>>valor;
      }
      cout<<"\nCantidad de valores pares = "<<pares<<endl;
      cout<<"\nCantidad de valores multiplos de 3 = "<<Multtre<<endl;
      cout<<"\nCantidad de valores NO enteros = "<<Nent<<endl;
      return 0;
}
/***********************************************************/
// ACT 34 --> K1145
#include <iostream>
using namespace std;
int main(){
      int cantAlu, notafinal, Sup8=0, Sup6=0, suma=0;
      cout<<"Ingrese una cantidad n de alumnos: ";cin>>cantAlu;
      for (int i=0; i< cantAlu; i++){
            cout<<"Ingrese la nota final: ";cin>>notafinal;
            if(notafinal>=8){
                  Sup8++;
            }
            if(notafinal>=6){
                  Sup6++;
            }
            suma+= notafinal;
            i++;
      }
      cout<<"Alumnos con nota mayor o igual a 8: "<<Sup8<<endl;
      cout<<"Alumnos con nota mayor o igual a 6: "<<Sup6<<endl;
      cout<<"El promedio total es: "<<suma<<endl;
      return 0;
} 
/***********************************************************/
// ACT 35 --> K1145
#include <iostream>
using namespace std;
int main(){
      int sumapositi=0, sumanegati=0, promedio=0, i;
      for(i=9999; i>=-9999;i--){
            if(i>0){
                  sumapositi +=i;
            }
            if(i<0){
                  sumanegati +=i;
            }
            if((i>=50) && (i<=100)){
                  promedio +=i;
            }
            i++;
      }
      cout<<"\nEl promedio de los que se encuentran entre 50 y 100 = "<<(promedio/50)<<endl;
      cout<<"\nLa suma de los valores positivos: "<<sumapositi<<endl;
      cout<<"\nLa suma de los negativos: "<<sumanegati<<endl;
      return 0;
}
/***********************************************************/
// ACT 36 --> K1145
#include <iostream>
using namespace std;
int main(){
      int num, max =0, min=999, n;
      cout<<"Cuantos n valores va a querer ingresar ? : ";cin>>n;

      for(int i=0; i<=n; i++){
            cout<<"Ingrese un numero: ";cin>>num;
            if (num>max){
                  max = num;
            }
            if(num<min){
                  min=num;
            }
            i++;
      }
      cout<<"El numero de mayor valor es: "<<max<<endl;
      cout<<"El numero de menor valor es: "<<min<<endl;
      return 0;
}
/***********************************************************/
// ACT 37 --> K1145
#include <iostream>
using namespace std;
int main(){
      int num, max=0, min=999, posicion=0, maxneg=0;
      while (num !=0){
            cout<<"\nIngrese un valor n: ";cin>>num;

            if(num>max){
                  max = num;
                  posicion ++;
            }
            if (num<min){
                  min = num;
            }
            if((num > -500 && num < -200) && (num >maxneg)){
                  maxneg = num;
            }
      }
      cout<<"\nEl mayor valor positivo fue: "<<max<<endl;
      cout<<"Y su posicion es : "<<posicion<<endl;
      cout<<"\nEl menor valor positivo fue: "<<min<<endl;
      cout<<"\nEl mayor valor del intervalo [-500;-200]: "<<maxneg<<endl;

      return 0;
}
/***********************************************************/
// ACT 38 --> K1145
#include <iostream>
using namespace std;
int main(){
      int num;
      bool band = false;
      while (num !=0){
            cout<<"Ingrese un numero: "<<endl;cin>>num;

            if((num>=10) && (num<=20)){
                  band = true;
            }
      }
      if(band = true){
      cout<<"\nEn el conjunto hubo al menos un valor dentro del intervalo [10;20]"<<endl;
      }
      else{
      cout<<"\nEn el conjunto no hubo ningun valor dentro del intervalo [10;20]"<<endl; 
      }
      return 0;
}
/********************************************************************/
// ACT 39 --> K1145
#include <iostream>
#include<string.h>
#include<conio.h>

using namespace std;
int main(){
      float DNI;
      int Edad, TipoTramite, CantTramit24=0, PromEdad=0, Client123=0, Max=0;
      char Nom [15], Ape [10], MaxNom [15], MaxApe [10], Prioritario ='no', Band = 'F', PrioMen = 'N';
      
      cout<<"Ingrese su DNI (0 para cortar): ";cin>>DNI;
      while (DNI !=0 ){
            fflush(stdin);

            cout<<"Ingrese su nombre: ";cin.getline(Nom,20,'\n');
            cout<<"Ingrese su Apellido: ";cin.getline(Ape,10,'\n');
            
            cout<<"\nIngrese su edad: "<<endl;cin>>Edad;
            if((Edad > Max) && (TipoTramite ==5 || TipoTramite ==1)){
                  Max = Edad;
                  strcpy(MaxNom, Nom);
                  strcpy(MaxApe, Ape);
            }
            cout<<"\nIngrese su tipo de Tramite: "<<endl;cin>>TipoTramite;
            if ((TipoTramite==4) || (TipoTramite==2)){
                  CantTramit24++;
            }
            cout<<"\nEs usted un cliente prioritario? (si / no) : "<<endl;cin>>Prioritario;
            if((Prioritario != 'no') && (TipoTramite<4)){
                  Client123++;
                  PromEdad += Edad;
            }
            if((Prioritario != 'no') && (Edad<30)){
                  PrioMen = 'S';
            }
            cout<<"Ingrese su DNI (0 para cortar): ";cin>>DNI;    
      }
      cout<<"\nCantidad de empleados de tramite 2 o 4: "<<CantTramit24<<endl;
      cout<<"\nEdad promedio de los clientes Prioritarios tramites 1, 2 o 3: "<<(PromEdad/Client123)<<endl;
      cout<<"\nMayor de edad para tramite 1 o 5: "<<MaxNom<<" "<<MaxApe<<endl;

      if(PrioMen = 'S'){
            cout<<"\nHubo al menos un cliente prioritario menor de 30"<<endl;
      }
      else{
            cout<<"\nNO hubo cliente prioritario menor de 30"<<endl;
      }
      getch();
      return 0;
}
/***************************************************************************/
// ACT 39b --> K1145
#include <iostream>
#include<string.h>
#include<conio.h>

using namespace std;
int main(){
      int edad, maxEdad=0, sumaEdad=0, cantalumno=0;
      char NA [20], maxNom[20];

      cout<<"\nIngrese el nombre y apellido del alumno (. para cortar): ";cin>>NA;
      while (NA != '.'){
            cout<<"\nIngrese la edad del alumno: ";cin>>edad;
            if(edad > maxEdad){
                  maxEdad = edad;
                  strcpy(maxNom, NA);
            }
            if(edad >20){
                  cantalumno++;
                  sumaEdad += edad;
            }
            cout<<"\nIngrese el nombre y apellido del alumno (. para cortar): ";cin>>NA;
      }
      cout<<"\nAlumno de mayor edad: "<<maxNom;
      cout<<"\nPromedio: "<<(sumaEdad/cantalumno);
      getch();
      return 0;
}