#include <stdio.h>
#include <stdlib.h>

typedef int Item;

struct Nodo{
    Item dato;
    struct Nodo * sig;
};

typedef struct Fila{
    struct Nodo * frente; 
    struct Nodo * final;
    int longitud; 
}Fila;

Fila filaVacia(){
    Fila f;
    f.frente = NULL;
    f.final = NULL;
    f.longitud = 0;
    return f;
}

int esFilaVacia(Fila f){
    return(f.longitud == 0);
}

Fila enFila(Fila f, Item x){
    struct Nodo * nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = x;
    nuevo->sig = NULL;
    if (esFilaVacia(f))
    {
        f.frente = nuevo;
        f.final = nuevo;
    }else{
        f.final->sig = nuevo;
        f.final = nuevo;
    }
    f.longitud++;
    return f;
}

struct Nodo * frente(Fila f){
    if (esFilaVacia(f))
    {
        printf("\nLa fila esta vacia");
        return NULL;
    }else{
        return f.frente;
    }
}

void defila(Fila *f){
    if (esFilaVacia(*f))
    {
        printf("\nLa fila esta vacia");
    }else{
        struct Nodo * aux;
        aux = f->frente;
        if (f->longitud == 1)
        {
            f->frente = NULL;
            f->final = NULL;
        }else{
            f->frente = f->frente->sig;
        }
        f->longitud--;
        free(aux);
    }
}

int longitud(Fila f){
    return f.longitud;
}

// int main(){
//     Fila f;
//     struct Nodo * nodoAux;
//     int input, aux;
//     do
//     {
        
//         printf("\n---------MENU---------\n");
//         printf("1 - Iniciar Fila\n");
//         printf("2 - enFila\n");
//         printf("3 - frente\n");
//         printf("4 - defila\n");
//         printf("5 - longitud\n");
//         printf("----------------------");
//         printf("\nIngrese una opcion: ");
//         scanf("%d", &input);

//         switch (input)
//         {
//         case 1:
//             f = filaVacia();
//             break;
//         case 2:
//             printf("\nIngrese el elemento que quiere agregar: ");
//             scanf("%d", &aux);
//             f = enFila(f, aux);
//             break;
//         case 3:
//             nodoAux = frente(f);
//             if (nodoAux != NULL)
//             {
//                 printf("\nFrente de la pila: %d", nodoAux->dato);
//             }
//             break;
//         case 4:
//             defila(&f);
//             break;
//         case 5:
//             printf("Altura de la pila: %d", longitud(f));
//             break;
        
//         default:
//             break;
//         }
//     }while (input != 0);
//     return 0;
// }