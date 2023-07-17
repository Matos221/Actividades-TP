//ESTRUCTURAS  DINAMICAS
#include <iostream>
//pila
struct Tinfo{
      int dato;
};
struct Nodo{
      Tinfo info;
      Nodo *sig;
};
void meterOpush(Nodo *pila, Tinfo Rinfo){
      Nodo *nuevo = new Nodo();
      nuevo->info = Rinfo;
      pila->sig = pila;
      pila = nuevo;
}      
void sacaOpop(Nodo *&pila, Tinfo &Rinfo){
      Nodo *aux = pila;
      Rinfo = aux->info;
      pila = pila->sig;
      delete aux;
}

//cola 
struct Tinfo{
      int dato1, dato2;
};
struct Nodo{
      Tinfo info;
      Nodo *sig;
};
void Agregar(Nodo *fte, Nodo *fin, Tinfo Rinfo){
      Nodo *nuevo = new Nodo();
      nuevo->info = Rinfo;
      nuevo->sig = NULL;
      if(fte == NULL){
            fte = nuevo;
      }
      else{
            fin->sig = nuevo;
      }
      fin = nuevo;
}
void Suprimir(Nodo *&fte, Nodo *&fin, Tinfo &Rinfo){
      Nodo *aux = fte;
      Rinfo = aux->info;
      fte = fte->sig;
      delete aux;
      if(fte == NULL){
            fin = NULL;
      }
}

//lista
Nodo* InsertarOrd(Nodo *&lista, Tinfo Rinfo){ //VERSION MODULAR
      if((lista == NULL) &&(Rinfo.dato < lista->info.dato)){
            Nodo *nuevo = new Nodo(); //INSERTA DELANTE
            nuevo->info = Rinfo;
            nuevo->sig = lista;
            lista = nuevo;
      }
      else{ 
            Nodo *nuevo= new Nodo();  //INSERTA MEDIO
            nuevo->info = Rinfo;

            Nodo *aux1 = lista;
            Nodo *aux2;
            while((aux1 != NULL) && (nuevo->info.dato > aux1->info.dato)){
                  aux2 = aux1;
                  aux1 = aux1->sig;
            }
            aux2->sig = nuevo;
            nuevo->sig = aux1;

      }
      return nuevo;
}
Nodo* InsertarOrd(Nodo *&lista, Tinfo Rinfo){ //VERSION NO MODULAR
      Nodo *nuevo = new Nodo(); 
       nuevo->info = Rinfo;
      if((lista == NULL) &&(Rinfo.dato < lista->info.dato)){ 
            nuevo->sig = lista;
            lista = nuevo;
      }
      else{ 
            Nodo *aux1 = lista;
            Nodo *aux2;
            while((aux1 != NULL) && (nuevo->info.dato > aux1->info.dato)){
                  aux2 = aux1;
                  aux1 = aux1->sig;
            }
            aux2->sig = nuevo;
            nuevo->sig = aux1;

      }
      return nuevo;
}
Nodo* InsOrdenadoPorDobleClave(Nodo *&lista, Tinfo Rinfo){
      Nodo *nuevo = new Nodo();
      nuevo->info = Rinfo;

      if((lista == NULL) || (nuevo->info.dato1 <= lista->info.dato1) && (nuevo->info.dato2 < lista->info.dato2)){
            nuevo->sig = lista;
            lista = nuevo;
      }
      else{ 
            Nodo *aux1 = lista;
            Nodo *aux2;

            while((aux1 != NULL) && (nuevo->info.dato1 >= aux1->info.dato1) && (nuevo->info.dato2 >= aux1->info.dato2)){
                  aux2 = aux1;
                  aux1 = aux1->sig;
            }
            aux2->sig = nuevo;
            nuevo->sig = aux1;

      }
      return nuevo;
}
void Eliminar1ro(Nodo *&lista, Tinfo &Rinfo){
      Nodo *aux = lista;
      Rinfo = aux->info;
      lista = lista->sig;
      delete aux;
}
//APAREO DE 2 LISTAS
void ApareoListas(Nodo *lista1, Nodo *lista2, Nodo *&lista3, Tinfo Rinfo){
      Nodo *p1 = lista1;
      Nodo *p2 = lista2;
      Nodo *lista3 = NULL;

      while((p1 != NULL) && (p2 != NULL)){
            if(p1->info.dato1 < p2->info.dato1){
                  Rinfo = p1->info;
                  p1 = p1->sig;
            }
            else{
                  Rinfo = p2->info;
                  p2 = p2->sig;
            }
            //sea crea nodo en L3 con la INFO que resultó < entre L1 apuntada por p1 y L2 apuntada por p2
            Nodo *nuevo = new Nodo();
            nuevo->info = Rinfo;
            nuevo->sig=NULL;
            //una vez creado y cargado el nodo, se lo engancha con L3 si lista vacía, o con el sgte de p3 es decir al final todas las restantes veces. 
            //Y se actualiza p3 para que siempre apunte al último nodo 
           if(lista3 == NULL){
                  lista3 = nuevo;
            }
            else{
                  lista3->sig = nuevo;
            }// se actualiza p3 con la dirección del último nodo para siempre enganchar con el final 
            lista3 = nuevo;
      }//una vez que sale del ciclo, queda por agregar a L3 todos los nodos de aquella lista que no se acabó

      if(p1 ==NULL){ //si la que se terminó es p1, entonces voy generando con los valores de L2
            while(p2!=NULL){
                  Rinfo = p2->info;
                  p2 = p2->sig;
                  Nodo *nuevo = new Nodo();
                  nuevo->info = Rinfo;
                  nuevo->sig = NULL;
                  lista3->sig = nuevo;
                  lista3 = nuevo;
            }
      }
      else{
            while (p1 != NULL){
                  Rinfo = p1->info;
                  p1 = p1->sig;
                  Nodo *nuevo = new Nodo();
                  nuevo->info = Rinfo;
                  nuevo->sig = NULL;
                  lista3->sig = nuevo;
                  lista3 = nuevo;
            }
      }
}