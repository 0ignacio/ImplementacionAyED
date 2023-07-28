#include <stdio.h>
#include <stdlib.h>

typedef int Item;
const Item indef = -99999;

struct Nodo
{
    Item dato;
    struct Nodo * sig;
};

typedef struct
{
    struct Nodo * cabecera;
    int altura;
} Pila;

Pila pilaVacia()
{
    Pila p;
    p.cabecera = NULL;
    p.altura = 0;
    return p;
}

int esPilaVacia(Pila p)
{
    return(p.cabecera == NULL);
}

Pila* PUSH(Pila * p, Item item)
{
    struct Nodo * nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = item;
    nuevo->sig = p->cabecera;
    p->cabecera = nuevo;
    p->altura++;
    return p;
}

struct Nodo* TOP(Pila * p)
{
    if(esPilaVacia(*p))
    { 
        printf("\nLa pila esta vacia\n");
        return NULL;
    }else{
        return(p->cabecera);
    }
}

void POP(Pila * p)
{
    if (esPilaVacia(*p))
    {
        printf("\nLa pila esta vacia\n");
    }else{
        struct Nodo * aux;
        aux = p->cabecera;
        p->cabecera = p->cabecera->sig;
        free(aux);
        p->altura--;
    }
}

int main(){
    Pila *p = (Pila*)malloc(sizeof(Pila));
    struct Nodo * nodoAux;
    int input, aux;
    do
    {
        
        printf("\n---------MENU---------\n");
        printf("1 - Iniciar Pila\n");
        printf("2 - PUSH\n");
        printf("3 - TOP\n");
        printf("4 - POP\n");
        printf("5 - Altura\n");
        printf("----------------------");
        printf("\nIngrese una opcion: ");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            *p = pilaVacia();
            break;
        case 2:
            printf("\nIngrese el elemento que quiere agregar: ");
            scanf("%d", &aux);
            p = PUSH(p, aux);
            break;
        case 3:
            nodoAux = TOP(p);
            if (nodoAux != NULL)
            {
                printf("\nTOP de la pila: %d", nodoAux->dato);
            }
            break;
        case 4:
            POP(p);
            break;
        case 5:
            printf("Altura de la pila: %d", p->altura);
            break;
        
        default:
            break;
        }
    }while (input != 0);
    return 0;
}