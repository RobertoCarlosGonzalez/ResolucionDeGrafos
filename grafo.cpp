#include "grafo.h"
#include <QInputDialog>

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



/* Este método encuentra el árbol abarcador de costo mínimo de un grafo. En el arreglo VerAux se almacenan los vértices
  con menor costo que van formando el árbol abarcador. */
template <class T>
void GrafoND<T>::Prim()
{
//    cout << "\n------> Prim Algorithm \n\n" ;
    int MCosto[MAX], VerAux[MAX], Ind1, Ind2, VerMen, MenCos;
    // Inicializa el subconjunto de vértices VerAux con el valor del primer vértice.
    for (Ind1=0; Ind1<NumVer; Ind1++)
    {
       MCosto[Ind1]=MatAdy[0][Ind1];
       VerAux[Ind1]=0;
    }
//    cout << "\n   Arcos y costos del arbol abarcador de costo minimo\n";
    int esp1=9;
//    cout << "\n" << setw(esp1)<< "Vertice" << "|" <<setw(esp1)<< "Vertice" << "|" <<setw(esp1)<< "Costo \n";
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
//           cout << "\n " <<setw(esp)<< Vertices[VerMen] << setw(esp)<< "|" << setw(esp) <<  Vertices[VerAux[VerMen]]<< setw(esp) <<"|" << setw(esp) <<  MatAdy[VerMen][VerAux[VerMen]];
        // Se agrega el vértice VerMen a VerAux y se redefinen los costos asociados.
        MCosto[VerMen]=1000;
        for (Ind2=1; Ind2 < NumVer; Ind2++)
           if ((MatAdy[VerMen][Ind2] < MCosto[Ind2]) && MCosto[Ind2] < 1000)
           {
              MCosto[Ind2]=MatAdy[VerMen][Ind2];
              VerAux[Ind2]=VerMen;
           }
    }
    //cout << "\n\n";
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
//    cout << "\n   ---> Kruskal Algorithm " << endl;
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
//    cout << "\n" << setw(espa) << "Vertice" << setw(espa) << "Vertice" << setw(espa) << "Costo" << endl;
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
//          cout << setw(espa) << Vertices[Ver1] << setw(espa) << Vertices[Ver2] << setw(espa) << MatAdy[Ver1][Ver2] << "\n";
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

// <---------------ALGORITMOS DE BUSQUEDA____________________________________>

template <class T>
void GrafoND<T>::Profundidad(int NivelProf){
    int Indice=0, EstadoFinal=0, VisitaAux[MAX], Resp=1, plok, posicion;
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
//	cout << "\n Recorrido del DFS (Deph First Search): ";
//	Visitado.ImprimeIterativo();
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
void GrafoND<T>::VerticesAdyacentes(int VertiDato, Lista<T> *ploks){
    ploks->~Lista();
    for (int Indice=0; Indice < NumVer; Indice++)
       if (MatAdy[VertiDato][Indice] !=0 && MatAdy[VertiDato][Indice] !=999)
            ploks->InsertaFinal(Vertices[Indice]);
}

/* Este método busca una solución (estado final) de un problema representado por medio de un grafo. Visita todos los
   vértices de un mismo nivel antes de pasar al siguiente. Regresa uno si llega al estado meta o cero en caso contrario.
   Se usan atributos de la clase como el número y nombre de los vértices. Además, se declaran tres objetos de la clase
   Lista para almacenar los vértices visitados, los pendientes de visitar y los adyacentes de un nodo dado. */
template <class T>
void GrafoND<T>::Anchura(){
    int Indice, EstadoFinal=0, VisitaAux[MAX], Resp=1, plok, posicion;
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

        ListaAux.ImprimeIterativo();

        if(NoVisitado.vacia()){
            while(!ListaAux.vacia()){
                    Vertix=ListaAux.RegresaPrimero()->RegresaInfo();
                    plok=ListaAux.EliminaPrimero();
                    posicion=BuscaVertice(Vertix);
                    if(!VisitaAux[posicion])
                        NoVisitado.InsertaFinal(Vertix);
                    VisitaAux[posicion]=1;
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
            }
        }
    }
}
