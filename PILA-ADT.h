#include <stdio.h>
#include <stdlib.h>

typedef char itemAB;
struct nodoAB{
    itemAB raiz;
    struct nodoAB *izq;
    struct nodoAB *der;
};
typedef struct nodoAB *AB;

typedef AB Item;

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

int altura(Pila *p)
{
    return p->altura;
}