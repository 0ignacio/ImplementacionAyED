#include <stdio.h>
#include <stdlib.h>

#define indef = NULL;

typedef char itemAB;
struct nodoAB
{
    itemAB raiz;
    struct nodoAB *izq;
    struct nodoAB *der;
};
typedef struct nodoAB *AB;

AB ABvacio();
AB armarAB(AB I, itemAB r, AB D);
int esABvacio(AB T);
int pertenece(AB T, itemAB x);
AB izq(AB T);
AB der(AB T);
itemAB raiz(AB T);

//FUNCIONES PARA MOSTRAR EL ARBOL (PreOrden - EnOrden - PostOrden)
void preOrden(AB T);
void enOrden(AB T);
void postOrden(AB T);

AB ABvacio()
{
    return NULL;
}

AB armarAB(AB I, itemAB r, AB D)
{
    struct nodoAB * nuevo = (struct nodoAB*)malloc(sizeof(struct nodoAB));
    nuevo->raiz = r;
    nuevo->izq = I;
    nuevo->der = D;
    return nuevo;
}

int esABvacio(AB T)
{
    if (T == NULL)
    {
        return 1;
    }else{
        return 0;
    }
}

int pertenece(AB T, itemAB x)
{
    if (esABvacio(T) == 1)
    {
        return 0;
    }else{
        if ((x == T->raiz) || (pertenece(T->izq, x)) || (pertenece(T->der, x)))
        {
            return 1;
        }
    }
}

AB izq(AB T)
{
    if (esABvacio(T) == 0)
    {
        return T->izq;
    }else{
        return NULL;
    }   
}

AB der(AB T)
{
    if (esABvacio(T) == 0)
    {
        return T->der;
    }else{
        return NULL;
    } 
}

itemAB raiz(AB T)
{
    if (esABvacio(T) == 0)
    {
        return T->raiz;
    }else{
        return "#";
    } 
}

void preOrden(AB T)
{
    if (esABvacio(T) == 0)
    {
        printf("%c ", T->raiz);
        preOrden(T->izq);
        preOrden(T->der);
    }
}

void enOrden(AB T)
{
    if (esABvacio(T) == 0)
    {
        preOrden(T->izq);
        printf("%c ", T->raiz);
        preOrden(T->der);
    }
}

void postOrden(AB T)
{
    if (esABvacio(T) == 0)
    {
        preOrden(T->izq);
        preOrden(T->der);
        printf("%c ", T->raiz);
    }
}