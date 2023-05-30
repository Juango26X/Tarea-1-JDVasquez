#include "biginteger.h"
#include<stdio.h>
#include<string>
int main(){
    string numeros = "211";
    BigInteger l(numeros);
     l.imprimir();
    string numeros2 = "-3450";
    BigInteger l2(numeros2);
    l.add(l2);
    l.imprimir();
    return 0;
}
