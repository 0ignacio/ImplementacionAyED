#include <stdio.h>
#include <stdlib.h>
#include "PILA-ADT.h"
#include "AB-ADT.h"

int esSigno(char posfija[], int aux){
    return((posfija[aux] == '+') || (posfija[aux] == '-') || (posfija[aux] == '*') || (posfija[aux] == '/'));
}

int main(){
    AB ab = ABVacio(), DER = ABVacio(), IZQ = ABVacio();
    Pila *p = (Pila*)malloc(sizeof(Pila));
    *p = pilaVacia();
    int aux = 0;
    char posfija[50];

    printf("Ingrese una expresion posfija: ");
    gets(posfija);

    while (posfija[aux] != '=')
    {
        if (posfija[aux] != '~')
        {
            if (esSigno(posfija, aux) == 0)
            {
                PUSH(p, armarAB(ABVacio(), posfija[aux], ABVacio()));
            }else{
                DER = TOP(p);
                POP(p);
                IZQ = TOP(p);
                POP(p);
                PUSH(p, armarAB(IZQ, posfija[aux], DER));
            }
        }else{
            IZQ = TOP(p);
            POP(p);
            PUSH(p, armarAB(IZQ, posfija[aux], ABVacio()));
        }
        aux++;
    }
    ab = TOP(p);
    printf("Post: ");
    postOrden(ab);
    printf("\nPre: ");
    preOrden(ab);
    printf("\nEn: ");
    enOrden(ab);
    return 0;
}