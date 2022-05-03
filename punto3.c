#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarea{
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
}typedef Tarea;

struct Nodo{
Tarea T;
Nodo *Siguiente;
}typedef Nodo;

// Declaración de funciones
Nodo* insertar(Nodo* head, Tarea T);
Nodo* borrarPrimerNodo(Nodo* head);
Nodo* borrarNodo(Nodo* head, int ID);
void insertarNodo(Nodo** head, Nodo* nuevoNodo);
void desapuntarNodo(Nodo** head, Nodo* N);
void mostrarTotales(Nodo* head);
void mostrarTarea(Tarea t);
Nodo* busquedaPorId(Nodo* head, int ID);
Nodo* busquedaPorPalabra(Nodo* head, char *palabra);

int main(){
    Nodo * realizadas=NULL;
    Nodo * pendientes=NULL;
    int cantEncargos;

    printf("Ingrese la cantidad de tareas que cargara\n");
    scanf("%d",&cantEncargos);
    fflush(stdin);
    pendientes= (Tarea*)malloc(cantEncargos * sizeof(Tarea));
    realizadas= (Tarea*)malloc(cantEncargos * sizeof(Tarea));
    return 0;
}

