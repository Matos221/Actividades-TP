// ACT 1 y 2 --> K1145
#include <iostream>
#include <math.h>
using namespace std;
int main(){
      int num1, num2;
      cout<<"Digite dos numeros a los cuales sumar: "; cin>>num1>>num2; //PIDO DOS VALORES AL USUARIO Y LOS ALMACENO INTERNAMENTE

      cout<<"La suma de los numeros es: "<<(num1 + num2)<<endl; //SUMA DE LOS DOS VALORES

      return 0;
}
/************************************************************************************/
// ACT 3 --> K1145
#include <iostream>
#include <math.h>
using namespace std;
int main(){
      int num1, num2, suma, prod, resta;
      cout<<"Digite dos numeros a los cuales se opéraran : "; cin>>num1>>num2; //PIDO DOS VALORES AL USUARIO Y LOS ALMACENO INTERNAMENTE

      suma = num1 + num2;
      prod = num1 * num2;
      resta = num1 - num2;

      cout<<"\nLa suma de los numeros es: "<< suma<<endl;
      cout<<"\nLa resta de los numeros es: "<< resta<<endl;
      cout<<"\nEl producto de los numeros es: "<< prod<<endl;

      return 0;
}
/*************************************************************************************/
// ACT 4 --> K1145
#include <iostream>
#include <math.h>
using namespace std;
int main(){
      int num1, num2, promedio, suma;
      cout<<"Ingrese dos numeros: ";cin>>num1>>num2;
      suma = num1 + num2;
      promedio = suma/2;

      cout<<"Promedio = "<<promedio<<endl;
      return 0;
}
/*************************************************************************************/
// ACT 5 --> K1145
#include <iostream>
#include <math.h>
using namespace std;
int main(){
      int numero;
      float Part5, Part3, resto;
      cout<<"Digite un numero: ";cin>>numero;

      Part5 = numero / 5;
      Part3 = Part5 / 3;
      resto = numero % 5;

      cout<<"Quinta parte = "<<Part5<<endl;
      cout<<"Tercera parte = "<<Part3<<endl;
      cout<<"Resto de numero con 5 = "<<resto<<endl;


      return 0;
}
/*************************************************************************************/
// ACT 6 --> K1145
#include <iostream>
#include <math.h>
using namespace std;
int main(){
      int anio, mes, dia, fecha;
      cout<<"Ingrese el anio: ";cin>>anio;
      cout<<"Ingrese el mes: ";cin>>mes;
      cout<<"Ingrese el dia: ";cin>>dia;

      fecha = (anio* 1000) + (mes*100) + dia;

      cout<<"Su fecha es: "<<anio<<mes<<dia<<endl;
      cout<<fecha<<endl;


      return 0;
}
/*************************************************************************************/
// ACT 7 --> K1145
#include <iostream>
#include<cmath>
using namespace std;
int main(){
      int ano;
      int mes;
      int dia;
      int fecha;
      int mesdia;
      cout<<"ingrese una fecha en la forma AAAAMMDD: ";cin>>fecha;

      ano = int(fecha/10000);
      mesdia = fecha%10000;
      
      mes = int(mesdia/100);
      dia = mesdia%100;

      cout<<"Anio: "<< ano<<endl;
      cout<<"Mes: "<<mes<<endl;
      cout<<"Dia: "<<dia<<endl;

      return 0;
}
/*************************************************************************************/
// ACT 8 --> K1145
#include <iostream>
#include<cmath>
using namespace std;
int main(){
      float PI = 3.1416, diametro, area;
      int radio;
      cout<<"Digite el radio de la ciurcunferencia: ";cin>>radio;

      diametro = 2 * PI * radio;
      area = PI * (pow(radio,2));

      cout<<"\nDiametro = "<<diametro<<endl;
      cout<<"\nArea = "<<area<<endl;
      return 0;
}
/*************************************************************************************/
// ACT 9 --> K1145
#include <iostream>
#include<cmath>
using namespace std;
int main(){
      int num1, num2;
      cout<<"Ingrese dos enteros: ";cin>>num1>>num2;

      if (num1 > num2){
            cout<<"El mayor es el primer valor" <<endl;
      }
      else{
            cout<<"El segundo valor es mayor o igual que el primero"<<endl;
      }

      return 0;
}
/*************************************************************************************/
// ACT 10 --> K1145
#include <iostream>
#include<cmath>
using namespace std;
int main(){
      int num1, num2;
      cout<<"Ingrese dos enteros: ";cin>>num1>>num2;

      if(num1>num2){
            cout<<"El mayor es el 1er valor";
      } else{
            if(num1<num2){
                  cout<<"El mayor es el 2do valor";
       }    else{
                  cout<<"Ambos son iguales";
            }
      }
      return 0;
}
/*************************************************************************************/
// ACT 11 --> K1145
#include <iostream>
#include<cmath>
using namespace std;
int main(){

      int D1, M1, A1, D2, A2, M2;
      cout<<"\nIngrese primera fecha (anio mes dia): "; cin>>A1>>M1>>D1;

      cout<<"\nIngrese segunda fecha (anio mes dia): "; cin>>A2>>M2>>D2;

      if(((A1 > A2) || ((A1=A2) && (M1>M2))) || ((A1=A2) && (M1=M2) && (D1>D2))){
            cout<<"\nLa fecha 1 es la mas actual";
      }else{
            if(((A2 > A1) || ((A1=A2) && (M2>M1))) || ((A1=A2) && (M1=M2) && (D2>D1))){
            cout<<"\nLa fecha 2 es la mas actual";
            } 
            else{
                  cout<<"Las fechas son iguales";
            }
      }
      return 0;
}
/*************************************************************************************/
// ACT 12 --> K1145
#include <iostream>
#include<cmath>
using namespace std;
int main(){
      float num1, num2, suma, resta, producto, cociente;
      cout<<"\nDigite dos numeros: ";cin>>num1>>num2;

      suma = num1 + num2;
      resta = num1 - num2;
      producto = num1 * num2;
      
      cout<<"\nSuma = "<<suma<<endl;
      cout<<"\nResta = "<<resta<<endl;
      cout<<"\nProducto = "<<producto<<endl;
      if((num2!=0)){
            cociente = num1/num2;
      }
      cout<<"\nCociente = "<<cociente<<endl;

      return 0;
}
/*************************************************************************************/
// ACT 13 --> K1145
#include <iostream>
#include<cmath>
using namespace std;
int main(){
      int num1, num2, operacion;
      cout<<"Meteme dos numeros: ";cin>>num1>>num2;
      cout<<"Ingrese operacion / (suma = 0) (resta = 1) (producto = 2): ";cin>>operacion;

      switch (operacion)
      {
      case 0: cout<<"La suma es: "<<num1+num2<<endl;
            break;
      case 1: cout<<"La resta es: "<<num1-num2<<endl;
            break;
       case 2: cout<<"El producto es: "<<num1*num2<<endl;
            break;
      default: cout<<"NO HAY OPERACION";
            break;
      }
      return 0;
}
/*************************************************************************************/
// ACT 14 --> K1145
#include <iostream>
#include<cmath>
using namespace std;
int main(){
      int num1, num2, num3;
      cout<<"Ingrese tres numeros: ";cin>>num1>>num2>>num3;
      if((num1+num2>num3) && (num2+num3)>num1 && (num1+num3)>num2){
            cout<<"Forman un Triangulo"<<endl;
      }
      else{
            cout<<"NO forman un triangulo";
      }
      return 0;
}
/*************************************************************************************/
// ACT 15 --> K1145
#include <iostream>
#include<cmath>
using namespace std;
int main(){
      int L1, L2, L3;
      cout<<"Ingrese tres lados: ";cin>>L1>>L2>>L3;

      if((L1=L2) && (L2=L3)){
            cout<<"Es triangulo Equilatero"<<endl;
      }else{
            if ((L1=L2) || (L2=L3) || (L1=L3)){
                  cout<<"Es triangulo Isoceles"<<endl;
            }
            else{
                  cout<<"Es triangulo Escaleno"<<endl;
            }
      }
      return 0;
}
/*************************************************************************************/