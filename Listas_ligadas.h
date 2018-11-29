#ifndef LISTA_H
#define LISTA_H
// (C) MOVIS
#include <iostream>

using namespace std;

// Definición de la plantilla de la clase NodoLista y de la clase Lista

/* Prototipo de la plantilla de la clase Lista. Así, en la clase NodoLista se
   podrá hacer referencia a ella. */
template <class T>
class Lista;

template <class T>
class NodoLista
{
  private:
     NodoLista<T> * Liga;
     T Info;
     T *punInfo;
  public:
     NodoLista();
     T RegresaInfo();
     T * regresaPunt();
     NodoLista<T> * RegresaLiga();
     ~NodoLista();
     friend class Lista<T>;
};
/* Constructor por omisión. Inicializa con el valor NULL al apuntador al
   siguiente nodo. */
template<class T>
NodoLista<T>::~NodoLista<T>(){
//    cout << " adios puto" << endl;
}
template <class T>
T * NodoLista<T>::regresaPunt()
{
    punInfo=&Info;
    return punInfo;
}

template <class T>
NodoLista<T>* NodoLista<T>::RegresaLiga()
{
    return Liga;
}

template <class T>
NodoLista<T>::NodoLista()
{
   Liga = NULL;
}

/* Método que permite, a los usuarios ajenos a la clase, conocer el valor del
   atributo Info. */
template <class T>
T NodoLista<T>::RegresaInfo()
{
   return Info;
}

// Definición de la clase Lista
template <class T>
class Lista
{
  private:
     NodoLista<T> * Primero;
  public:
     Lista();
     ~Lista();
     NodoLista<T> * RegresaPrimero();
     void CreaInicio();
     void CreaFinal();
     void ImprimeIterativo();
     void ImprimeRecursivo(NodoLista<T> * );
     void ImprimeUnNodo(NodoLista<T> * );
     void InsertaInicio(T);
     void InsertaFinal(T);
     void InsertaOrdenCrec(T);
     int InsertaAntes(T, T);
     int InsertaDespues(T, T);
     int EliminaPrimero();
     int EliminaUltimo();
     int EliminaUnNodo(T);
     int EliminaAnterior(T);
     int EliminaDespues(T);
     int vacia();
     NodoLista<T> * BuscaDesordenada(T);
     NodoLista<T> * BuscaOrdenada(T);
     NodoLista<T> * BuscaRecursivo(T, NodoLista<T> *);
     NodoLista<T> * RegresaSiguiente(); // nuevo metodo
};

template<class T>
int Lista<T>::vacia(){
//    return(Primero);
    if(Primero==NULL){
        return 1;
    }else{
        return 0;
    }
}

template <class T>
NodoLista<T> * Lista<T>::RegresaSiguiente(){
    return Primero->Liga;
}

/* Método constructor. Inicializa el apuntador al primer nodo de la lista con
   el valor NULL: indica lista vacía. */
template <class T>
Lista<T>::Lista()
{
   Primero = NULL;
}

template <class T>
Lista<T>::~Lista(){
    NodoLista<T> *Q;

    while(Primero){
        Q=Primero;
        Primero=Primero->Liga;
        Q->~NodoLista();
    }
}

/* Método que regresa la dirección del primer nodo de la lista. */
template <class T>
NodoLista<T> * Lista<T>::RegresaPrimero()
{
   return Primero;
}

/* Método que crea una lista agregando el nuevo nodo al inicio de la misma. */
template <class T>
void Lista<T>::CreaInicio()
{
   NodoLista<T> * P;
   T Dato;
   char Resp;
   Primero = new NodoLista<T>();
   cout << "Ingresa la informacion a almacenar: \n";
   cin >> Dato;
   Primero->Info = Dato;
   cout<< "\nDeseas ingresar otro elemento (S/N)? ";
   cin>>Resp;
   while (Resp == 'S' || Resp == 's')
   {
      cout<< "Ingresa la información: \n";
      cin>> Dato;
      P = new NodoLista<T>();
      P->Info = Dato;
      P->Liga = Primero;
      Primero = P;
      cout<< "\nDeseas ingresar otro elemento (S/N)? ";
      cin>>Resp;
   }
}

/* Método que crea una lista agregando el nuevo nodo al final de la misma. */
template <class T>
void Lista<T>::CreaFinal()
{
   NodoLista<T> * P, *Ultimo;
   T Dato;
   char Resp;
   Primero = new NodoLista<T>();
   cout<<"Ingresa la información a almacenar: \n";
   cin>>Dato;
   Primero->Info = Dato;
   /* Se mantiene un apuntador al último nodo agregado a la lista para evitar
      tener que recorrerla con cada nuevo nodo. */
   Ultimo = Primero;
   cout<<"\nDeseas ingresar otro elemento (S/N)? ";
   cin>>Resp;
   while (Resp == 'S' || Resp == 's')
   {
      cout<< "\nIngresa la información \n";
      cin>>Dato;
      P = new NodoLista<T>();
      P->Info = Dato;
      Ultimo->Liga = P;
      Ultimo = P;
      cout<< "\nDeseas ingresar otro elemento (S/N)? ";
      cin>>Resp;
   }
}

/* Método que despliega el contenido de la lista iterativamente. */
template <class T>
void Lista<T>::ImprimeIterativo()
{
   NodoLista<T> * P;
   P = Primero;
   if(P==NULL){
    cout << "\n >>> NO hay elemntos registrados <<< " << endl;
   }

   while (P)
   {
      cout<< P->Info << "  ";
      P = P->Liga;
   }
   cout << "\n";
}

/* Método que despliega el contenido de la lista recursivamente. Recibe como
   parámetro el nodo cuya información se va a imprimir. */
template <class T>
void Lista<T>::ImprimeRecursivo(NodoLista<T> * P)
{
   if (P)
   {
      cout<<"\nInformación: "<< P->Info;
      ImprimeRecursivo(P->Liga);
   }
   cout<<'\n';
}

/* Método que imprime la información de un nodo dado como dato. */
template <class T>
void Lista<T>::ImprimeUnNodo(NodoLista<T> * P)
{
   if (P)
      cout<< P->Info;
}

/* Método que inserta un nodo al inicio de la lista. El método es válido tanto
   para listas ya creadas como para listas vacías. */
template <class T>
void Lista<T>::InsertaInicio(T Dato)
{
  NodoLista<T> * P;
  P = new NodoLista<T>();
  P->Info = Dato;
  P->Liga = Primero;
  Primero = P;
}

/* Método que inserta un nodo al final de la lista. El método es válido tanto
   para listas ya creadas como para listas vacías. */
template <class T>
void Lista<T>::InsertaFinal(T Dato)
{
  NodoLista<T> * P, *Ultimo;
  P = new NodoLista<T>();
  P->Info = Dato;
  if (Primero)
  {
     /* Si la lista tiene al menos un elemento, entonces se debe recorrer hasta
        llegar al último nodo. */
     Ultimo = Primero;
     while (Ultimo->Liga)
        Ultimo = Ultimo->Liga;
     // El último nodo de la lista apunta al nuevo nodo, cuya dirección está en P
     Ultimo->Liga = P;
  }
  else
     /* Si la lista no tiene elementos, entonces el nuevo elemento será el
        primero de la misma. */
     Primero = P;
}

/* Método que inserta un nodo en orden creciente. Luego de varias inserciones,
  usando este método, se habrá generado una lista ordenada de menor a mayor. */
template <class T>
void Lista<T>::InsertaOrdenCrec(T Dato)
{
   NodoLista<T> * P, *Q, *Ant;
   if (!Primero || Dato < Primero->Info )
      InsertaInicio(Dato);
   else
   {
      Q = Primero;
      while (Q && Q->Info < Dato)
      {
         Ant= Q;
         Q = Q->Liga;
      }
      P = new NodoLista<T>();
      P->Info = Dato;
      Ant->Liga = P;
      P->Liga = Q;
   }
}

/* Método que inserta un nodo antes de un nodo dado como referencia. Recibe como
   parámetros la información a insertar y un dato dado como referencia. Regresa
   1 si se pudo insertar, 0 si no se encontró la referencia y –1 si la lista
   está vacía. */
template <class T>
int Lista<T>::InsertaAntes(T Dato, T Ref)
{
   NodoLista<T> * P, *Ant, *Q;
   int Resp = 1;
   if (Primero)
   {
      Q = Primero;
      while ((Q != NULL ) && (Q->Info != Ref))
      {
         Ant = Q;
         Q = Q->Liga;
      }
      if (Q != NULL )
      {
         P = new NodoLista<T>();
         P->Info = Dato;
         // El dato de referencia es el primero de la lista.
         if (Primero == Q)
         {
            P->Liga = Primero;
            Primero = P;
         }
         else
         {
            Ant->Liga = P;
            P->Liga = Q;
         }
      }
      else
         // No se encontró el dato dado como referencia
         Resp = 0;
   }
   else
      // La lista está vacía
      Resp = -1;
   return Resp;
}

/* Método que inserta un nodo después de uno dado como referencia. Recibe como
   parámetros la información a insertar y la referencia. Regresa 1 si se pudo
   insertar, 0 si no se encontró el dato dado y –1 si la lista está vacía. */
template <class T>
int Lista<T>::InsertaDespues(T Dato, T Ref)
{
   NodoLista<T> * Q, *P;
   int Resp = 1;
   if (Primero)
   {
      Q = Primero;
      while ((Q != NULL ) && (Q->Info != Ref))
         Q = Q->Liga;
      if ( Q != NULL )
      {
         P = new NodoLista<T>();
         P->Info = Dato;
         P->Liga = Q->Liga;
         Q->Liga = P;
      }
      else
         // No se encontró la referencia
         Resp = 0;
   }
   else
      // La lista está vacía
      Resp = -1;
   return Resp;
}

/* Método que elimina el primer elemento de la lista. El método redefine el
  apuntador al inicio de la lista y libera el espacio de memoria del nodo
  eliminado. Regresa 1 si se pudo llevar a cabo la operación y 0 en caso
  contrario. */
template <class T>
int Lista<T>::EliminaPrimero()
{
   NodoLista<T> * P;
   int Resp = 1;
   if (Primero)
   {
      P = Primero;
      Primero = P->Liga;
      P->~NodoLista();
   }
   else
      Resp = 0;

   return Resp;
}

/* Método que elimina el último elemento de una lista. Primero lo localiza,
  guardando la dirección del nodo que le precede. Posteriormente redefine la
  liga de éste con el valor de NULL para indicar que ahora éste es el último y
  libera el espacio de memoria. Regresa 1 si se pudo llevar a cabo la eliminación
  y 0 en caso contrario. */
template <class T>
int Lista<T>::EliminaUltimo()
{
   NodoLista<T> * Ant, *P;
   int Resp = 1;
   if (Primero)
   {
      /* Verifica si la lista está formada por un único elemento, en tal caso
         redefine el puntero al inicio con el valor de NULL, indicando lista vacía. */
      if (!Primero->Liga)
      {
         delete (Primero);
         Primero = NULL;
      }
      else
      {
         P = Primero;
         while (P->Liga)
         {
            Ant = P;
            P = P->Liga;
         }
         Ant->Liga = NULL;
         delete (P);
      }
   }
   else
      // La lista está vacía
      Resp = 0;
   return Resp;
}

/* Método que elimina un nodo que almacena cierta información. Recibe como
   parámetro el dato a eliminar y regresa como resultado 1 si lo elimina, 0 si
   no lo encuentra y –1 si la lista está vacía. */
template <class T>
int Lista<T>::EliminaUnNodo(T Ref)
{
   NodoLista<T> * P, *Ant;
   int Resp = 1;
   if (Primero)
   {
      P = Primero;
      while ((P->Liga) && (P->Info != Ref))
      {
         Ant = P;
         P = P->Liga;
      }
      if (P->Info != Ref)
         // El elemento no fue encontrado
         Resp = 0;
      else
      {
         if (Primero == P)
            Primero = P->Liga;
         else
            Ant->Liga = P->Liga;
         delete (P);
      }
   }
   else
      Resp = -1;
   return Resp;
}

/* Método que elimina el nodo anterior al nodo que almacena un dato dado como
   referencia. Regresa 1 si el nodo fue eliminado, 2 si la referencia es el
   primero, 3 si no fue encontrado y 4 si la lista está vacía. */
template <class T>
int Lista<T>::EliminaAnterior(T Ref)
{
   NodoLista<T> * Q, *Ant, *P;
   int Resp= 1;
   if (Primero)
   {
      if (Primero->Info == Ref)
      // No hay nodo que preceda al dado como referencia.
      Resp= 2;
   else
   {
      Q = Primero;
      Ant = Primero;
      /* Ciclo que permite encontrar la información dada como referencia,
         guardando la dirección del nodo que le precede (nodo que se eliminará)
         y del anterior a éste para establecer las ligas correspondientes. */
      while ((Q->Info != Ref) && (Q->Liga))
      {
         P = Ant;
         Ant = Q;
         Q = Q->Liga;
      }
      if (Q->Info != Ref)
      // El elemento dado como referencia no está en la lista.
         Resp = 3;
      else
         if (Primero->Liga == Q)
         {
            delete (Primero);
            Primero = Q;
         }
         else
         {
            P->Liga = Q;
            delete (Ant);
         }
      }
   }
   else
   // La lista está vacía
      Resp = 4;
   return Resp;
}

/* Método que busca un elemento dado referencia en una lista desordenada. Regresa
   la dirección del nodo si lo encuentra y NULL en caso contrario. */
template <class T>
NodoLista<T> * Lista<T>::BuscaDesordenada(T Ref)
{
   NodoLista<T> * Q, *Resp= NULL;
   if (Primero)
   {
      Q = Primero;
      while ((Q->Info != Ref) && (Q->Liga))
         Q = Q->Liga;
      // Se verifica si el elemento dado como referencia fue encontrado en la lista
      if (Q->Info == Ref)
         Resp = Q;
   }
   return Resp;
}

/* Método que busca un elemento dado como referencia, en una lista ordenada de
   menor a mayor. Regresa la dirección del nodo si lo encuentra y NULL en caso
   contrario. */
template <class T>
NodoLista<T> * Lista<T>::BuscaOrdenada(T Ref)
{
   NodoLista<T> * Q, *Resp= NULL;
   if (Primero)
   {
      Q = Primero;
      while ((Q->Info < Ref) && (Q->Liga))
         Q = Q->Liga;
      // Se verifica si el elemento dado como referencia fue encontrado en la lista
      if (Q->Info == Ref)
         Resp = Q;
   }
   return Resp;
}

/* Método que busca un dato en la lista. La operación se realiza recursivamente.
   El método recibe como parámetro el elemento a buscar ( Dato) y una variable
   ( Q) que almacena la dirección de un nodo (la primera vez es la dirección del
   primero). Regresa como resultado la dirección del nodo si lo encuentra y NULL
   en caso contrario. */
template <class T>
NodoLista<T> * Lista<T>::BuscaRecursivo(T Dato, NodoLista<T> * Q)
{
   if (Q)
      if (Q->Info == Dato)
         return Q;
      else
         return BuscaRecursivo(Dato, Q->Liga);
   else
      return NULL;
}

#endif // LISTA_H
