#include "bigInteger.h"
#include<stdio.h>
#include<string>
int main(){
    string numeros = "5";
    BigInteger l(numeros);
    //l.imprimir();
    string numeros2 = "-120";
    BigInteger l2(numeros2);
    l.add(l2); 
    l.substract(l2);
    l.imprimir();
    l.product(l2);
    return 0;
}
