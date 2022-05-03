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
Nodo* insertar(Nodo* cabecera, Tarea T);
Nodo* borrarNodo(Nodo* cabecera, int ID);
void mostrarTotales(Nodo* cabecera);
void mostrarTarea(Tarea t);
Nodo* busquedaPorId(Nodo* cabecera, int ID);
Nodo* busquedaPorPalabra(Nodo* cabecera, char *clave);

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

Nodo* insertar(Nodo* cabecera, Tarea T){
    Nodo* nuevoNodo;

    nuevoNodo = (Nodo*) malloc(sizeof(struct Nodo));
    nuevoNodo->T = T;
    nuevoNodo->Siguiente = cabecera;
    cabecera=nuevoNodo;
    return cabecera;
}

Nodo* borrarNodo(Nodo* cabecera, int ID){
    if (cabecera== NULL)
    {
        return cabecera;
    }
    Nodo* aux=cabecera;
    if (cabecera->Siguiente==NULL)
    {
        if (cabecera->Siguiente->T.TareaID == ID)
        {
            free(cabecera->Siguiente);
            cabecera= NULL;
            return cabecera;
        }
    }
    while (cabecera->Siguiente != NULL)
    {
        if (cabecera->Siguiente->T.TareaID == ID)
        {
            Nodo * elimina;
            elimina= cabecera->Siguiente;
            cabecera->Siguiente= cabecera->Siguiente->Siguiente;
            free(elimina);
        }
        cabecera= cabecera->Siguiente;
    }
    return aux;
}

