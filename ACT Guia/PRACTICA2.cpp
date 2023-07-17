// ACT 16 --> K1145
#include <iostream>
using namespace std;
int main(){
      float n1, n2;
      int operacion;
      cout<<"\nIngrese dos numeros: ";cin>>n1>>n2;

      cout<<"\nDigite operacion a realizar: "<<endl;
      cout<<"\nSuma --> 0 / Resta --> 1 / Producto --> 2 / cociente --> 3: ";cin>>operacion;
      switch (operacion){
      case 0: cout<<"\nLa suma es: "<<n1+n2<<endl;
            break;      
      case 1: cout<<"\nLa resta es: "<<n1-n2<<endl;
            break;
      case 2: cout<<"\nEl producto es: "<<n1*n2<<endl;
            break;
      case 3: cout<<"\nEl cociente es: "<<n1/n2<<endl;

      default:cout<<"No existe comando para esa operacion";
            break;
      }
      return 0;
}
/****************************************************************************/
// ACT 17 --> K1145
#include <iostream>
using namespace std;
int main(){
      int mes, anio;
      cout<<"\nIngrese un mes: ";cin>>mes;
      cout<<"\nIngrese anio: ";cin>>anio;

      switch (mes){
      case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            cout<<"\nTiene 31 dias";
            break;

      case 4: case 6: case 9: case 11: 
            cout<<"\nTiene 30 dias";
            break;

      default: if( (anio%4)== 0){
                  cout<<"\nTiene 29 dias";
                  break;
            }
            else{
                  cout<<"\nTiene 28 dias";
                  break;
            }
      }      
      return 0;
}
/*******************************************************************/
// ACT 19 --> K1145
#include <iostream>
using namespace std;
int main(){
      for(int n=0;n<=20;n++){
            cout<<n<<endl;
      }
      return 0;
}
/*******************************************************************/
// ACT 20 --> K1145
#include <iostream>
using namespace std;
int main(){
      for(int n=0;n<=20;n++){
            if (n%2 ==0){
            cout<<n<<endl;
            }
            
      }
      return 0;
}
/*******************************************************************/
// ACT 21 --> K1145
#include <iostream>
using namespace std;
int main(){

      int n, A, B;
      cout<<"Ingrese una cantidad n de pares: ";cin>>n;
      for ( int i=0; i=n; i++) {
            cout<<"\nIngrese un numero A: "<<endl;cin>>A;
            cout<<"\nIngrese un numero B: "<<endl;cin>>B;

            cout<<"\nresultado de la suma = "<<A+B<<endl;
            i++;
      }            
      return 0;
}
/*******************************************************************/
// ACT 22 --> K1145
#include <iostream>
using namespace std;
int main(){

      int n, A, B, operacion;

      cout<<"Ingrese una cantidad n de pares: ";cin>>n;
      for ( int i=0; i<=n; i++) {
            cout<<"\nIngrese un numero A: "<<endl;cin>>A;
            cout<<"\nIngrese un numero B: "<<endl;cin>>B;

       cout<<"\nDigite operacion a realizar: "<<endl;
       cout<<"\nSuma --> 0 / Resta --> 1 / Producto --> 2 / cociente --> 3: ";cin>>operacion;
       switch (operacion){
       case 0: cout<<"\nLa suma es: "<<A+B<<endl;
            break;      
       case 1: cout<<"\nLa resta es: "<<A-B<<endl;
            break;
       case 2: cout<<"\nEl producto es: "<<A*B<<endl;
            break;
       case 3: cout<<"\nEl cociente es: "<<A/B<<endl;

       default:cout<<"No existe comando para esa operacion";
            break;
      }
            i++;
      }            
      return 0;
}
/*******************************************************************/
// ACT 24 --> K1145
#include <iostream>
using namespace std;
int main(){
      int n=0;
      while (n<=20) {
        cout<<n<<endl;
        n++;
      }
      return 0;
}
/*******************************************************************/
// ACT 25 --> K1145
#include <iostream>
using namespace std;
int main(){
      int n=0;
      while (n<=20) {
            if(n%2 ==0){
        cout<<n<<endl;
            }
        n++;
      }
      return 0;
}
/*******************************************************************/
// ACT 26 --> K1145
#include <iostream>
using namespace std;
int main(){
      int n, i=0, A, B;
      cout<<"Ingrese n pares de valores: ";cin>>n;
      while (i<=n) {
            cout<<"\nIngrese un numero A: "<<endl;cin>>A;
            cout<<"\nIngrese un numero B: "<<endl;cin>>B;

            cout<<"\nresultado de la suma = "<<A+B<<endl;
            i++;
      }            
      return 0;
}
/*******************************************************************/
// ACT 27 --> K1145
#include <iostream>
using namespace std;
int main(){
      int a, b;
      while ((a!=0) || (b!=0)){
            cout<<"Ingrese un numero: ";cin>>a;
            cout<<"Ingrese otro numero: ";cin>>b;

            cout<<(a+b)/2<<endl;
      }
      return 0;
}
/*******************************************************************/
// ACT 28 --> K1145
#include <iostream>
using namespace std;
int main(){
      int zona;
      while ((zona>=1) && (zona=10)) {
      cout<<"\nIngrese un numero de zona: "<<endl ;cin>>zona;
            cout<<"\nZona ok entre 1 y 10 "<<endl;
      }
      return 0;
}
/*******************************************************************/
// ACT 29 --> K1145
#include <iostream>
using namespace std;
int main(){
      int zona;
      do{
      cout<<"Ingrese un numero de zona: "<<endl;cin>>zona;
            cout<<"\nZona ok entre 1 y 10 "<<endl;

      }while ((zona>=1) && (zona=10));      
      return 0;
}
/*******************************************************************/
// ACT 30 --> K1145
#include <iostream>
using namespace std;
int main(){
      int zona;
      do{
      cout<<"Ingrese un numero de zona: "<<endl;cin>>zona;
            cout<<"\nZona ok entre 1 y 10 "<<endl;

      }while ((zona>=1) && (zona=10));      
      return 0;
}
/*******************************************************************/