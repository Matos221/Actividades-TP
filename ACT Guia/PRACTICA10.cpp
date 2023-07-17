//ACT 100 --> K-1145
#include<iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo{
      int numero;
      Nodo *siguiente;
};
//PROTIPOS DE FUNC
void AgregarPila(Nodo *&, int);
void SacarPila(Nodo *&, int &);
//FUNC MAIN
int main(){ 
      Nodo *Pila = NULL;
      int numero;

      cout<<"\nIngrese un numero a la pila: ";cin>>numero;
      while (numero !=0){
            AgregarPila(Pila, numero);
            cout<<"\nIngrese un numero a la pila: ";cin>>numero;
      }
      while (Pila != NULL){
            SacarPila(Pila,numero);
            if(Pila != NULL){
                  cout<<numero<<" , ";
            }
            else{
                  cout<<numero<<" . "<<endl;
            }
      }
      getch();
	return 0;
}
//FUNCS
void AgregarPila(Nodo *&pila , int n){
      Nodo *nuevo_nodo = new Nodo;
      nuevo_nodo->numero = n;
      nuevo_nodo->siguiente = pila;
      pila = nuevo_nodo;
      cout<<"\tEl elemento a sido agregado a pila correctamente"<<endl;
}
void SacarPila(Nodo *&pila , int &n){
      Nodo *aux = pila;
      n = aux->numero;
      pila = aux->siguiente;
      delete aux;
}
/***************************************************************/
//ACT 101 --> K-1145
#include<iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;

struct Productos{
      int CodProd;
      float PrecioUnit;
};
struct Nodo{
      Productos Prod;
      Nodo *siguiente;
};
//PROTIPOS DE FUNC
void AgregarPila(Nodo *&, Productos);
void SacarPila(Nodo *&, Productos &);
//FUNC MAIN
int main(){ 
      Nodo *Pila = NULL;
      Productos Prod;

      cout<<"\nIngrese codigo de producto (0 para cortar): ";cin>>Prod.CodProd;
      while (Prod.CodProd !=0) {
            cout<<"\nIngrese Precio Unitario: ";cin>>Prod.PrecioUnit;
            AgregarPila(Pila ,Prod);    
      cout<<"\nIngrese codigo de producto (0 para cortar): ";cin>>Prod.CodProd;
      }
      while (Pila != NULL){
            SacarPila(Pila, Prod);
            cout<<"\nCodigo de Producto: "<<Prod.CodProd;
            cout<<"\nPrecio unitario: "<<Prod.PrecioUnit;
            cout<<"\n";
            cout<<"==================================="<<endl;
      }
      getch();
	return 0;
}
//FUNCS
void AgregarPila(Nodo *&pila , Productos Prod){
      Nodo *nuevo_nodo = new Nodo;
      nuevo_nodo->Prod = Prod;
      nuevo_nodo->siguiente = pila;
      pila = nuevo_nodo;
      cout<<"\tEl elemento a sido agregado a pila correctamente"<<endl;
}
void SacarPila(Nodo *&pila , Productos &Prod){
      Nodo *aux = pila;
      Prod.CodProd = aux->Prod.CodProd;
      Prod.PrecioUnit = aux->Prod.PrecioUnit;
      pila = aux->siguiente;
      delete aux;
}
/***********************************************************************/
//ACT 102 --> K-1145
#include<iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;

struct Productos{
      int CodProd;
      float PrecioUnit;
};
struct Nodo{
      Productos Prod;
      Nodo *siguiente;
};

//FUNCS
void AgregarPila(Nodo *&pila , Productos Prod){
      Nodo *nuevo_nodo = new Nodo;
      nuevo_nodo->Prod.CodProd = Prod.CodProd;
      nuevo_nodo->Prod.PrecioUnit = Prod.PrecioUnit;
      nuevo_nodo->siguiente = pila;
      pila = nuevo_nodo;
}
void SacarPila(Nodo *&pila , Productos &Prod){
      Nodo *aux = pila;
      Prod = aux->Prod;
      pila = aux->siguiente;
      delete aux;
}
//FUNC MAIN
int main(){ 
      Nodo *Pila = NULL;
      Nodo *PilaAux= NULL;
      Productos Prod;
      int n;

      cout<<"\nIngrese codigo de producto (0 para cortar): ";cin>>Prod.CodProd;
      while (Prod.CodProd !=0) {

      cout<<"\nIngrese el Precio Unitario: ";cin>>Prod.PrecioUnit;
            AgregarPila(Pila ,Prod);    
      cout<<"\nIngrese codigo de producto (0 para cortar): ";cin>>Prod.CodProd;
      }

      cout<<"Que elemento desea eliminar?"<<endl;
	cin>>n;

      for(int i=0; i<n-1; i++){
            SacarPila(Pila, Prod);
            AgregarPila(PilaAux, Prod);
      }
      SacarPila(Pila, Prod);

      while(Pila != NULL){
            SacarPila(Pila, Prod);
            AgregarPila(PilaAux, Prod);
      }

      cout<<"Codp        PU "<<endl;
      while(Pila != NULL){
            cout<<"========================="<<endl;
            SacarPila(PilaAux, Prod);
            cout<<"  "<<Prod.CodProd<<"        "<<Prod.PrecioUnit<<endl;
      } 
      getch();
	return 0;
}
/***************************************************************/
//ACT 103 --> K-1145
#include<iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;

struct Productos{
      int CodProd;
      float PrecioUnit;
};
struct Nodo{
      Productos Prod;
      Nodo *siguiente;
};
//PROTIPOS DE FUNC
void InsertarCola(Nodo *& , Nodo *&, Productos);
bool VerColaVacia(Nodo *);
void SuprimirCola(Nodo *&, Nodo *&, Productos &);
//FUNC MAIN
int main(){ 
      Nodo *frente = NULL;
      Nodo *fin = NULL;
      Productos Prod;

      cout<<"\nIngrese el codigo de producto (0 para terminar): ";cin>>Prod.CodProd;
      while (Prod.CodProd !=0){
            cout<<"\nIngrese el precio unitario: ";cin>>Prod.PrecioUnit;
            InsertarCola(frente, fin, Prod);
            cout<<"\nIngrese el codigo de producto (0 para terminar): ";cin>>Prod.CodProd;
      }
      while (frente != NULL){
            SuprimirCola(frente, fin, Prod);
            cout<<"\nCodigo de Producto: "<<Prod.CodProd;
            cout<<"\nPrecio Unitario: "<<Prod.PrecioUnit;
            cout<<"\n";
            cout<<"==================================="<<endl;
      }
      getch();
	return 0;
}
//DEF DE FUNCS
void InsertarCola(Nodo *&frente , Nodo*&fin, Productos Prod){
      Nodo *nuevo_nodo = new Nodo;
      nuevo_nodo->Prod.CodProd = Prod.CodProd;
      nuevo_nodo->Prod.PrecioUnit = Prod.PrecioUnit;
      nuevo_nodo->siguiente = NULL;

      if(VerColaVacia(frente)){
            frente = nuevo_nodo;
      }
      else{
            fin->siguiente = nuevo_nodo;
      }
      fin = nuevo_nodo;
      cout<<"\tElemento insertado correctamente a la cola"<<endl;
}
bool VerColaVacia(Nodo *frente){
      return(frente == NULL)? true: false;
}
void SuprimirCola(Nodo *&frente, Nodo *&fin, Productos &Prod){
      Nodo *aux = frente;
      Prod.CodProd = frente->Prod.CodProd;
      Prod.PrecioUnit = frente->Prod.PrecioUnit;

      if(frente == fin){ //UN SOLO NODO
            frente = NULL;
            fin = NULL;
      }
      else{ //MAS DE UN NODO
            frente = frente->siguiente;
      }
      delete aux;
}
/***************************************************************/
//ACT 104 --> K-1145 DE NICO
#include<iostream>
using namespace std;

struct tInfo{
	int CodP, PU;
};
struct Nodo{
	tInfo INFO;
	Nodo *sig;
};

void Agregar(Nodo *&Fte, Nodo *&Fin, tInfo RInfo){
	Nodo *Pnue = new Nodo;
	Pnue->INFO = RInfo;
	Pnue->sig = NULL;
	if(Fte == NULL){
		Fte=Pnue;
	}else{
		Fin->sig = Pnue;
	}
	Fin = Pnue;
}
void Suprimir (Nodo *&Fte, Nodo *&Fin, tInfo &RInfo){
	Nodo *ptr = Fte;
	RInfo = ptr->INFO;
	Fte = Fte->sig;
	delete ptr;
	if(Fte==NULL){
		Fin = NULL;
	}
}
int main(){
	Nodo *Fte = NULL;
	Nodo *Fin = NULL;
	Nodo *Fte2 = NULL;
	Nodo *Fin2 = NULL;
	tInfo RInfo;
	int n;
	
	cout<<"Ingrese codigo de producto (0 para cortar)"<<endl;
	cin>>RInfo.CodP;
	while(RInfo.CodP != 0){
		cout<<"Ingrese el precio unitario del producto"<<endl;
		cin>>RInfo.PU;
		Agregar(Fte, Fin, RInfo);
		cout<<"Ingrese codigo de producto (0 para cortar)"<<endl;
		cin>>RInfo.CodP;
	}
	
	cout<<"Que elemento desea eliminar?"<<endl;
	cin>>n;
	
	for(int i=0; i<n-1; i++){
		Suprimir (Fte, Fin, RInfo);
		Agregar(Fte2, Fin2,  RInfo);
	}
	Suprimir(Fte, Fin, RInfo);
	while(Fte!= NULL){
		Suprimir (Fte, Fin, RInfo);
		Agregar(Fte2, Fin2,  RInfo);
	}
	
	cout<<" CodP      PU  "<<endl;
	while(Fte2 != NULL){
		cout<<"-----------------------------"<<endl;
		Suprimir(Fte2, Fin2, RInfo);
		cout<<"  "<<RInfo.CodP<<"        "<<RInfo.PU<<endl;
	}
	return 0;
	}
/***************************************************************/
//ACT 105 y 106 --> K-1145
#include<iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;

struct Productos{
      int CodProd, Stock;
};
struct Nodo{
      Productos Prod;
      Nodo *siguiente;
};
struct Pedido{
      int CodProd, Cantidad;
};

//PROTIPOS DE FUNC
Nodo* InsertarListaOrdenado(Nodo *&, Productos);
Nodo* BuscarLista(Nodo *, Productos);
void IngresarProd(Nodo *&);
void InsertarPedido(Nodo *&);
void MostrarLista(Nodo *);

//FUNC MAIN
int main(){ 
      Nodo *lista = NULL;
      int opc;
      Productos Prod;
      Pedido pedido;

      do{
       cout <<"\n-------------MENU--------------" << endl;
	 cout << "0) Finalizar programa         " << endl;
	 cout << "1) Ingresar productos" << endl;
	 cout << "2) Ingresar Pedido" << endl;
	 cout << "3) Imprimir lista" << endl;
	 cout << "Ingrese Operacion: " << endl;
	 cin >> opc;
          
          switch (opc)
          {
          case 0: cout<<"\nGracias por usar el Programa"<<endl;
                  break;
          case 1: 
                  IngresarProd(lista);
                  break;
          case 2: 
                  InsertarPedido(lista);
                  break;
          case 3:
                  MostrarLista(lista);
                  break;
          default:cout<<"ERORR !! OPERACION INVALIDA  ";
                  break;
          }
      } while (opc != 0);
      
      getch();
	return 0;
}
//DEF DE FUNCS
Nodo* InsertarListaOrdenado(Nodo *&lista, Productos Prod){
      Nodo *nuevo_nodo = new Nodo();
      nuevo_nodo->Prod = Prod;

      Nodo *aux1 = lista;
      Nodo *aux2;

      while ((aux1 != NULL) && (aux1->Prod.CodProd < Prod.CodProd)){
            aux2 = aux1;
            aux1 = aux1->siguiente;
      }
      if(lista == NULL) {
            lista = nuevo_nodo;
      }
      else{
            aux2->siguiente = nuevo_nodo;
      }
      nuevo_nodo->siguiente = aux1;
      return nuevo_nodo;
}
Nodo* BuscarLista(Nodo *lista, Pedido pedido){
      Nodo *actual = lista;
      while (actual != NULL && actual->Prod.CodProd != pedido.CodProd){
            actual = actual->siguiente;
      }   
      return actual;
}
void IngresarProd(Nodo *&lista){
      Productos Prod;
      Nodo *nodoProd;
      
      cout<<"\nIngrese un codigo de producto (0 para cortar): ";cin>>Prod.CodProd;
      while (Prod.CodProd !=0){
            cout<<"\nIngrese el stock: ";cin>>Prod.Stock;
            nodoProd = InsertarListaOrdenado(lista,Prod);

      cout<<"\nIngrese un codigo de producto (0 para cortar): ";cin>>Prod.CodProd;
      }
}
void InsertarPedido(Nodo *&lista){
      Pedido pedido;
      cout<<"\nIngrese un codigo de producto (0 para cortar): ";cin>>pedido.CodProd;
      while (pedido.CodProd !=0){
            Nodo *ListaProd = BuscarLista(lista,pedido);

            if(ListaProd == NULL ){
                  cout<<"\n NO se encontro el codigo"<<endl;
            }
            else{
                  cout<<"\nIngrese la cantidad Pedida: ";cin>>pedido.Cantidad;
                  if(ListaProd->Prod.Stock > pedido.Cantidad){
                        ListaProd->Prod.Stock -= pedido.Cantidad;
                        cout<<"Cantidad vendida es: "<<pedido.Cantidad;
                  }
                  else{
                        cout<<"\nNo hay stock suficiente";
                  }
            }
      cout<<"\nIngrese un codigo de producto (0 para cortar): ";cin>>pedido.CodProd;
      }     
}
void MostrarLista(Nodo *lista){
      while (lista != NULL){
            cout<<"\nCodigo Producto: "<<lista->Prod.CodProd;
            cout<<"\nStock: "<<lista->Prod.Stock;
            cout<<"\n";
            cout<<"==================================="<<endl;
            lista = lista->siguiente;
      }
}
/*************************************************************************************************/
//ACT 107 --> K-1145
#include<iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct Productos{
      int codigo;
      float PreUnit;
};

struct Nodo{
      Productos info;
      Nodo *ant;
      Nodo *sig;
};

//DEF DE FUNCS
void InsertarOrdenado(Nodo *&lista, Productos info){
      Nodo *nuevo = new Nodo();
      nuevo->info = info;
      if((lista == NULL) || (nuevo->info.codigo < lista->info.codigo)){
            nuevo->sig = lista;
            nuevo->ant = NULL;
            if(lista != NULL)
                  lista->ant = nuevo;
            lista = nuevo;
      }
      else{
            Nodo *aux1 = lista;
            Nodo *aux2;
            while((aux1 != NULL) && (nuevo->info.codigo > aux1->info.codigo)){
                  aux2 = aux1;
                  aux1 = aux1->sig;
            }
            aux2->sig = nuevo;
            nuevo->ant = aux2;
            nuevo->sig = aux1;
             if(aux1 != NULL){
                  aux1->ant = nuevo;
             }
      }
}
void EliminarPrimero(Nodo *&lista, Productos &info){
      Nodo *aux = lista;
      info = aux->info;
      lista = lista->sig;
      delete aux;
}
//FUNC MAIN
int main(){
      Productos info;
      Nodo *lista = NULL;
      Nodo *aux1;
      Nodo *aux2;

      cout<<"\nIngrese un codigo de producto (0 para cortar): ";cin>>info.codigo;
      while(info.codigo != 0){
            cout<<"Ingrese un precio unitario: ";cin>>info.PreUnit;
            InsertarOrdenado(lista, info);
      cout<<"\nIngrese un codigo de producto (0 para cortar): ";cin>>info.codigo;

      }
      cout<<"\n";

      cout<<"\tLista de forma creciente: "<<endl;
      cout<<"Cod Prod: "<<endl;
      aux1 = lista;
      while(aux1 != NULL){
            cout<< " " <<aux1->info.codigo<< "  -  " <<aux1->info.PreUnit<<endl;
            aux2 = aux1;
            aux1 = aux1->sig;
      }
      cout<<"\n";

      aux1 = aux2;
      cout<<"\tLista de forma decreciente: "<<endl;
      cout<<"Cod Prod: "<<endl;
      while (aux1 != NULL){
            cout<< " " <<aux1->info.codigo<< "  -  " <<aux1->info.PreUnit<<endl;
            aux1 = aux1->ant;
      }
      return 0;
}
/*********************************************************************************************/
//ACT 108 --> K-1145
#include<iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct Productos{
      int codigo, sucursal;
      float PrecioUnit;
};
struct Nodo{
      Productos info;
      Nodo *sig;
};

//DEF DE FUNCS
void InsertarOrd(Nodo *&lista, Productos info){
      Nodo *nuevo = new Nodo();
      nuevo->info = info;
      //Caso que lista = NULL, nuevo->info.coidgo < lista->info.coidgo ó nuevo->info.coidgo= al lista->info.coidgo pero 
      //nuevo->info.sucursal < lista->info.sucursal
      if((lista == NULL) || (nuevo->info.codigo < lista->info.codigo) 
      || ((nuevo->info.codigo = lista->info.codigo) && (nuevo->info.sucursal < lista->info.sucursal)) ){
            nuevo->sig = lista;
            lista = nuevo;
      }
      //Me quedo en el ciclo mientras nuevo->info.coidgo > aux1->info.coidgo ó
      //nuevo->info.coidgo = aux1->info.coidgo pero nuevo->info.sucursal > aux1->info.sucursal
      else{
            Nodo *aux1 = lista;
            Nodo *aux2;

            while((aux1 != NULL) && ((nuevo->info.codigo > aux1->info.codigo)
            || ((nuevo->info.codigo = aux1->info.codigo) && (nuevo->info.sucursal > aux1->info.sucursal)) )){
                  aux2 = aux1;
                  aux1 = aux1->sig;
            }
            aux2->sig = nuevo;
            nuevo->sig = aux1;
      }
}
void ElminaPrimero(Nodo *&lista, Productos &info){
      Nodo *aux = lista;
      info = aux->info;
      lista = lista->sig;
      delete aux;
}

//FUNC MAIN
int main(){
      Productos info;
      Nodo *lista = NULL;

      cout<<"\nIngresar codigo de producto (0 para cortar): ";cin>>info.coidgo;
      while(info.coidgo != 0){
            cout<<"\nIngrese sucursal: ";cin>>info.sucursal;
            cout<<"\nIngrese Precio unitario: ";cin>>info.PrecioUnit;
            InsertarOrd(lista, info); 

      cout<<"\nIngresar codigo de producto (0 para cortar): ";cin>>info.coidgo;

      }
      cout<<"\nCod Prod: "<<"   "<< "Sucursal " <<"   "<< "Precio Unit:"<<endl;
      while (lista != NULL){
            ElminaPrimero(lista, info);
            cout<< " " <<info.coidgo<< "          " << info.sucursal << "           " << info.PrecioUnit<<endl;       
      }
      return 0;
}
/***************************************************************/
//ACT video profe LISTAS--> K1145 
#include <iostream>
using namespace std;

struct Nodo{
      int dato;
      Nodo* siguiente;
};

Nodo* InsertarOrdenado(Nodo* inicio, Nodo* nuevo){
      if(inicio == NULL || nuevo->dato < inicio->dato){
            nuevo->siguiente=inicio;
            inicio=nuevo;
      }
      else{
            Nodo* aux=inicio;
            while (aux->siguiente != NULL && aux->siguiente->dato < nuevo->dato){
                  aux = aux->siguiente; 
            }
            if(aux->siguiente != NULL){
                  nuevo->siguiente = aux->siguiente;
            }
            aux->siguiente = nuevo;
      }
      return inicio;
}
Nodo* CargarNumeros(Nodo* inicio){
      Nodo* nuevo;
      int n;
      cout<<"\nIngrese un numero (0 para cortar): ";cin>>n;
      while (n !=0) {
            nuevo = new Nodo;
            nuevo->dato = n;
            nuevo->siguiente=NULL;
            inicio = InsertarOrdenado(inicio, nuevo);
      cout<<"\nIngrese un numero (0 para cortar): ";cin>>n;
      }
      return inicio;
}
void Imprimir(Nodo* inicio){
      for(Nodo* p=inicio; p!= NULL; p=p->siguiente){
            cout<<p->dato<<"    ";
      }
      cout<<endl;
}
Nodo* EliminarMult(Nodo* inicio, int num){
      Nodo* pEliminar;
      Nodo* aux = inicio;
      while(aux != NULL){
            if(inicio->dato % num == 0){
                  pEliminar = inicio;
                  aux = aux->siguiente;
                  inicio = inicio->siguiente;
                  delete pEliminar;
            }
            else{
                  if(aux->siguiente != NULL && aux->siguiente->dato % num==0){
                        pEliminar = aux->siguiente;
                        aux->siguiente = aux->siguiente->siguiente;
                        delete pEliminar;
                  }
                  else{
                        aux = aux->siguiente;
                  }
            }
      }
      return inicio;
}
int main(){
      Nodo* lista= NULL;
      lista = CargarNumeros(lista);

      cout<<"\nLista original: "<<endl;
      Imprimir(lista);

      lista = EliminarMult(lista, 5);
      cout<< endl;
      cout<<"\nLista sin multiplos: "<<endl;
      Imprimir(lista);
}