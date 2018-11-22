#ifndef GRAFO_H
#define GRAFO_H
#define MAX 20

#include <QMainWindow>
#include <QObject>
#include <QWidget>

template <class T>
class GrafoND
{
public:
   T MatAdy[MAX][MAX];
   int NumVer, Vertices[MAX];
public:
   // Método constructor y métodos auxiliares para leerla información relacionada al grafo e
   // imprimir los resultados que se obtienen con los demás métodos
   GrafoND();
   void Lee();
   void Imprime(int);
   void graph_default();

   // Métodos que permiten el cálculo del árbol de costo mínimo.
   void Prim();
   void Kruskal();
};

void Minimo();
void Maximo();

#endif // GRAFO_H
