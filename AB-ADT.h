#include <stdio.h>
#include <stdlib.h>

typedef char itemAB;

AB ABVacio(){
    return NULL;
}

int esABVacio(AB ab){
    return(ab == NULL);
}

AB armarAB(AB izq, int raiz, AB der){
    struct nodoAB * nuevo = (struct nodoAB*)malloc(sizeof(struct nodoAB));
    nuevo->der = der;
    nuevo->izq = izq;
    nuevo->raiz = raiz;
    return nuevo;
}

AB izquierdo(AB ab){
    if (esABVacio(ab))
    {
        printf("\nEl arbol esta vacio.");
        return NULL;
    }else{
        if (esABVacio(ab->izq))
        {
            printf("\nArbol izq vacio.");
        }else{
            return ab->izq;
        }
    }
}

AB derecho(AB ab){
    if (esABVacio(ab))
    {
        printf("\nEl arbol esta vacio.");
        return NULL;
    }else{
        if (esABVacio(ab->der))
        {
            printf("\nArbol der vacio.");
        }else{
            return ab->der;
        }
    }
}

itemAB raiz(AB ab){
    if (esABVacio(ab))
    {
        printf("\nEl arbol esta vacio.");
        return '\0';
    }else{
        return ab->raiz;
    }
}

int pertenece(AB ab, itemAB x){
    if (esABVacio(ab))
    {
        return 0;
    }else{
        if (ab->raiz == x)
        {
            return 1;
        }else{
            return pertenece(ab->izq, x) || pertenece(ab->der, x);
        }
    }
}

void preOrden(AB ab)
{
    if (esABVacio(ab) == 0)
    {
        printf("%c ", ab->raiz);
        preOrden(ab->izq);
        preOrden(ab->der);
    }
}

void enOrden(AB ab)
{
    if (esABVacio(ab) == 0)
    {
        preOrden(ab->izq);
        printf("%c ", ab->raiz);
        preOrden(ab->der);
    }
}

void postOrden(AB ab)
{
    if (esABVacio(ab) == 0)
    {
        preOrden(ab->izq);
        preOrden(ab->der);
        printf("%c ", ab->raiz);
    }
}