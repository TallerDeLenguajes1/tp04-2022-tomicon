#include <stdio.h>
#include <stdlib.h>

struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
} typedef tarea;

int main(){
    tarea **encargos;
    tarea **realizadas;
    int cantEncargos;

    printf("Ingrese la cantidad de tareas que cargara\n");
    scanf("%d",&cantEncargos);
    fflush(stdin);
    encargos= (tarea**)malloc(cantEncargos * sizeof(tarea*));

    for (int i = 0; i < cantEncargos; i++)
    {
        encargos[i]= (tarea *)malloc(sizeof(tarea));
        encargos[i]->Descripcion= (char*)malloc(501);
        printf("Ingrese el id de la tarea");
        scanf("%d",&(encargos[i]->TareaID));
        fflush(stdin);
        printf("Agregue una breve descripcion de la tarea (tiene 500 caracteres)");
        gets(encargos[i]->Descripcion);
        do
        {
            printf("Que duracion tendra la tarea? (recuerde que debe ingresar un valor entre 10 y 100)");
            scanf("%d",&(encargos[i]->Duracion));
            fflush(stdin);
        } while (encargos[i]->Duracion > 100 || encargos[i]->Duracion < 10);
    }
    int confirmar= 0;
    for (int i = 0; i < cantEncargos; i++)
    {
        printf("Si ya se ha realizado la tarea numero %d, ingrese un 1, sino ingrese cualquier otro numero", encargos[i]->TareaID);
        scanf("%d",&confirmar);
        if (confirmar == 1)
        {
            realizadas[i]= encargos[i];
            realizadas= NULL;
            confirmar= 0;
        }
    }
    return 0;
}