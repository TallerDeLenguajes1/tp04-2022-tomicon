#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
} typedef tarea;

void mostrarTareas(tarea* listaTareas);
tarea * BusquedaPorPalabra(tarea ** listaTareas, int cantTareas, char * palabraClave);
tarea * BusquedaPorId(tarea ** listaTareas, int cantTareas, int id);

int main(){
    tarea **encargos;
    tarea **realizadas;
    int cantEncargos;

    printf("Ingrese la cantidad de tareas que cargara\n");
    scanf("%d",&cantEncargos);
    fflush(stdin);
    encargos= (tarea**)malloc(cantEncargos * sizeof(tarea*));
    realizadas= (tarea**)malloc(cantEncargos * sizeof(tarea*));
    for (int i = 0; i < cantEncargos; i++)
    {
        encargos[i]= (tarea *)malloc(sizeof(tarea));    //reservo memoria para las tareas pendientes
        encargos[i]->Descripcion= (char*)malloc(501);
        realizadas[i]= (tarea *)malloc(sizeof(tarea));  //reservo memoria para las tareas realizadas
        realizadas[i]->Descripcion= (char*)malloc(501);               
        printf("Ingrese el id de la tarea: ");
        scanf("%d",&(encargos[i]->TareaID));
        fflush(stdin);
        printf("Agregue una breve descripcion de la tarea (tiene 500 caracteres): ");
        gets(encargos[i]->Descripcion);
        do
        {
            printf("Que duracion tendra la tarea? (recuerde que debe ingresar un valor entre 10 y 100): ");
            scanf("%d",&(encargos[i]->Duracion));
            fflush(stdin);
        } while (encargos[i]->Duracion > 100 || encargos[i]->Duracion < 10);
    }
    int confirmar= 0;
    for (int i = 0; i < cantEncargos; i++)    //for para confirmar si las tareas han sido realizadas
    {
        printf("Si ya se ha realizado la tarea numero %d, ingrese un 1, sino ingrese cualquier otro numero: ", encargos[i]->TareaID);
        scanf("%d",&confirmar);
        fflush(stdin);
        if (confirmar == 1)
        {
            realizadas[i]= encargos[i];
            encargos[i]= NULL;
            confirmar= 0;
        } else
        {
            realizadas[i]= NULL;
        }
    }
    for (int i = 0; i < cantEncargos; i++)  //for para mostrar tareas realizadas
    {
        if (realizadas[i] != NULL)
        {
            printf("Tarea realizada:\n");
            mostrarTareas(realizadas[i]);
        }
    }
    for (int i = 0; i < cantEncargos; i++)  //for para mostrar tareas pendientes
    {
        if (encargos[i] != NULL)
        {
            printf("Tarea pendiente:\n");
            mostrarTareas(encargos[i]);
        }
    }
    char clave[500];
    printf("ingrese la palabra clave: \n");
    gets(clave);
    int idBuscado;
    printf("ingrese el id de la tarea que busca: ");
    scanf("%d", &idBuscado);
    fflush(stdin);
    BusquedaPorPalabra(realizadas, cantEncargos, clave);
    BusquedaPorId(realizadas, cantEncargos, idBuscado);
    for (int i = 0; i < cantEncargos; i++)
    {
        free(encargos[i]);
        free(realizadas[i]);
    }
    free(encargos);
    free(realizadas);
    
    return 0;
}

void mostrarTareas(tarea* listaTareas) {
    printf("El id de la tarea es: %d\n", listaTareas->TareaID);
    printf("la descripcion de la tarea es: ");
    puts(listaTareas->Descripcion);
    printf("La duracion de la tarea es: %d\n", listaTareas->Duracion);
}

tarea * BusquedaPorPalabra(tarea ** listaTareas, int cantTareas, char * palabraClave){
    for (int i = 0; i < cantTareas; i++)
    {
        if (listaTareas[i] != NULL)
        {
            if (!strcmp(listaTareas[i]->Descripcion,palabraClave))
            {
                return listaTareas[i];
            }
        }
    }
    printf("No se ha encontrado la tarea ingresada\n");
    return NULL;
}

tarea * BusquedaPorId(tarea ** listaTareas, int cantTareas, int id){
    for (int i = 0; i < cantTareas; i++)
    {
        if (listaTareas[i] != NULL)
        {
            if (listaTareas[i]->TareaID == id)
            {
                return listaTareas[i];
            }
        }
    }
    printf("No se ha encontrado la tarea ingresada\n");
    return NULL;
}