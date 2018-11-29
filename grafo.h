#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <iomanip>
#include <QDebug>
#include <QString>
#include "Listas_ligadas.h"

#define MAX 20

using namespace std;


/* Definición de la plantilla de la clase GrafoND. Se incluyen como atributos el total de vértices (NumVer),
   los costos/distancias entre los vértices (MatAdy) y sus nombres (Vertices).
*/
template<class T>
class GrafoND
{
   public:
      T MatAdy[MAX][MAX];
      QString Prim_string, Kruskal_string, Anchura_string, Profundidad_string;
      int NumVer, Vertices[MAX], cont, cont2, aristas;

   public:
      // Método constructor y métodos auxiliares para leerla información relacionada al grafo e
      // imprimir los resultados que se obtienen con los demás métodos
      GrafoND();
      void Lee();

      void set_cont(int);
      int get_cont();
      void set_cont2(int);
      int get_cont2();
      void set_aristas(int);
      int get_aristas();
      void set_NumVer(int);
      int get_NumVer();

      int Maximo(int,int);
      int Minimo(int,int);
      void set_Vertices(int,int);
      void set_Matriz_grafo(int,int,int);
      void Imprime(int);
      void graph_default();

//    Métodos que permiten el cálculo del árbol de costo mínimo.
      void Profundidad(int);
      void set_profundidad(QString,QString);
      QString get_profundidad();

      int BuscaVertice(T);
      void Vertices_Adyacentes(int, Lista<T>*);
      int Anchura();
      void set_anchura(QString,QString);
      QString get_anchura();

      void Prim();
      void set_Imprime_Prim(QString,QString);
      QString get_Imprime_Prim();

      void Kruskal();
      void set_Imprime_kruskal(QString,QString);
      QString get_Imprime_kruskal();



/*
      void Warshall();
      void set_Imprime_Warshall(QString,QString);
      QString get_Imprime_Warshall();

      void Floyd();
      void set_Imprime_Floyd(QString,QString);
      QString get_Imprime_Floyd();

      void FloydVerInt();
      void set_FloydVerInt(QString,QString);
      QString get_ImprimeFloydVerInt();

      int Dijkstra();
      void set_Dijkstra(QString,QString);
      QString get_Dijkstra();

*/
};


template <class T>
void GrafoND<T>::set_cont(int _cont){
    cont = _cont;
}

template <class T>
int GrafoND<T>::get_cont(){
    return cont;
}

template <class T>
void GrafoND<T>::set_cont2(int _cont){
    cont2 = _cont;
}

template <class T>
int GrafoND<T>::get_cont2(){
    return cont2;
}

template <class T>
void GrafoND<T>::set_aristas(int _aristas){
    aristas = _aristas;
}

template <class T>
void GrafoND<T>::set_NumVer(int _numVer){
    NumVer = _numVer;
}

template <class T>
void GrafoND<T>::set_Vertices(int cont, int _vertice){
    Vertices[cont]= _vertice;
}

template <class T>
int GrafoND<T>::get_NumVer(){
    return NumVer;
}

template <class T>
int GrafoND<T>::get_aristas(){
    return aristas;
}



template <class T>
void GrafoND<T>::set_Matriz_grafo(int Origen, int Destino, int Costo){
    MatAdy[Origen-1][Destino-1]=Costo;
    MatAdy[Destino-1][Origen-1]=Costo;
}

// Método constructor. Inicializa el número de vértices en cero y la matriz de distancias con un valor arbitrario
// muy grande (999), excepto en la diagonal principal, donde el costo es cero.
template<class T>
GrafoND<T>::GrafoND()
{
    cont = 0;
    cont2 = 0;
    int Ind1, Ind2;
    for (Ind1=0; Ind1<MAX; Ind1++)
       for (Ind2=0; Ind2<MAX; Ind2++)
          if (Ind1 != Ind2)
             MatAdy[Ind1][Ind2]=999;
          else
             MatAdy[Ind1][Ind2]=0;
    NumVer=0;
}
template <class T>
void GrafoND<T>::graph_default(){
    NumVer=6;
    for(int i=0; i<NumVer; i++)
        Vertices[i]=i+1;

    MatAdy[1 -1][2 -1]= 3;
    MatAdy[1 -1][5 -1]= 2;
    MatAdy[1 -1][6 -1]= 5;
    MatAdy[2 -1][6 -1]= 3;
    MatAdy[2 -1][3 -1]= 1;
    MatAdy[3 -1][4 -1]= 3;
    MatAdy[3 -1][6 -1]= 2;
    MatAdy[5 -1][4 -1]= 2;
    MatAdy[6 -1][5 -1]= 3;

    MatAdy[2 -1][1 -1]= 3;
    MatAdy[5 -1][1 -1]= 2;
    MatAdy[6 -1][1 -1]= 5;
    MatAdy[6 -1][2 -1]= 3;
    MatAdy[3 -1][2 -1]= 1;
    MatAdy[4 -1][3 -1]= 3;
    MatAdy[6 -1][3 -1]= 2;
    MatAdy[4 -1][5 -1]= 2;
    MatAdy[5 -1][6 -1]= 3;
}

/* Método que lee del teclado la información de la gráfica. En esta solución el nombre de los vértices
   sólo pueden ser valores enteros. */
template <class T>
void GrafoND<T>::Lee()
{
    int Aristas, Costo, Ind1, Origen, Destino;
    cout << "\n\nIngresa el total de vertices del grafo: ";
    cin >> NumVer;
    for (Ind1=0; Ind1 < NumVer; Ind1++)
    {
       cout << "\nIngresa el nombre del vertice: ";
       cin >> Vertices[Ind1];
    }
    cout << "\n\nIngresa el total de aristas del grafo: ";
    cin >> Aristas;
    Ind1=0;
    while (Ind1 < Aristas)
    {
       cout << "”\nVertice origen: ";
       cin >> Origen;
       cout << "\nVertice destino: ";
       cin >> Destino;
       cout << "\nCosto de ir de " << Origen << " a " << Destino << " : ";
       cin >> Costo;
       MatAdy[Origen-1][Destino-1]=Costo;
       MatAdy[Destino-1][Origen-1]=Costo;
       Ind1++;
    }
}

template <class T>
void GrafoND<T>::Profundidad(int NivelProf){
    int Indice=0, VisitaAux[MAX], plok, posicion;
    Lista<T> Visitado, NoVisitado, ListaAux;
    T Vertix;

    for (Indice=0; Indice < NumVer; Indice++)
       VisitaAux[Indice]=0;

    /* Se guarda el primer vértice (representa el estado inicial) del grafo en la lista NoVisitado. */
    NoVisitado.InsertaFinal(Vertices[0]);

    /* En el arreglo auxiliar VisitaAux se indica que el primer vértice ya fue visitado, para evitar caer en ciclos. */
    VisitaAux[0]=1;

    while (Indice <= NivelProf){
        Indice++;

        Vertix=NoVisitado.RegresaPrimero()->RegresaInfo();
        plok=NoVisitado.EliminaPrimero();

        Visitado.InsertaFinal(Vertix);
        posicion=BuscaVertice(Vertix);
        VisitaAux[posicion]=1;

        VerticesAdyacentes(posicion, &ListaAux);

        cout << "\n Vertice [ " << Vertix << " ] lista adyaciencia: ";
        ListaAux.ImprimeIterativo();

        if(NoVisitado.vacia()){
            while(!ListaAux.vacia()){
                    Vertix=ListaAux.RegresaPrimero()->RegresaInfo();
                    plok=ListaAux.EliminaPrimero();
                    if(!VisitaAux[BuscaVertice(Vertix)])
                        NoVisitado.InsertaFinal(Vertix);
                    //NoVisitado.ImprimeIterativo();
            }
        }
        else
        {
            T VerticeBan=NoVisitado.RegresaPrimero()->RegresaInfo(), repetido;
            while(!ListaAux.vacia()){
                Vertix=ListaAux.RegresaPrimero()->RegresaInfo();
                plok=ListaAux.EliminaPrimero();
                if(!VisitaAux[BuscaVertice(Vertix)]){
//                    if(Vertix == VerticeBan && ListaAux.RegresaPrimero()){

                    if(Vertix == VerticeBan && !ListaAux.vacia()){
                        repetido=Vertix;
                        Vertix=ListaAux.RegresaPrimero()->RegresaInfo();
                        plok=ListaAux.EliminaPrimero();
                        NoVisitado.InsertaAntes(Vertix, VerticeBan);
                        NoVisitado.InsertaAntes(repetido, Vertix);
                    }
                    else
                    {
                        NoVisitado.InsertaAntes(Vertix, VerticeBan);
                    }
//                        NoVisitado.InsertaAntes(Vertix, VerticeBan);
                }
                //NoVisitado.ImprimeIterativo();
            }
        }
    }
    qDebug() << "\n PROFUNDIDA: ";
    Visitado.ImprimeIterativo();
}

/* Métopdo entero que determina si un vértice dado como parámetro es o no un vértice del grafo. Regresa la
   posición en la que lo encuentra o un negativo. */
template <class T>
int GrafoND<T>::BuscaVertice(T VertiDato){
    int Indice=0, Resp=-1;

    // Busca el nombre del vértice dado en el arreglo que guarda los nombres de todos los vértices del grafo
    while (Indice < NumVer && Vertices[Indice] != VertiDato)
       Indice++;
    if (Indice < NumVer)
       Resp=Indice;
    return Resp;
}

/* Método que genera una lista con los vértices adyacentes de un vértice dado como parámetro. Recibe como parámetro
   el nombre de un vértice y da como resultado una lista con sus vértices adyacentes. */
template <class T>
void GrafoND<T>::Vertices_Adyacentes(int VertiDato, Lista<T> *ploks){
    ploks->~Lista();
    for (int Indice=0; Indice < NumVer; Indice++)
       if (MatAdy[VertiDato][Indice] !=0 && MatAdy[VertiDato][Indice] !=999)
            ploks->InsertaFinal(Vertices[Indice]);
}

template <class T>
int GrafoND<T>::Anchura(){
    int Indice, VisitaAux[MAX], plok, posicion;
    Lista<T> NoVisitado, Visitado, ListaAux, cont;
    T Vertix;

    // El arreglo VisitaAux es un arreglo en el cual se indica si un nodo ya fue expandido.
    for (Indice=0; Indice < NumVer; Indice++)
       VisitaAux[Indice]=0;

    // Se guarda el primer vértice del grafo en la lista NoVisitado
    NoVisitado.InsertaFinal(Vertices[0]);
    VisitaAux[0] =1;

    while (!NoVisitado.vacia()){

        Vertix=NoVisitado.RegresaPrimero()->RegresaInfo();
        plok=NoVisitado.EliminaPrimero();

        Visitado.InsertaFinal(Vertix);
        posicion=BuscaVertice(Vertix);

        VerticesAdyacentes(posicion, &ListaAux);

        qDebug() << "\n Vertice [ " << Vertix << " ] lista adyaciencia: ";
        ListaAux.ImprimeIterativo();

        if(NoVisitado.vacia()){
            while(!ListaAux.vacia()){
                    Vertix=ListaAux.RegresaPrimero()->RegresaInfo();
                    plok=ListaAux.EliminaPrimero();
                    posicion=BuscaVertice(Vertix);
                    if(!VisitaAux[posicion])
                        NoVisitado.InsertaFinal(Vertix);
                    VisitaAux[posicion]=1;
                    //NoVisitado.ImprimeIterativo();
            }
        }
        else
        {
            T VerticeBan=NoVisitado.RegresaPrimero()->RegresaInfo(), repetido;
            while(!ListaAux.vacia()){
                Vertix=ListaAux.RegresaPrimero()->RegresaInfo();
                plok=ListaAux.EliminaPrimero();
                posicion=BuscaVertice(Vertix);
                if(!VisitaAux[posicion])
                    NoVisitado.InsertaFinal(Vertix);
                VisitaAux[posicion]=1;
                //NoVisitado.ImprimeIterativo();
            }
        }
    }
    qDebug() << "\n ANCHURA: ";
//    Visitado.ImprimeIterativo();
}

template <class T>
void GrafoND<T>::set_anchura(QString info1, QString info2){
    Anchura_string = info1 + " " + info2;
}

template <class T>
QString GrafoND<T>::get_anchura(){
    return Anchura_string;
}


/* Este método encuentra el árbol abarcador de costo mínimo de un grafo. En el arreglo VerAux se almacenan los vértices
  con menor costo que van formando el árbol abarcador. */
template <class T>
void GrafoND<T>::Prim()
{
    qDebug() << "\n------> Prim Algorithm \n\n" ;

    //DEclaracion de qstring
    QString titulo,vertices_letras,vertices="", VERTI, VERTI2, MAT_ADY;
    titulo = "\n------> Prim Algorithm \n\n" ;
    vertices_letras = titulo + "\n\n Vertice | Vertice | Costo\n   Arcos y costos del arbol abarcador de costo minimo\n" ;

    int MCosto[MAX], VerAux[MAX], Ind1, Ind2, VerMen, MenCos;
    // Inicializa el subconjunto de vértices VerAux con el valor del primer vértice.
    for (Ind1=0; Ind1<NumVer; Ind1++)
    {
       MCosto[Ind1]=MatAdy[0][Ind1];
       VerAux[Ind1]=0;
    }
    qDebug() << "\n   Arcos y costos del arbol abarcador de costo minimo\n";

    qDebug() << "\n" << "Vertice" << "|" << "Vertice" << "|" << "Costo \n";
    // Encuentra el vértice VerMen en (Vertices - VerAux) tal que el costo de ir de dicho vértice a uno de VerAux sea mínimo.
    for (Ind1=0; Ind1 < NumVer-1; Ind1++)
    {
       MenCos=MCosto[1];
       VerMen=1;
       for (Ind2=2; Ind2 < NumVer; Ind2++)
          if (MCosto[Ind2] < MenCos)
          {
             MenCos=MCosto[Ind2];
             VerMen=Ind2;
          }

        qDebug() << "\n " << Vertices[VerMen] << "|"  <<  Vertices[VerAux[VerMen]]<<"|" <<  MatAdy[VerMen][VerAux[VerMen]];

        //CONVERCION DE LOS NUMEROS A CADENAS
        VERTI = QString::number(Vertices[VerMen]);
        VERTI2 = QString::number(Vertices[VerAux[VerMen]]);
        MAT_ADY = QString::number(MatAdy[VerMen][VerAux[VerMen]]);

        vertices = vertices + "\n" + VERTI + "|" + VERTI2 + "|" + MAT_ADY;

        //ENVIAR LA CADENA PARA QUE SE JUNTE
        set_Imprime_Prim(vertices_letras,vertices);

        // Se agrega el vértice VerMen a VerAux y se redefinen los costos asociados.
        MCosto[VerMen]=1000;
        for (Ind2=1; Ind2 < NumVer; Ind2++)
           if ((MatAdy[VerMen][Ind2] < MCosto[Ind2]) && MCosto[Ind2] < 1000)
           {
              MCosto[Ind2]=MatAdy[VerMen][Ind2];
              VerAux[Ind2]=VerMen;
           }
    }
    cout << "\n\n";
}

template <class T>
void GrafoND<T>::set_Imprime_Prim(QString info1, QString info2){
    Prim_string = info1 + " " + info2;
}

template <class T>
QString GrafoND<T>::get_Imprime_Prim(){
    return Prim_string;
}


// Función auxiliar que obtiene el valor más pequeño de dos dados como parámetros. La utiliza el método de Kruskal.

template<class T>
int GrafoND<T>::Minimo (int Val1, int Val2)
{
    int Min= Val1;
    if (Val2 < Min)
      Min=Val2;
    return Min;
}

// Función auxiliar que obtiene el valor más grande de dos dados como parámetros. La utiliza el método de Kruskal.
template <class T>
int GrafoND<T>::Maximo (int Val1, int Val2)
{
    int Max= Val1;
    if (Val2 > Max)
       Max= Val2;
    return Max;
}

// Este método encuentra el árbol abarcador de costo mínimo de un grafo.
template <class T>
void GrafoND<T>::Kruskal()
{
    cout << "\n   ---> Kruskal Algorithm " << endl;
    /* El arreglo auxiliar ArisCosto[][] almacena en cada renglón los datos de una arista: vértices adyacentes y costo.
       El arreglo Partic[] almacena particiones de Vertices. Inicialmente Partic= {{1},{2},...,{NumVer}}. */
    int ArisCosto[2*MAX][3], Partic[MAX], Ind1, Ind2, Ver1, Ver2, TotAris, Menor, Mayor, Band;

    // Inicializa Partic[].
    for (Ind1=0; Ind1 < NumVer; Ind1++)
       Partic[Ind1]=Ind1;

    // Inicializa ArisCosto[][]
    Ver1=0;
    Ver2=0;
    TotAris=0;
    for (Ind1=0; Ind1 < NumVer; Ind1++)
       for (Ind2=Ind1; Ind2 < NumVer; Ind2++)
          if (MatAdy[Ind1][Ind2] != 0 && MatAdy[Ind1][Ind2] != 999)
          {
             ArisCosto[Ver1][Ver2++]=Ind1;
             ArisCosto[Ver1][Ver2++]=Ind2;
             ArisCosto[Ver1++][Ver2]=MatAdy[Ind1][Ind2];
             Ver2=0;
             TotAris++;
          }
    // Ciclo en el cual se seleccionan aristas y se agregan los vértices mientras existan vértices en Partic que
    // se encuentren en distintas particiones.
    Band=0;
    qDebug() << "\n"  << "Vertice | "  << "Vertice | "  << "Costo" << endl;

//  DECLARACION DE LOS STRING
    QString titulo,vertices_letras,vertices="", VERTI, VERTI2, MAT_ADY;
    titulo = "\n------> Kruskal Algorithm \n\n" ;
    vertices_letras = titulo + "\n\n Vertice | Vertice | Costo\n   Arcos y costos del arbol abarcador de costo minimo\n" ;

    while (Band != 1)
    {
       // Se selecciona la arista de menor costo.
       Menor=999;
       for (Ind1=0; Ind1 < TotAris; Ind1++)
          if (ArisCosto[Ind1][2] < Menor)
          {
             Ver1=ArisCosto[Ind1][0];
             Ver2=ArisCosto[Ind1][1];
             Menor=ArisCosto[Ind1][2];
             Ind2=Ind1;
          }
       // Se elimina la arista de menor costo de la matriz ArisCosto.
       ArisCosto[Ind2][2]=999;
       // Se verifica que la arista (Ver1, Ver2) una dos vértices que pertenecen a particiones diferentes.
       if (Partic[Ver1] != Partic[Ver2])
       {
          qDebug() << Vertices[Ver1]  << Vertices[Ver2]  << MatAdy[Ver1][Ver2] << "\n";
//            CONVERCION DE LOS NUMEROS A CADENAS
          VERTI = QString::number(Vertices[Ver1]);
          VERTI2 = QString::number(Vertices[Ver2]);
          MAT_ADY = QString::number(MatAdy[Ver1][Ver2]);

          vertices = vertices + "\n" + VERTI + "|" + VERTI2 + "|" + MAT_ADY;

//            ENVIAR LA CADENA PARA QUE SE JUNTE
          set_Imprime_kruskal(vertices_letras,vertices);

              Mayor=Maximo(Partic[Ver1], Partic[Ver2]);
          for (Ind1=0; Ind1 < NumVer; Ind1++)
             if (Ind1 == Ver1 || Ind1 == Ver2 || Partic[Ind1] == Mayor)
                Partic[Ind1]=Minimo(Partic[Ver1], Partic[Ver2]);
       }

       // Ciclo para determinar si quedan vértices en particiones diferentes.
       Ind1=0;
       while (Ind1 < NumVer && !Band)
       {
          if (Partic[Ind1] != 0)
             Band=1;
          Ind1++;
       }
       // Si existen particiones en Partic se debe seguir con el proceso.
       Band=!Band;
    }

}

template <class T>
void GrafoND<T>::set_Imprime_kruskal(QString info1, QString info2){
    Kruskal_string = info1 + " " + info2;
}

template <class T>
QString GrafoND<T>::get_Imprime_kruskal(){
    return Kruskal_string;
}



#endif // GRAFO_H
