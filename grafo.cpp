#include "grafo.h"
#include <QInputDialog>


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

// Método constructor. Inicializa el número de vértices en cero y la matriz de distancias con un valor arbitrario
// muy grande (999), excepto en la diagonal principal, donde el costo es cero.
template<class T>
GrafoND<T>::GrafoND()
{
    int Ind1, Ind2;
    for (Ind1=0; Ind1<MAX; Ind1++)
       for (Ind2=0; Ind2<MAX; Ind2++)
          if (Ind1 != Ind2)
             MatAdy[Ind1][Ind2]=999;
          else
             MatAdy[Ind1][Ind2]=0;
    NumVer=0;
}

/* Método que lee del teclado la información de la gráfica. En esta solución el nombre de los vértices
   sólo pueden ser valores enteros. */


/* Este método encuentra el árbol abarcador de costo mínimo de un grafo. En el arreglo VerAux se almacenan los vértices
  con menor costo que van formando el árbol abarcador. */
template <class T>
void GrafoND<T>::Prim()
{
   /*IMPRIME ALGORITMO PRIM COUT cout << "\n------> Prim Algorithm \n\n" ;*/
    int MCosto[MAX], VerAux[MAX], Ind1, Ind2, VerMen, MenCos;
    // Inicializa el subconjunto de vértices VerAux con el valor del primer vértice.
    for (Ind1=0; Ind1<NumVer; Ind1++)
    {
       MCosto[Ind1]=MatAdy[0][Ind1];
       VerAux[Ind1]=0;
    }
    /* TITULO D ARBOL Y COSTOS DE EL MISMO GRAFO*/
    int esp1=9;
/*
 * cout << "\n" << setw(esp1)<< "Vertice" << "|" <<setw(esp1)<< "Vertice" << "|" <<setw(esp1)<< "Costo \n";*/
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
          int esp=4;
  /*
   *       cout << "\n " <<setw(esp)<< Vertices[VerMen] << setw(esp)<< "|" << setw(esp) <<  Vertices[VerAux[VerMen]]<< setw(esp) <<"|" << setw(esp) <<  MatAdy[VerMen][VerAux[VerMen]];

 */     // Se agrega el vértice VerMen a VerAux y se redefinen los costos asociados.
        MCosto[VerMen]=1000;
        for (Ind2=1; Ind2 < NumVer; Ind2++)
           if ((MatAdy[VerMen][Ind2] < MCosto[Ind2]) && MCosto[Ind2] < 1000)
           {
              MCosto[Ind2]=MatAdy[VerMen][Ind2];
              VerAux[Ind2]=VerMen;
           }
    }
/*
 * SALTOS DE LINEA
 * 	cout << "\n\n";
 */

}

// Función auxiliar que obtiene el valor más pequeño de dos dados como parámetros. La utiliza el método de Kruskal.
int Minimo (int Val1, int Val2)
{
    int Min= Val1;
    if (Val2 < Min)
      Min=Val2;
    return Min;
}

// Función auxiliar que obtiene el valor más grande de dos dados como parámetros. La utiliza el método de Kruskal.
int Maximo (int Val1, int Val2)
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
/*
 *
 *     cout << "\n   ---> Kruskal Algorithm " << endl;

*/
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
    int espa=10;
/*
 *
 *    cout << "\n" << setw(espa) << "Vertice" << setw(espa) << "Vertice" << setw(espa) << "Costo" << endl;

*/ while (Band != 1)
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
/*
 *
 *         cout << setw(espa) << Vertices[Ver1] << setw(espa) << Vertices[Ver2] << setw(espa) << MatAdy[Ver1][Ver2] << "\n";

*/        Mayor=Maximo(Partic[Ver1], Partic[Ver2]);
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
