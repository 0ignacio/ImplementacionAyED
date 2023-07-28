#include <stdio.h>
#include <stdlib.h>
#define INDEF -99999;

typedef int ITEM; 
struct Nodo
{
    ITEM item;
    struct Nodo * sig;
};

typedef struct Fila
{
    struct Nodo * frente;
    struct Nodo * final;
    int longitud;
}Fila;

//Punto 4 - Implementacion ADT FILA
Fila filaVacia();
Fila enfila(Fila F, ITEM item);
Fila defila(Fila F);
int esFilaVacia(Fila F);
ITEM frente(Fila F);
int longitud(Fila F);
int pertenece(Fila F, int item);
int igualF(Fila F, Fila G);
Fila invertir(Fila F);
Fila defilaX(Fila F, ITEM item);
Fila enfilaN(Fila F, ITEM item, int cant);
//Punto 2 - Operacion misterio
Fila eliminarRepetidos(Fila F, Fila G);
//Punto 3 - Funcion CONCATN
Fila concatN(Fila* F, Fila G, int cant);
//Punto 5 - Operacion CONCAT
Fila concat(Fila F, Fila G);

void mostraFila(Fila F);

int main()
{
    int aux;
    Fila F = filaVacia();
    Fila G = filaVacia();
    
    F = enfila(F, 3);
    F = enfila(F, 2);
    F = enfila(F, 3);
    F = enfila(F, 6);
    F = enfila(F, 7);
    
    G = enfila(G, 1);
    G = enfila(G, 2);
    G = enfila(G, 3);
    G = enfila(G, 5);
    
    F = concatN(&F, G, 3);
    mostraFila(F);

    return 0;
}

//Punto 4 - Implementacion ADT FILA
Fila filaVacia()
{
    Fila F;
    F.frente = NULL;
    F.final = NULL;
    F.longitud = 0;
    return F;
}

int esFilaVacia(Fila F)
{
    if(F.longitud == 0)
    {
        return 1;
    }else{
        return 0;
    }
}

Fila enfila(Fila F, ITEM item)
{
    struct Nodo* nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->item = item;
    nuevo->sig = NULL;
    if (esFilaVacia(F) == 1)
    {
        F.frente = nuevo;
        F.final = nuevo;
    }else{
        F.final->sig = nuevo;
        F.final = nuevo;
    }
    F.longitud++;
    return F;
}

Fila defila(Fila F)
{
    if(esFilaVacia(F) == 1)
    {
        printf("La fila esta vacia\n");
        return F;
    }else{
        Fila aux = F;
        if (F.longitud == 1)
        {
            F.frente = NULL;
            F.final = NULL;
            F.longitud--;
            free(aux.frente->sig);
            free(aux.final->sig);
        }else{
            F.frente = F.frente->sig;
            F.longitud--;
            free(aux.frente);
        }
    }
    return F;
}

ITEM frente(Fila F)
{
    if(esFilaVacia(F) == 1)
    {
        printf("La fila esta vacia\n");
        return INDEF;
    }else{
        return (F.frente->item);
    }
}

int pertenece(Fila F, ITEM item)
{
    if(F.frente == NULL || esFilaVacia(F) == 1)
    {
        return 0;
    }else{
        if (F.frente->item == item)
        {
            return 1;
        }else{
            F.frente = F.frente->sig;
            return pertenece(F, item);
        }
    }
}

int igualF(Fila F, Fila G)
{
    if(F.frente == NULL && G.frente == NULL)
    {
        return 1;
    }else{
        if ((F.frente == NULL || G.frente == NULL) || (esFilaVacia(F) || esFilaVacia(G)))
        {
            return 0;
        }else{
            if(F.frente->item == G.frente->item)
            {
                F.frente = F.frente->sig;
                G.frente = G.frente->sig;
                return igualF(F, G);
            }else{
                return 0;
            }
        }
    }
}

Fila invertir(Fila F)
{
    if(F.frente == NULL || esFilaVacia(F) == 1)
    {
        return F;
    }else{
        return enfila(invertir(defila(F)), F.frente->item);
    }
}

Fila defilaX(Fila F, ITEM item){                    //REVISAR
    if(F.frente == NULL || esFilaVacia(F) == 1){
        return F;
    }else{
        struct Nodo * aux;
        struct Nodo * ant;
        if(F.frente->item == item)
        {
            aux = F.frente;
            F.frente = F.frente->sig;
            F.longitud--;
            if(F.frente == F.final)
            {
                F.final = F.frente;
            }
            free(aux);
            return defilaX(F, item);
        }else{
            F.frente = F.frente->sig;
            return defilaX(F, item);
        }
    }
}

Fila enfilaN(Fila F, ITEM item, int cant)
{
    if(cant == 0)
    {
        return F;
    }else{
        return enfila(enfilaN(F, item, cant-1), item);
    }
}

//Punto 2 - Operacion misterio
Fila eliminarRepetidos(Fila F, Fila G)
{
    if(F.frente == NULL || esFilaVacia(F) == 1)
    {
        return F;
    }else{
        if(pertenece(G, F.frente->item) == 1)
        {
            struct Nodo * aux = F.frente;
            F.frente = F.frente->sig;
            free(aux);
            eliminarRepetidos(F, G);
        }else{
            F.frente = F.frente->sig;
            if (F.frente == NULL)
            {
                return F;
            }else{
                enfila(eliminarRepetidos(F, G), F.frente->item);
            }
        }
    }
}

//Punto 3 - Funcion CONCATN
Fila concatN(Fila* F, Fila G, int cant)
{
    if (cant == 0 || esFilaVacia(G) == 1)
    {
        return *F;
    }else{
        enfila(*F, frente(G));
        defila(G);
        cant--;
        return concatN(F, G, cant);
    }
}

//Punto 5 - Operacion CONCAT
Fila concat(Fila F, Fila G)
{

}

void mostraFila(Fila F){
    if(esFilaVacia(F) == 1){
        printf("La fila esta vacia");
    }else{
        while(F.frente != NULL)
        {
            printf("item:%d", F.frente->item);
            F.frente = F.frente->sig;
        }
    }
}